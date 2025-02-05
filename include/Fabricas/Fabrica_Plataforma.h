#pragma once

#include "Fabricas/Fabrica_Entidades.h"

namespace fact {

class Fabrica_Plataforma : public Fabrica_Entidades {
private:
    int tipoPlataforma;
    int numeroFase;
    float tamanhoFase;

public:
    Fabrica_Plataforma();
    Fabrica_Plataforma(int nFase, int tipo, float tamanho);
    ~Fabrica_Plataforma();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;
};

}
