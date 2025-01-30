#pragma once

#include "Entidades/Entidade.h"

namespace fact {

/* Classe Interface do Factory Method */
class Fabrica_Entidades {
public:
    Fabrica_Entidades();
    virtual ~Fabrica_Entidades();

    virtual ent::Entidade* criarEntidade(sf::Vector2f posicao) = 0;
};

}
