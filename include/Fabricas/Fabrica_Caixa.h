#pragma once

#include "Fabricas/Fabrica_Entidades.h"

namespace fact {

class Fabrica_Caixa : public Fabrica_Entidades {
private:
    float tamanhoFase;

public:
    Fabrica_Caixa();
    Fabrica_Caixa(float tamanho);
    ~Fabrica_Caixa();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;
};

}
