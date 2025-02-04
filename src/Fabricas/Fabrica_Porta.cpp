#include "Fabricas/Fabrica_Porta.h"
#include <iostream>
namespace fact{

Fabrica_Porta::Fabrica_Porta():
    Fabrica_Porta(0.0f)
{
}

Fabrica_Porta::Fabrica_Porta(float tamanho):
    tamanhoFase(tamanho)    
{
}

Fabrica_Porta::~Fabrica_Porta(){
}

ent::Entidade* Fabrica_Porta::criarEntidade(sf::Vector2f posicao){


    ent::obs::Porta* porta = new ent::obs::Porta();
    porta->setTamanhoFase(tamanhoFase);
    porta->setTextura("Static-door");

    return (static_cast<ent::Entidade*>(porta));

}
}