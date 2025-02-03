#pragma once

#include "Fabricas/Fabrica_Entidades.h"
#include "Entidades/Personagens/Jogador.h"

namespace fact {

class Fabrica_Goblin : public Fabrica_Entidades {
private:
    ent::pers::Jogador* pJog1;
    ent::pers::Jogador* pJog2;
    bool doisJogadores;
    float tamanhoFase;

public:
    Fabrica_Goblin();
    Fabrica_Goblin(ent::pers::Jogador* jog1, ent::pers::Jogador* jog2, bool doisJog, float tamanho);
    ~Fabrica_Goblin();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;
};

}
