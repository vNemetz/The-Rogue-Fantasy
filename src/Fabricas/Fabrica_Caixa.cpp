#include "Fabricas/Fabrica_Caixa.h"
#include "Entidades/Obstáculos/Caixa.h"

namespace fact {

Fabrica_Caixa::Fabrica_Caixa()
    : Fabrica_Caixa(0.f)
{
}

Fabrica_Caixa::Fabrica_Caixa(float tamanho)
    : Fabrica_Entidades()
    , tamanhoFase(tamanho)
{
}

Fabrica_Caixa::~Fabrica_Caixa()
{
}

ent::Entidade* Fabrica_Caixa::criarEntidade(sf::Vector2f posicao) {
    ent::obs::Caixa* caixa = new ent::obs::Caixa(posicao, sf::Vector2f(5.f, 5.f));
    
    caixa->setTamanhoFase(tamanhoFase);
    return static_cast<ent::Entidade*>(caixa);
}

}