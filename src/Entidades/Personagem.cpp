#include "Entidades/Personagem.h"

namespace ent {
namespace pers {

Personagem::Personagem()
    : Personagem(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), ID::vazio)
{
}

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Entidade(pos, tam, id)
    , num_vidas(0)
    , est(parado)
    , movendoEsquerda(false)
    , movendoDireita(false)
    , olhandoDireita(true)
    , tempoParado(0.f)
{
}

Personagem::~Personagem(){
}

/* Movimentação */

void Personagem::mover() {
    sf::Vector2f ds(0.f, 0.f);

    dt = pGG->getDeltaTime(); // Guarda os segundos passados em dt

    /* Atualiza o movimento horizontal */
    if (movendoDireita) {
        ds.x += velocidade.x * dt;
    }

    if (movendoEsquerda) {
        ds.x -= velocidade.x * dt;
    }

    /* Aplica a gravidade quando o personagem está no ar */
    const float GRAVIDADE_REAL = 9.8f; // m/s^2
    const float ESCALA_GRAVIDADE_PIXEL = 100.f; // pixels/m
    const float GRAVIDADE = GRAVIDADE_REAL * ESCALA_GRAVIDADE_PIXEL; // pixels/s^2

    if (!noChao) {
        velocidade.y += GRAVIDADE * dt;
    }

    else {
        velocidade.y = 0.f;
    }

    ds.y += velocidade.y * dt;
    
    /* Define para que lado está olhando */
    if (ds.x > 0.f) {
        olhandoDireita = true;
    }

    else if (ds.x < 0.f) {
        olhandoDireita = false;
    }

    /* Atualiza a posição do sprite */
    setPosition((ds + posicao));
}

/* Estado */

void Personagem::atualizarEstado() {
    if (!noChao && velocidade.y != 0.f) {
        est = pulando;

        tempoParado = 0.f;
    }

    else if ((movendoDireita && !movendoEsquerda) || (movendoEsquerda && !movendoDireita)) {
        est = andando;

        tempoParado = 0.f;
    }

    else {
        est = parado;

        tempoParado += pGG->getDeltaTime();

        /* Se o personagem ficar parado por mais de 4 segundos, está ausente */
        if (tempoParado >= 1.8) {
            est = ausente;
        }
    }    
}

void Personagem::setEstado(estado est) {
    this->est = est;
}

estado Personagem::getEstado() const {
    return est;
}

}
}
