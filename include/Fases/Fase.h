#pragma once
#include "Jogo.h"

namespace Fases{

class Fase{
protected:
    ger::Gerenciador_Colisoes gColisoes;
    int numeroFase;
public:
    Fase(int nFase = 1);
    ~Fase();
    
    virtual void executar() = 0;
    void gerenciarColisoes();

    /*Criação de entidades: */
    void criarInimigosFaceis();
    void criarInimigosMedios();
    void criarPlataformas();
    void criarInimigos();
    void criarObstaculos();
    void criarCenario();

};
}