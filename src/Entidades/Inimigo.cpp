#include "Entidades/Inimigo.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace ent {
namespace pers {

Inimigo::Inimigo()
    : Personagem()
    , jogador(nullptr)
    , nivel_maldade(1)
{
}

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, Jogador* jog) 
    : Personagem(pos, tam, inimigo)
    , jogador(jog)
    , nivel_maldade(1)
{
}

Inimigo::~Inimigo() {
}

void Inimigo::movimentoAleatorio() {
    // TODO
}

}
}
