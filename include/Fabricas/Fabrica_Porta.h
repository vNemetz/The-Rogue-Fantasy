#pragma once
#include "Fabricas/Fabrica_Entidades.h"
#include "Entidades/Obstáculos/Porta.h"

namespace fact{

class  Fabrica_Porta : public Fabrica_Entidades{
private:
    float tamanhoFase;
public:
    Fabrica_Porta();
    Fabrica_Porta(float tamanho);
    ~Fabrica_Porta();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;

};

}
