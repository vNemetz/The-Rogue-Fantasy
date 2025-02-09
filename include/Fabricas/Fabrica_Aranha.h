#pragma once

#include "Fabricas/Fabrica_Entidades.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Jogador.h"

namespace fact {

class Fabrica_Aranha : public Fabrica_Entidades {
private:
    ent::pers::Jogador* pJog1;
    ent::pers::Jogador* pJog2;
    bool doisJogadores;
    float tamanhoFase;
    lis::Lista_Entidades* listaProjeteis;

public:
    Fabrica_Aranha();
    Fabrica_Aranha(ent::pers::Jogador* jog1, ent::pers::Jogador* jog2, bool doisJog, float tamanho, lis::Lista_Entidades* listaProj);
    ~Fabrica_Aranha();
    
    ent::Entidade* criarEntidade(sf::Vector2f posicao) override;

    void setJogador1(ent::pers::Jogador* j1);
    void setJogador2(ent::pers::Jogador* j2);
};

}
