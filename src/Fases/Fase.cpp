#include "Fases/Fase.h"

fases::Fase::Fase(ger::Gerenciador_Colisoes* pGC, int nFase) :  
Ente(fase)
,pColisoes(ger::Gerenciador_Colisoes::getInstancia())
,listaEntidades()
,numeroFase(nFase)
{
}

fases::Fase::~Fase(){

}

void fases::Fase::criarPersonagem(sf::Vector2f posicao){
    
}

void fases::Fase::criarInimigos()
{
}

void fases::Fase::criarPlataformas()
{
}

void fases::Fase::criarObstaculos()
{
}

void fases::Fase::criarEntidade(char l, const sf::Vector2i pos)
{
}

void fases::Fase::executar()
{
}

void fases::Fase::desenhar()
{
}
