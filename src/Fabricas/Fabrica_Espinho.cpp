#include "Fabricas/Fabrica_Espinho.h"
#include "Entidades/Obstáculos/Espinho.h"

namespace fact {

Fabrica_Espinho::Fabrica_Espinho()
    : Fabrica_Espinho(0.f)
{
}

Fabrica_Espinho::Fabrica_Espinho(float tamanho)
    : Fabrica_Entidades()
    , tamanhoFase(tamanho)
{
}

Fabrica_Espinho::~Fabrica_Espinho()
{
}

ent::Entidade* Fabrica_Espinho::criarEntidade(sf::Vector2f posicao) {
    ent::obs::Espinho* espinho = new ent::obs::Espinho(posicao, sf::Vector2f(1.4f, 1.4f));
    
    espinho->setTamanhoFase(tamanhoFase);
    return static_cast<ent::Entidade*>(espinho);
}

}