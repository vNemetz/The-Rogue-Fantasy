#include "Entidades/Personagens/Goblin.h"
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

    // TODO Se não: Faz um movimento aleatório

    mover();
}

sf::Vector2f Goblin::persegueJogador() {
    sf::Vector2f posJogador = jogador->getPosition();
    sf::Vector2f posInimigo = getPosition();
    
    sf::Vector2f novaPosicao = posInimigo;

    if (posJogador.x > posInimigo.x) {
        movendoDireita = true;
        movendoEsquerda = false;
    }

    else {
        movendoDireita = false;
        movendoEsquerda = true;
    }

    return novaPosicao;
}

void Goblin::emColisaoInimigo(Inimigo* pI, sf::Vector2f ds) {
    sf::Vector2f posicaoInimigo = pI->getPosition();
    sf::Vector2f tamanhoPers = pI->getTamanho();
    sf::Vector2f velocidadeInimigo = pI->getVelocidade();

    if (ds.x < 0.f && ds.y < 0.f) {
        // Se a colisão é no eixo x
        if (ds.x > ds.y) {
            if (posicaoInimigo.x < posicao.x)
                posicaoInimigo.x += ds.x;

            else
                posicaoInimigo.x -= ds.x;
        }
        
        // Se a colisão é no eixo y
        else {
            if (posicaoInimigo.y < posicao.y) {
                posicaoInimigo.y += ds.y;
            }

            else {
                posicaoInimigo.y -= ds.y;
            }

            velocidadeInimigo.y = 0;
        }
    }

    pI->setPosition(posicaoInimigo);
    pI->setVelocidade(velocidadeInimigo);
}

}
}
