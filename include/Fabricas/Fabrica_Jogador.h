#pragma once

#include "Fabricas/Fabrica_Entidades.h"

namespace fact {

class Fabrica_Jogador : public Fabrica_Entidades {
private:
    bool jogador1;
    float tamanhoFase;

public:
    Fabrica_Jogador();
    Fabrica_Jogador(bool jog1, float tamanho);
    ~Fabrica_Jogador();
    
    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;
};

}
