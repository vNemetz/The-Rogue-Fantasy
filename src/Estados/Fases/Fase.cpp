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
#include "Fabricas/Fabrica_Porta.h"
#include "Fabricas/Fabrica_Caixa.h"
#include "Fabricas/Fabrica_Espinho.h"
#include "Entidades/Projeteis/Teia.h"
#include <fstream>





fases::Fase::Fase() : 
    Ente()
    , Estado(fase)
{
}

fases::Fase::Fase(int nFase, bool carreg)
    : Ente()
    , Estado(fase)
    , numeroFase(nFase)
    , tamanhoFase(0.f)
    , pColisoes(ger::Gerenciador_Colisoes::getInstancia())
    , pEstados(ger::Gerenciador_Estados::getInstancia())
    , pJog1(nullptr)
    , pJog2(nullptr)
    , pontos(0)
    , carregada(carreg)
{
    if (numeroFase == 0)
        tamanhoFase = 8000.f;
    else if(numeroFase == 1)
        tamanhoFase = 5290.0f;

    ent::obs::Porta::setAberta(false);

    /* Criação Inicial dos Jogadores e suas Fábricas */
    registrarFabrica('j', new fact::Fabrica_Jogador(true, tamanhoFase));
    if (doisJogadores) registrarFabrica('k', new fact::Fabrica_Jogador(false, tamanhoFase));

    if(!carregada){
        criarEntidade('j', sf::Vector2i(0, 0));
    }
    /* Criação do restante das Fábricas (Factory Method Design Pattern) */
    registrarFabrica('g', new fact::Fabrica_Goblin(pJog1, pJog2, doisJogadores, tamanhoFase));
    registrarFabrica('a', new fact::Fabrica_Aranha(pJog1, pJog2, doisJogadores, tamanhoFase, &listaProjeteis));
    registrarFabrica('c', new fact::Fabrica_Cavaleiro(pJog1, pJog2, doisJogadores, tamanhoFase));
    registrarFabrica('d', new fact::Fabrica_Porta(tamanhoFase));
    registrarFabrica('b', new fact::Fabrica_Caixa(tamanhoFase));
    registrarFabrica('e', new fact::Fabrica_Espinho(tamanhoFase));
    registrarFabrica('/', new fact::Fabrica_Plataforma(numeroFase, 0, tamanhoFase));
    registrarFabrica('#', new fact::Fabrica_Plataforma(numeroFase, 1, tamanhoFase));
    registrarFabrica(';', new fact::Fabrica_Plataforma(numeroFase, 2, tamanhoFase));
    registrarFabrica('|', new fact::Fabrica_Plataforma(numeroFase, 3, tamanhoFase));
    registrarFabrica('@', new fact::Fabrica_Plataforma(numeroFase, 4, tamanhoFase));
    registrarFabrica('.', new fact::Fabrica_Plataforma(numeroFase, 5, tamanhoFase));
    registrarFabrica('*', new fact::Fabrica_Plataforma(numeroFase, 500, tamanhoFase));
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

ent::Entidade* fases::Fase::criarEntidade(char simbolo, const sf::Vector2i pos) {

    auto it = fabricas.find(simbolo);

    if (it != fabricas.end()) {
        sf::Vector2f posicao(pos.x * 54.0f, pos.y * 54.0f);
        ent::Entidade* entidade = it->second->criarEntidade(posicao);
        
        // Adicionar às listas e colisões conforme o tipo
        if (dynamic_cast<ent::pers::Inimigo*>(entidade)) {
            listaInimigos.incluir(entidade);
            pColisoes->incluirEntidade(entidade);
        }
        
        else if (dynamic_cast<ent::obs::Obstaculo*>(entidade)) {
            listaObstaculos.incluir(entidade);
            pColisoes->incluirEntidade(entidade);
        }

        else if (dynamic_cast<ent::pers::Jogador*>(entidade)) {
            // Se o(s) jogador(es) ainda não foi definido, cria.
            // Se já foi, apenas atualize sua posição.
            if (!pJog1) {
                listaJogadores.incluir(entidade);
                ent::pers::Jogador* jogador = static_cast<ent::pers::Jogador*>(entidade);
                
                pColisoes->incluirEntidade(entidade);
                ger::Gerenciador_Eventos::getInstancia()->setJogador(jogador);
                ger::Gerenciador_Input::getInstancia()->setJogador(jogador);
                pJog1 = jogador;

                if (doisJogadores) {
                    auto it2 = fabricas.find('k');
                    sf::Vector2f posicao2(posicao.x + 200.f, posicao.y);
                    
                    ent::Entidade* entidade2 = it2->second->criarEntidade(posicao2);
                    listaJogadores.incluir(entidade2);
                    pColisoes->incluirEntidade(entidade2);
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
        return entidade;
    }
    return nullptr;
}

/* Execução da Fase */
void fases::Fase::executar() {
    if(checaFimJogo() == false){
        desenharFundo();
        atualizarObstaculos();
        atualizarProjeteis();
        atualizarPersonagens();
        pColisoes->executar();
        checaObjetivo();
        if(doisJogadores){
            if(pJog1->getPontos() + pJog2->getPontos() > pontos){
                pontos = pJog1->getPontos() + pJog2->getPontos();
            }
        }
        else{
            if(pJog1->getPontos() > pontos){
                pontos = pJog1->getPontos();

            }
        }
    }    
    else{executarEstado(fim);}
    if(numeroFase = 1 && listaInimigos.getTamanho() <= 0){
        executarEstado(fim);
    }
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

    if (listaInimigos.getTamanho() <= 0) {
        ent::obs::Porta::setAberta(true);
    }

    listaJogadores.percorrer();
}

void fases::Fase::atualizarObstaculos(){
    listaObstaculos.percorrer();
}

void fases::Fase::atualizarProjeteis() {
    listaProjeteis.percorrer();
}

ent::pers::Jogador* fases::Fase::getJogador1() const {
    if(pJog1)
        return pJog1;
    return nullptr;
}

ent::pers::Jogador* fases::Fase::getJogador2() const {
    if(pJog2)
        return pJog2;
    return nullptr;
}


float fases::Fase::getTamanhoFase() const {
    return tamanhoFase;
}

int fases::Fase::getPontuacao()
{
    return pontos;
}

void fases::Fase::setPontuacao(int pontos)
{
    this->pontos = pontos;
}

bool fases::Fase::checaFimJogo()
{
    if(listaJogadores.getTamanho() == 0){
        return true;
    }
    return false;
}


void fases::Fase::executarEstado(tipoEstado tipo){

    switch (tipo){
        case pausa:
            pEstados->setEstadoAtual(pausa);
            break;
        case fim:
            pEstados->setEstadoAtual(fim);
            break;
        default:
            break;
    }
}


void fases::Fase::setMultijogador(bool multi)
{
    doisJogadores = multi;
}

void fases::Fase::salvarJogo(std::string caminho){
    json j;

    j["JOGO"] = tipoEstado::fase;
    j["numeroFase"] = numeroFase;
    if(doisJogadores)
        j["doisJogadores"] = doisJogadores;
    
    /*Salvar Jogadores*/
    if(pJog1){
        j["Jogador1"]["posicao"]["x"] = pJog1->getPosition().x;
        j["Jogador1"]["posicao"]["y"] = pJog1->getPosition().y;
        j["Jogador1"]["ehJogador1"] = pJog1->getEhJogador1();
        j["Jogador1"]["vidas"] = pJog1->getNumVidas();
        j["Jogador1"]["pontos"] = pJog1->getPontos();
        j["Jogador1"]["pulando"] = pJog1->getPulando();
        j["Jogador1"]["estado"] = pJog1->getEstado();
    }

    if(doisJogadores){
        if(pJog2){
            j["Jogador2"]["posicao"]["x"] = pJog2->getPosition().x;
            j["Jogador2"]["posicao"]["y"] = pJog2->getPosition().y;
            j["Jogador2"]["ehJogador1"] = pJog2->getEhJogador1();
            j["Jogador2"]["vidas"] = pJog2->getNumVidas();
            j["Jogador2"]["pontos"] = pJog2->getPontos();
            j["Jogador2"]["pulando"] = pJog2->getPulando();
            j["Jogador2"]["estado"] = pJog2->getEstado();
        }
    }

    /*Salvar obstáculos*/
    for(auto it = listaObstaculos.begin(); it != listaObstaculos.end(); ++it){
        if((*it)){
            auto obstaculo = (*it);

            json obs;

            obs["tipo"] = obstaculo->getID();
            obs["posicao"]["x"] = obstaculo->getPosition().x;
            obs["posicao"]["y"] = obstaculo->getPosition().y;
            if(obstaculo->getID() == ID::plataforma){
                obs["tipoPlataforma"] = dynamic_cast<ent::obs::Plataforma*>(obstaculo)->getTipoPlataforma();
            }
            j["obstaculos"].push_back(obs);
        }
    }

    /*Salvar inimigos*/
    for(auto it = listaInimigos.begin(); it != listaInimigos.end(); ++it){
        if(*it){
            ent::pers::Inimigo* inimigo = dynamic_cast<ent::pers::Inimigo*>(*it);

            json inim;

            inim["tipo"] = inimigo->getTipoInimigo();
            inim["posicao"]["x"] = inimigo->getPosition().x;
            inim["posicao"]["y"] = inimigo->getPosition().y;
            inim["vidas"] = inimigo->getNumVidas();
            inim["estado"] = inimigo->getEstado();

            j["inimigos"].push_back(inim);
        }
    }

    /*Salvar Projéteis*/
    for(auto it = listaProjeteis.begin(); it != listaProjeteis.end(); ++it){
        if(*it){
            ent::prj::Projetil* projetil = dynamic_cast<ent::prj::Projetil*>(*it);

            json pjt;

            pjt["posicao"]["x"] = projetil->getPosition().x;
            pjt["posicao"]["y"] = projetil->getPosition().y;
            pjt["aDireita"] = projetil->getParaDireita();

            j["projeteis"].push_back(pjt);
        }
    }

    //Abrir arquivo .json para escrita

    std::ofstream arquivo(caminho, std::ofstream::trunc);
    if (!arquivo.is_open()) {
        std::cerr << "ERRO ao salvar jogo\n";
    }
    arquivo << j.dump(4);   //"4" é a indentação do arquivo (4 espaços)
    arquivo.close();

}

void fases::Fase::carregarJogo(std::string caminho){
    std::ifstream arquivo(caminho);
    listaInimigos.limpar();
    listaJogadores.limpar();
    listaObstaculos.limpar();
    listaProjeteis.limpar();

    std::cout <<"Entrou em carregar jogo\n";
    if(!arquivo.is_open()){
        std::cerr<< "ERRO ao carregar jogo\n";
        return;
    }

    json j;

    try{
        arquivo >> j;
    }
    catch (const std::exception& e){
        std::cerr << "Erro ao processar JSON: " << e.what() <<"\n";
        return;
    }        
    if(j.contains("Jogador1")){
        pJog1  = dynamic_cast<ent::pers::Jogador*>(criarEntidade('j', sf::Vector2i(0,0)));
        if(pJog1){
            pJog1->setPosition(sf::Vector2f(j["Jogador1"]["posicao"]["x"], j["Jogador1"]["posicao"]["y"]));
            pJog1->setEhJogador1(j["Jogador1"]["ehJogador1"]);
            pJog1->setNumVidas(j["Jogador1"]["vidas"]);
            pJog1->setPontos(j["Jogador1"]["pontos"]);
            pJog1->setPulando(j["Jogador1"]["pulando"]);
            pJog1->setEstado(j["Jogador1"]["estado"]);


            static_cast<fact::Fabrica_Goblin*>(fabricas['g'])->setJogador1(pJog1);
            static_cast<fact::Fabrica_Aranha*>(fabricas['a'])->setJogador1(pJog1);
            //listaJogadores.incluir(static_cast<ent::Entidade*>(pJog1));
        }
    }

    if(j["doisJogadores"] == true){ 
        this->doisJogadores = true;
        if(j.contains("Jogador2")){
            pJog2  = dynamic_cast<ent::pers::Jogador*>(criarEntidade('k', sf::Vector2i(0, 0)));
            if(pJog2){
                pJog2->setPosition(sf::Vector2f(j["Jogador2"]["posicao"]["x"], j["Jogador2"]["posicao"]["y"]));
                pJog2->setEhJogador1(j["Jogador2"]["ehJogador1"]);
                pJog2->setNumVidas(j["Jogador2"]["vidas"]);
                pJog2->setPontos(j["Jogador2"]["pontos"]);
                pJog2->setPulando(j["Jogador2"]["pulando"]);
                pJog2->setEstado(j["Jogador2"]["estado"]);
                static_cast<fact::Fabrica_Goblin*>(fabricas['g'])->setJogador2(pJog2);
            static_cast<fact::Fabrica_Aranha*>(fabricas['a'])->setJogador2(pJog2);
                //listaJogadores.incluir(static_cast<ent::Entidade*>(pJog2));
            }
        }
    }

    if(j.contains("obstaculos")){
        for(const auto& dadoObstaculo : j["obstaculos"]){
            ID id = dadoObstaculo["tipo"];

            if(id == ID::plataforma){
                ent::obs::tipoPlataforma tipo= dadoObstaculo["tipoPlataforma"];
                ent::obs::Plataforma* pPlataforma = nullptr;
                if(numeroFase == 0){
                    if(tipo == ent::obs::tipoPlataforma::topoGrama){
                        pPlataforma= dynamic_cast<ent::obs::Plataforma*>(criarEntidade(('#'), sf::Vector2i(0, 0)));
                    }
                    else if(tipo == ent::obs::tipoPlataforma::meioGrama){
                        pPlataforma= dynamic_cast<ent::obs::Plataforma*>(criarEntidade(('@'), sf::Vector2i(0, 0)));
                    }
                }
                if(numeroFase == 1){
                if(tipo == ent::obs::tipoPlataforma::topoTijolo){
                    pPlataforma= dynamic_cast<ent::obs::Plataforma*>(criarEntidade(('@'), sf::Vector2i(0, 0)));
                }
                else if(tipo == ent::obs::tipoPlataforma::meioTijolo){
                    pPlataforma= dynamic_cast<ent::obs::Plataforma*>(criarEntidade(('@'), sf::Vector2i(0, 0)));
                }
                }
                if(pPlataforma)
                pPlataforma->setPosition(sf::Vector2f(dadoObstaculo["posicao"]["x"], dadoObstaculo["posicao"]["y"]));
                    //listaObstaculos.incluir(static_cast<ent::Entidade*>(plataforma));
            }
        }
    }

    if(j.contains("inimigos")){
        for(const auto& dadoInimigo : j["inimigos"]){
            ent::pers::tipoInimigo tipo = dadoInimigo["tipo"];

            if(tipo == ent::pers::tipoInimigo::goblin){
                ent::pers::Inimigo* goblin = dynamic_cast<ent::pers::Inimigo*>(criarEntidade(('g'), sf::Vector2i(0, 0)));
                if(goblin){
                    goblin->setPosition(sf::Vector2f(dadoInimigo["posicao"]["x"], dadoInimigo["posicao"]["y"]));
                    goblin->setNumVidas(dadoInimigo["vidas"]);
                    goblin->setEstado(dadoInimigo["estado"]);
                }
            }
            else if(tipo == ent::pers::tipoInimigo::aranha){
                ent::pers::Inimigo* aranha = dynamic_cast<ent::pers::Inimigo*>(criarEntidade(('a'), sf::Vector2i(0, 0)));
                if(aranha){
                    aranha->setPosition(sf::Vector2f(dadoInimigo["posicao"]["x"], dadoInimigo["posicao"]["y"]));
                    aranha->setNumVidas(dadoInimigo["vidas"]);
                    aranha->setEstado(dadoInimigo["estado"]);
                }
            }
            else if(tipo == ent::pers::tipoInimigo::cavaleiro){
                ent::pers::Inimigo* cavaleiro = dynamic_cast<ent::pers::Inimigo*>(criarEntidade(('c'), sf::Vector2i(0, 0)));
                if(cavaleiro){
                    cavaleiro->setPosition(sf::Vector2f(dadoInimigo["posicao"]["x"], dadoInimigo["posicao"]["y"]));
                    cavaleiro->setNumVidas(dadoInimigo["vidas"]);
                    cavaleiro->setEstado(dadoInimigo["estado"]);
                }
            }
        }
    }

    if(j.contains("projeteis")){
        for(const auto& dadoProjetil : j["projeteis"]){
            if(dadoProjetil.is_null()){
                continue;
            }

            ent::prj::Teia* teia = new ent::prj::Teia(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1.7f, 1.7f), false);
            teia->setPosition(sf::Vector2f(dadoProjetil["posicao"]["x"], dadoProjetil["posicao"]["y"]));
            teia->setParaDireita(dadoProjetil["aDireita"]);

            listaProjeteis.incluir(static_cast<ent::Entidade*>(teia));
        }
    }
}
