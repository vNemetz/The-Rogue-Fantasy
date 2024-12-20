#include "Entidades/Entidade.h"

namespace ent {

Entidade::Entidade()
    : Ente()
    , velocidade(0.f, 0.f)
    , dt(0.f)
{
}

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Ente(pos, tam, id)
    , velocidade(0.f, 0.f)
    , dt(0.f)
{
}

Entidade::~Entidade()
{
}

sf::Vector2f Entidade::getVelocidade() const {
    return velocidade;
}

void Entidade::setVelocidade(sf::Vector2f vel) {
    velocidade = vel;
}


void ent::Entidade::salvarDataBuffer()
{
}

}
