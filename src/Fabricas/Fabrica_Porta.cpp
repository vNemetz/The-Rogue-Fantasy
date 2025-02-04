#include "Fabricas/Fabrica_Porta.h"
#include "Entidades/Obstáculos/Porta.h"

namespace fact {

Fabrica_Porta::Fabrica_Porta()
    : Fabrica_Porta(0.f)
{
}

Fabrica_Porta::Fabrica_Porta(float tamanho)
    : Fabrica_Entidades()
    , tamanhoFase(tamanho)
{
}

Fabrica_Porta::~Fabrica_Porta()
{
}

ent::Entidade* Fabrica_Porta::criarEntidade(sf::Vector2f posicao) {
    ent::obs::Porta* porta = new ent::obs::Porta(posicao, sf::Vector2f(2.2f, 2.2f));
    
    porta->setTamanhoFase(tamanhoFase);
    return static_cast<ent::Entidade*>(porta);
}

}