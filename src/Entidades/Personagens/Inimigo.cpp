#include "Entidades/Personagens/Inimigo.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace ent {
namespace pers {

Inimigo::Inimigo()
    : Inimigo(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam) 
    : Personagem(pos, tam, inimigo)
    , nivel_maldade(1)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::incluirJogador(Jogador* jogador) {
    jogadores.push_back(jogador);
}

}
}
