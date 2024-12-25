#include "Entidades/Personagem.h"

namespace ent {
namespace pers {

Personagem::Personagem()
    : Entidade()
    , num_vidas(0)
    , movendoEsquerda(false)
    , movendoDireita(false)
{
}

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Entidade(pos, tam, id)
    , num_vidas(0)
    , movendoEsquerda(false)
    , movendoDireita(false)
{
}

Personagem::~Personagem(){
}

void Personagem::mover() {
    sf::Vector2f novaPosicao = posicao;

    dt = pGG->getDeltaTime();

    if (movendoDireita) {
        novaPosicao.x += velocidade.x * dt;
    }

    if (movendoEsquerda) {
        novaPosicao.x -= velocidade.x * dt;
    }

    const float GRAVIDADE_REAL = 9.8f; // m/s^2
    const float ESCALA_GRAVIDADE_PIXEL = 100.f; // pixels/m
    const float GRAVIDADE = GRAVIDADE_REAL * ESCALA_GRAVIDADE_PIXEL; // pixels/s^2

    velocidade.y += GRAVIDADE * dt;
    novaPosicao.y += velocidade.y * dt;

    if (noChao) {
        velocidade.y = 0;
    }

    setPosition(novaPosicao);
}

}
}
