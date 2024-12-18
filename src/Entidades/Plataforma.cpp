#include "Entidades/Plataforma.h"
#include "Entidades/Jogador.h"
#include "Entidades/Obstaculo.h"

namespace ent {
namespace obs {

Plataforma::Plataforma()
    : Obstaculo()
    , altura(0)
{
}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt)
    : Obstaculo(pos, tam, dan, plataforma)
    , altura(alt)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() {
}

void Plataforma::obstacular(pers::Jogador* p) {
}

}
}

