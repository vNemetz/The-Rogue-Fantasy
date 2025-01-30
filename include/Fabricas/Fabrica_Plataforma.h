#pragma once

#include "Fabricas/Fabrica_Entidades.h"

namespace fact {

class Fabrica_Plataforma : public Fabrica_Entidades {
private:
    int tipoPlataforma;
    float tamanhoFase;

public:
    Fabrica_Plataforma();
    Fabrica_Plataforma(int tipo, float tamanho);
    ~Fabrica_Plataforma();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;
};

}
