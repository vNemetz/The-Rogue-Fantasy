#include "Entidades/Projeteis/Projetil.h"

namespace ent {
namespace prj {

Projetil::Projetil()
    : Projetil(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false)
{
}

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f esc, bool aDireita)
    : Entidade(pos, esc, projetil)
    , dano(0)
    , paraDireita(aDireita)
{
}

Projetil::~Projetil()
{
}

void Projetil::setParaDireita(bool paraDireita) {
    this->paraDireita = paraDireita;
}

bool Projetil::getParaDireita() const {
    return paraDireita;
}

}
}
