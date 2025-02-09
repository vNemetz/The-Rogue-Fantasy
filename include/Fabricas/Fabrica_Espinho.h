#pragma once

#include "Fabricas/Fabrica_Entidades.h"

namespace fact {

class Fabrica_Espinho : public Fabrica_Entidades {
private:
    float tamanhoFase;

public:
    Fabrica_Espinho();
    Fabrica_Espinho(float tamanho);
    ~Fabrica_Espinho();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;
};

}
