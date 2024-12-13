#include "Entidades/Inimigo.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace ent {
namespace pers {
Inimigo::Inimigo()
    : Personagem()
    , jogador(nullptr)
    , nivel_maldade(1)
    , raio(800)
{
}

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, Jogador* jog) 
    : Personagem(pos, tam, inimigo)
    , jogador(jog)
    , nivel_maldade(1)
    , raio(800)
{
}

Inimigo::~Inimigo() {
}

void Inimigo::executar() {
    sf::Vector2f posJogador = jogador->getPosition();
    sf::Vector2f posInimigo = getPosition();

    sf::Vector2f dist = posJogador - posInimigo;
    float moduloDist = sqrt(pow((dist.x),2) + pow(dist.y, 2));

    if (moduloDist <= raio)
        persegueJogador(posJogador, posInimigo);
}

void Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
    sf::Vector2f novaPosicao = posInimigo;

    if (posJogador.x > posInimigo.x)
        novaPosicao.x += velocidade.x;

    else
        novaPosicao.x -= velocidade.x;

    if (posJogador.y > posInimigo.y)
        novaPosicao.y += velocidade.y;

    else
        novaPosicao.y -= velocidade.y;

    setPosition(novaPosicao);
}

void Inimigo::movimentoAleatorio() {
}

}
}
