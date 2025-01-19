#include "Fases/Fase.h"
#include "Entidades/Obstáculos/Plataforma.h"


fases::Fase::Fase(ger::Gerenciador_Colisoes* pGC, int nFase) :  
Ente(fase)
,pColisoes(ger::Gerenciador_Colisoes::getInstancia())
,listaPersonagens()
,listaObstaculos()
,numeroFase(nFase)
, pJog(nullptr)
{
}

fases::Fase::~Fase(){
    pColisoes = nullptr;
    listaObstaculos.limpar();
    listaPersonagens.limpar();
}

void fases::Fase::criarPersonagens(sf::Vector2f posicao, ID id){
    if(id == inimigo){
        /* Criação do Goblin */
        ent::pers::Goblin* goblin = new ent::pers::Goblin(sf::Vector2f(posicao),sf::Vector2f(1.7f, 1.7f), getJogador());
        goblin->setTextura("Goblin-Idle");
        goblin->setVelocidadeMaxima(sf::Vector2f (250.f, 250.f));
            
        listaPersonagens.incluir(static_cast<ent::Entidade*>(goblin));
        pColisoes->incluirInimigo(goblin);
    }
    else if(id == jogador){
        /*Criação do Jogador 1*/
        ent::pers::Jogador* jogador = new ent::pers::Jogador (posicao,sf::Vector2f(1.7f, 1.7f));
        jogador->setTextura("Rogue-Stand");
        jogador->setVelocidadeMaxima(sf::Vector2f(600.f, 600.f));
        pJog = jogador;

        listaPersonagens.incluir(static_cast<ent::Entidade*>(jogador));
        pColisoes->setJogador(jogador);
    }
}

void fases::Fase::criarPlataformas(sf::Vector2f pos, int tipo)
{
    ent::obs::Plataforma* plataforma = new ent::obs::Plataforma(sf::Vector2f(pos), sf::Vector2f(1.7f, 1.7f), false, 50);
    if(tipo == 0){
        plataforma->setTextura("Grass0000");
    }else if(tipo == 1){
        plataforma->setTextura("Grass0001");
    }else if(tipo == 2){
        plataforma->setTextura("Grass0002");
    }
    pColisoes->incluirObstaculo(static_cast<ent::obs::Obstaculo*>(plataforma));
    listaObstaculos.incluir(static_cast<ent::Entidade*>(plataforma));
    pColisoes->incluirObstaculo(plataforma);
}

void fases::Fase::criarObstaculos()
{
}

void fases::Fase::desenharFundo(){
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->draw(spriteFundo);
            ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getVista());
}
void fases::Fase::criarEntidade(char simbolo, const sf::Vector2i pos)
{
    switch(simbolo){
        case ('i'):
            criarPersonagens(sf::Vector2f(pos.x * 54.0f, pos.y * 54.0f), inimigo);
            break;
        case ('j'):
            criarPersonagens(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f), jogador);
            break;
        case('#'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 1);
            break;
        case('/'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 0);
            break;
        case(';'):
            criarPlataformas(sf::Vector2f(pos.x * 54.2f, pos.y * 54.2f), 2);
            break;
        default: 
            break;
    }
}

void fases::Fase::executar()
{
    pColisoes->setJogador(pJog);
    desenharFundo();
    atualizaObstaculos();
    atualizaPersonagens();
    pColisoes->executar();
}

ent::pers::Jogador* fases::Fase::getJogador(){
    return pJog;
}
void fases::Fase::atualizaPersonagens(){
    listaPersonagens.percorrer();
}

void fases::Fase::atualizaObstaculos(){
    listaObstaculos.percorrer();
}
