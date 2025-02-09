#pragma once

#include "Fabricas/Fabrica_Entidades.h"
#include "Entidades/Personagens/Jogador.h"

namespace fact {

class Fabrica_Cavaleiro : public Fabrica_Entidades {
private:
    ent::pers::Jogador* pJog1;
    ent::pers::Jogador* pJog2;
    bool doisJogadores;
    float tamanhoFase;

public:
    Fabrica_Cavaleiro();
    Fabrica_Cavaleiro(ent::pers::Jogador* jog1, ent::pers::Jogador* jog2, bool doisJog, float tamanho);
    ~Fabrica_Cavaleiro();

    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;


    void setJogador1(ent::pers::Jogador* j1);
    void setJogador2(ent::pers::Jogador* j2);
};

}
