#pragma once
#include "Entidade.h"

namespace pers{
class Personagem : public ent::Entidade{
protected:
    int num_vidas;
public:
    Personagem();
    Personagem(ger::Gerenciador_Grafico* pGrafico = NULL);
    ~Personagem();

    virtual void setNum_Vidas() = 0; //Declara o número de vidas inicial
    virtual void operator --() = 0; //Diminui a vida
    virtual void operator ++() = 0; //Incrementa a vida

};   
}