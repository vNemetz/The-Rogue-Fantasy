#include "Estados/Fases/Fase.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Fabricas/Fabrica_Goblin.h"
#include "Fabricas/Fabrica_Plataforma.h"
#include "Fabricas/Fabrica_Aranha.h"
#include "Fabricas/Fabrica_Cavaleiro.h"
#include "Fabricas/Fabrica_Jogador.h"
#include "Entidades/Personagens/Inimigo.h"

fases::Fase::Fase() : 
    Ente()
    , Estado(fase)
{
}

fases::Fase::Fase(int nFase)
    : Ente()
    , Estado(fase)
    , numeroFase(nFase)
    , tamanhoFase(0.f)
    , pColisoes(ger::Gerenciador_Colisoes::getInstancia())
    , pEstados(ger::Gerenciador_Estados::getInstancia())
    , pJog1(nullptr)
    , pJog2(nullptr)
{
    pColisoes->setListaProjeteis(&listaProjeteis);
    pColisoes->setListaInimigos(&listaInimigos);
    pColisoes->setListaJogadores(&listaJogadores);

    if (numeroFase == 0)
        tamanhoFase = 5290.f;

    /* Criação Inicial dos Jogadores e suas Fábricas */
    registrarFabrica('j', new fact::Fabrica_Jogador(true, tamanhoFase));
    if (doisJogadores) registrarFabrica('k', new fact::Fabrica_Jogador(false, tamanhoFase));

    criarEntidade('j', sf::Vector2i(0, 0));

    /* Criação do restante das Fábricas (Factory Method Design Pattern) */
    registrarFabrica('g', new fact::Fabrica_Goblin(pJog1, pJog2, doisJogadores, tamanhoFase));
    registrarFabrica('a', new fact::Fabrica_Aranha(pJog1, pJog2, doisJogadores, tamanhoFase, &listaProjeteis));
    registrarFabrica('c', new fact::Fabrica_Cavaleiro(pJog1, pJog2, doisJogadores, tamanhoFase));
    registrarFabrica('/', new fact::Fabrica_Plataforma(0, tamanhoFase));
    registrarFabrica('#', new fact::Fabrica_Plataforma(1, tamanhoFase));
    registrarFabrica(';', new fact::Fabrica_Plataforma(2, tamanhoFase));
    registrarFabrica('|', new fact::Fabrica_Plataforma(3, tamanhoFase));
    registrarFabrica('@', new fact::Fabrica_Plataforma(4, tamanhoFase));
    registrarFabrica('.', new fact::Fabrica_Plataforma(5, tamanhoFase));
    
}

fases::Fase::~Fase() {
    // Deleta as fábricas
    for (auto& par : fabricas) {
        delete par.second;
    }
    fabricas.clear();

    pColisoes = nullptr;
    listaObstaculos.limpar();
    listaPersonagens.limpar();
    listaProjeteis.limpar();
}

/* Atributos Estáticos */
bool fases::Fase::doisJogadores(true);

/* Criação de Entidades */
void fases::Fase::registrarFabrica(char simbolo, fact::Fabrica_Entidades* fabrica) {
    fabricas[simbolo] = fabrica;
}

void fases::Fase::criarEntidade(char simbolo, const sf::Vector2i pos) {
    auto it = fabricas.find(simbolo);

    if (it != fabricas.end()) {
        sf::Vector2f posicao(pos.x * 54.0f, pos.y * 54.0f);
        ent::Entidade* entidade = it->second->criarEntidade(posicao);
        
        // Adicionar às listas e colisões conforme o tipo
        if (dynamic_cast<ent::pers::Inimigo*>(entidade)) {
            listaInimigos.incluir(entidade);
        }
        
        else if (dynamic_cast<ent::obs::Obstaculo*>(entidade)) {
            listaObstaculos.incluir(entidade);
            pColisoes->incluirObstaculo(static_cast<ent::obs::Obstaculo*>(entidade));
        }

        else if (dynamic_cast<ent::pers::Jogador*>(entidade)) {
            // Se o(s) jogador(es) ainda não foi definido, cria.
            // Se já foi, apenas atualize sua posição.
            if (!pJog1) {
                listaJogadores.incluir(entidade);
                ent::pers::Jogador* jogador = static_cast<ent::pers::Jogador*>(entidade);

                ger::Gerenciador_Eventos::getInstancia()->setJogador(jogador);
                ger::Gerenciador_Input::getInstancia()->setJogador(jogador);
                pJog1 = jogador;

                if (doisJogadores) {
                    auto it2 = fabricas.find('k');
                    sf::Vector2f posicao2(posicao.x + 200.f, posicao.y);
                    
                    ent::Entidade* entidade2 = it2->second->criarEntidade(posicao2);
                    listaJogadores.incluir(entidade2);
                    ent::pers::Jogador* jogador2 = static_cast<ent::pers::Jogador*>(entidade2);

                    ger::Gerenciador_Input::getInstancia()->setJogador2(jogador2);
                    pJog2 = jogador2;
                }
            }

            else {
                pJog1->setPosition(posicao);

                if (doisJogadores && pJog2)
                    pJog2->setPosition(sf::Vector2f(posicao.x + 200.f, posicao.y));
            }
        }
    }
}

/* Execução da Fase */
void fases::Fase::executar() {
    desenharFundo();

    atualizarProjeteis();
    atualizarObstaculos();
    atualizarPersonagens();

    pColisoes->executar();
}

void fases::Fase::desenharFundo() {
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getJanela()->getDefaultView());
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->draw(spriteFundo);
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getVista());
    
    if (!pJog1->getParaDeletar())
        ger::Gerenciador_Grafico::getInstancia()->centralizarVista(pJog1, tamanhoFase);
    
    else if (pJog2 && !pJog2->getParaDeletar())
        ger::Gerenciador_Grafico::getInstancia()->centralizarVista(pJog2, tamanhoFase);
}


void fases::Fase::atualizarPersonagens(){
    listaInimigos.percorrer();
    listaJogadores.percorrer();
}

void fases::Fase::atualizarObstaculos(){
    listaObstaculos.percorrer();
}

void fases::Fase::atualizarProjeteis() {
    listaProjeteis.percorrer();
}

ent::pers::Jogador* fases::Fase::getJogador1() const {
    return pJog1;
}

ent::pers::Jogador* fases::Fase::getJogador2() const {
    return pJog2;
}


float fases::Fase::getTamanhoFase() const {
    return tamanhoFase;
}

float fases::Fase::getNumeroFase() const {
    return numeroFase;
}

void fases::Fase::executarEstado(tipoEstado tipo){
    switch (tipo){
        case pausa:
            pEstados->setEstadoAtual(pausa);
            break;

        default:
            break;
    }
}
