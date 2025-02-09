#include "Entidades/Obstáculos/Espinho.h"

namespace ent {
namespace obs {

Espinho::Espinho()
    : Espinho(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam)
    : Obstaculo(pos, tam, true, espinho)
    , dano(1)
{
    setTextura("Spikes");
}

Espinho::~Espinho()
{
}

void Espinho::executar() {
    aplicarGravidade();

    mover();
}

}
}