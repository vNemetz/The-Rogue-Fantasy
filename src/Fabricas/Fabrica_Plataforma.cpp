#include "Fabricas/Fabrica_Plataforma.h"
#include "Entidades/Obstáculos/Plataforma.h"

namespace fact {

Fabrica_Plataforma::Fabrica_Plataforma()
    : Fabrica_Plataforma(0, 0.f)
{
}

Fabrica_Plataforma::Fabrica_Plataforma(int tipo, float tamanho)
    : Fabrica_Entidades()
    , tipoPlataforma(tipo)
    , tamanhoFase(tamanho)
{
}

Fabrica_Plataforma::~Fabrica_Plataforma()
{
}

ent::Entidade* Fabrica_Plataforma::criarEntidade(sf::Vector2f posicao) {
    ent::obs::Plataforma* plataforma = new ent::obs::Plataforma(posicao, sf::Vector2f(1.7f, 1.7f), false, 50);
    plataforma->setTamanhoFase(tamanhoFase);

    // Configurar textura conforme o tipo
    plataforma->setTextura("Grass000" + std::to_string(tipoPlataforma));

    return static_cast<ent::Entidade*>(plataforma);
}

}
