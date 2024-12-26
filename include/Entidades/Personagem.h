#pragma once
#include "Entidades/Entidade.h"

namespace ent {
namespace pers{

enum estado{
    parado = 0,
    andando,
    atacando,
    pulado,
    morrendo
};    

class Personagem : public Entidade {
protected:
    int num_vidas;
    estado est;

    /* Movimentação - Atributos */
    bool movendoEsquerda;
    bool movendoDireita;
    
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    ~Personagem();

    //virtual void setNum_Vidas() = 0; //Declara o número de vidas inicial
    //virtual void operator --() = 0; //Diminui a vida
    //virtual void operator ++() = 0; //Incrementa a vida
    virtual void executar() = 0;

    //Movimento
    virtual void mover();

};
}
}
