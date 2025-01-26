#include "Estados/Fases/Fase.h"
#include "Entidades/Obstáculos/Plataforma.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Personagens/Goblin.h"
#include "Entidades/Obstáculos/Plataforma.h"

fases::Fase::Fase() : Fase(nullptr, 0)
{
}

fases::Fase::Fase(ger::Gerenciador_Colisoes* pGC, int nFase)
    : Ente(fase)
    , Estado()
    , pColisoes(ger::Gerenciador_Colisoes::getInstancia())
    , listaPersonagens()
    , listaObstaculos()
    , numeroFase(nFase)
    , pJog1(nullptr)
    , pJog2(nullptr)
    , tamanhoFase(0.f)
{
    ent::pers::Jogador* jogador1 = new ent::pers::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(1.7f, 1.7f), true);
    jogador1->setTextura("Rogue-Stand");
    jogador1->setVelocidadeMaxima(sf::Vector2f(600.f, 600.f));
    listaPersonagens.incluir(static_cast<ent::Entidade*>(jogador1));
    pColisoes->incluirJogador(jogador1);
    ger::Gerenciador_Eventos::getInstancia()->setJogador(jogador1);
    ger::Gerenciador_Input::getInstancia()->setJogador(jogador1);
    pJog1 = jogador1;
    

    if (doisJogadores) {
        ent::pers::Jogador* jogador2 = new ent::pers::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(1.7f, 1.7f), false);
        jogador2->setTextura("Rogue-Stand");
        jogador2->setVelocidadeMaxima(sf::Vector2f(600.f, 600.f));
        listaPersonagens.incluir(static_cast<ent::Entidade*>(jogador2));
        pColisoes->incluirJogador(jogador2);
        ger::Gerenciador_Input::getInstancia()->setJogador2(jogador2);
        pJog2 = jogador2;
    }
}

bool fases::Fase::doisJogadores(true);

fases::Fase::~Fase() {
    pColisoes = nullptr;
    listaObstaculos.limpar();
    listaPersonagens.limpar();
}

void fases::Fase::criarPersonagens(sf::Vector2f posicao, ID id) {
    if (id == inimigo) {
        /* Criação do Goblin */
        ent::pers::Goblin* goblin = new ent::pers::Goblin(sf::Vector2f(posicao),sf::Vector2f(1.7f, 1.7f));
        goblin->setTextura("Goblin-Idle");
        goblin->setVelocidadeMaxima(sf::Vector2f (250.f, 250.f));
        goblin->setTamanhoFase(tamanhoFase);
        goblin->incluirJogador(getJogador1());
        
        if (doisJogadores)
            goblin->incluirJogador(getJogador2());
            
        listaPersonagens.incluir(static_cast<ent::Entidade*>(goblin));
        pColisoes->incluirInimigo(goblin);
    }

    else if (id == jogador) {
        pJog1->setPosition(posicao);
        pJog1->setTamanhoFase(tamanhoFase);

        if (doisJogadores) {
            pJog2->setPosition(posicao + sf::Vector2f(200.f, 0.f));
            pJog2->setTamanhoFase(tamanhoFase);
        }
    }
}

void fases::Fase::criarPlataformas(sf::Vector2f pos, int tipo) {
    ent::obs::Plataforma* plataforma = new ent::obs::Plataforma(sf::Vector2f(pos), sf::Vector2f(1.7f, 1.7f), false, 50);
    plataforma->setTamanhoFase(tamanhoFase);

    switch (tipo) {
        case (0):
            plataforma->setTextura("Grass0000");
            break;
        
        case (1):
            plataforma->setTextura("Grass0001");
            break;
        
        case (2):
            plataforma->setTextura("Grass0002");
            break;
        
        case (3):
            plataforma->setTextura("Grass0003");
            break;

        case (4):
            plataforma->setTextura("Grass0004");
            break;

        case (5):
            plataforma->setTextura("Grass0005");
            break;

        default:
            break;
    }

    pColisoes->incluirObstaculo(static_cast<ent::obs::Obstaculo*>(plataforma));
    listaObstaculos.incluir(static_cast<ent::Entidade*>(plataforma));
}

void fases::Fase::criarObstaculos() {
}

void fases::Fase::desenharFundo() {
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getJanela()->getDefaultView());
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->draw(spriteFundo);
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getVista());
}

void fases::Fase::criarEntidade(char simbolo, const sf::Vector2i pos) {
    switch(simbolo) {
        case ('g'):
            criarPersonagens(sf::Vector2f(pos.x * 54.0f, pos.y * 54.0f), inimigo);
            break;

        case ('j'):
            criarPersonagens(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f), jogador);
            break;

        case ('#'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 1);
            break;

        case ('/'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 0);
            break;

        case (';'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 2);
            break;

        case ('@'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 4);
            break;
        
        case ('|'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 3);
            break;

        case ('.'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 5);
            break;

        default: 
            break;
    }
}

void fases::Fase::executar() {
    desenharFundo();
    atualizaObstaculos();
    atualizaPersonagens();
    pColisoes->executar();
}

ent::pers::Jogador* fases::Fase::getJogador1(){
    return pJog1;
}

ent::pers::Jogador* fases::Fase::getJogador2(){
    return pJog2;
}

void fases::Fase::atualizaPersonagens(){
    listaPersonagens.percorrer();
}

void fases::Fase::atualizaObstaculos(){
    listaObstaculos.percorrer();
}

float fases::Fase::getTamanhoFase() {
    return tamanhoFase;
}

/*void fases::Fase::alterarParaMenu(){
    ger::Gerenciador_Estados::getInstancia()->setEstadoAtual(menuPausa);
}*/