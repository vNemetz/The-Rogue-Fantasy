#include "Entidades/Goblin.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace pers {

Goblin::Goblin() 
    : Inimigo()
    , raio(800)
{
}

Goblin::Goblin(sf::Vector2f pos, sf::Vector2f tam, Jogador* jog)
    : Inimigo(pos, tam, jog)
    , raio(800)
{
}

Goblin::~Goblin() {

}

void Goblin::executar() {
    sf::Vector2f posJogador = jogador->getPosition();
    sf::Vector2f posInimigo = getPosition();

    sf::Vector2f dist = posJogador - posInimigo;
    float moduloDist = sqrt(pow((dist.x),2) + pow(dist.y, 2));

    sf::Vector2f novaPosicao = posInimigo;

    if (moduloDist <= raio)
        novaPosicao = persegueJogador();

    // se não: Faz um movimento aleatório (TODO)

    mover(novaPosicao);
}

sf::Vector2f Goblin::persegueJogador() {
    sf::Vector2f posJogador = jogador->getPosition();
    sf::Vector2f posInimigo = getPosition();
    
    sf::Vector2f novaPosicao = posInimigo;

    if (posJogador.x > posInimigo.x)
        novaPosicao.x += velocidade.x;

    else
        novaPosicao.x -= velocidade.x;

    if (posJogador.y > posInimigo.y)
        novaPosicao.y += velocidade.y;

    else
        novaPosicao.y -= velocidade.y;

    return novaPosicao;
    //setPosition(novaPosicao);
}

}
}
