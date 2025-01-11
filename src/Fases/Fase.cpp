#include "Fases/Fase.h"

Fases::Fase::Fase(ger::Gerenciador_Colisoes gC, int nFase) : gColisoes(gC)
{
    numeroFase = nFase;
}

Fases::Fase::~Fase(){

}

/*Criação de Entidades*/
void Fases::Fase::criarInimigosFaceis(){

}

void Fases::Fase::criarInimigosMedios(){

}

void Fases::Fase::criarPlataformas(){

}

void Fases::Fase::criarInimigos(){

}

void Fases::Fase::criarObstaculos(){

}

void Fases::Fase::criarCenario(){

}
