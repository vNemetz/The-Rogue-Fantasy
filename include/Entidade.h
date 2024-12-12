#pragma once
#include "Ente.h"
#include "Jogo.h"

namespace ent{

class Entidade : public Ente{
protected:
    ElementosGraficos::Animacao animacao;
    //ostream buffer;
public:
    //Construtora e Destrutora
    Entidade();
    Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    virtual ~Entidade();

   // virtual void setAnimacao() = 0;

    //virtual void executar() = 0;
    //virtual void salvar() = 0;
    void salvarDataBuffer();

};
}