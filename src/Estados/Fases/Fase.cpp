#include "Estados/Fases/Fase.h"
#include "Entidades/Obstáculos/Plataforma.h"


fases::Fase::Fase(ger::Gerenciador_Colisoes* pGC, int nFase) :  
Ente(fase)
,Estado()
,pColisoes(ger::Gerenciador_Colisoes::getInstancia())
,listaPersonagens()
,listaObstaculos()
,numeroFase(nFase)
, pJog(nullptr)
{
    ent::pers::Jogador* jogador = new ent::pers::Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(1.7f, 1.7f));
    jogador->setTextura("Rogue-Stand");
    jogador->setVelocidadeMaxima(sf::Vector2f(600.f, 600.f));
    listaPersonagens.incluir(static_cast<ent::Entidade*>(jogador));
    pColisoes->setJogador(jogador);
    pJog = jogador;
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
        pJog->setPosition(posicao);
    }
}

void fases::Fase::criarPlataformas(sf::Vector2f pos, int tipo)
{
    ent::obs::Plataforma* plataforma = new ent::obs::Plataforma(sf::Vector2f(pos), sf::Vector2f(1.7f, 1.7f), false, 50);

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

/*void fases::Fase::alterarParaMenu(){
    ger::Gerenciador_Estados::getInstancia()->setEstadoAtual(menuPausa);
}*/