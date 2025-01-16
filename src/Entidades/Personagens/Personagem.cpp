#include "Entidades/Personagens/Personagem.h"

namespace ent {
namespace pers {

Personagem::Personagem()
    : Personagem(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), ID::vazio)
{
}

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Entidade(pos, tam, id)
    , est(parado)
    , numVidas(3)
    , tempoParado(0.f)
    , tempoDano(0.f)
    , movendoEsquerda(false)
    , movendoDireita(false)
    , olhandoDireita(true)
    , correndo(false)
    , levandoDano(false)
{
}

Personagem::~Personagem(){
}

/* Movimentação */

void Personagem::mover() {
    sf::Vector2f ds(0.f, 0.f); // Guarda a variação de movimento atual
    dt = pGG->getDeltaTime(); // Guarda os segundos passados em dt

    /* Atualiza o movimento horizontal */
    if (levandoDano) {
        if (noChao)
            levandoDano = false;
    }

    else if (movendoDireita && !movendoEsquerda) {
        if (correndo)
            velocidade.x = velocidadeMaxima.x * 1.4f;
        
        else
            velocidade.x = velocidadeMaxima.x;
    }

    else if (movendoEsquerda && !movendoDireita) {
        if (correndo)
            velocidade.x = -velocidadeMaxima.x * 1.4f;
        
        else
            velocidade.x = -velocidadeMaxima.x;
    }

    else {
        velocidade.x = 0.f;
    }

    /* Atualiza o movimento vertical (aplica gravidade) */
    if (!noChao) {
        velocidade.y += GRAVIDADE * dt;
    }

    else {
        velocidade.y = 0.f;
    }

    ds += velocidade * dt;
    
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
    estado estadoAntigo = est;

    if (levandoDano) {
        est = sofrendo;

        tempoParado = 0.f;
        tempoDano += pGG->getDeltaTime();

        /* Se acabar o tempo de invulnerabilidade */
        if (tempoDano >= duracaoInvulneravel) {
            levandoDano = false;
            tempoDano = 0.f;
        }
    }

    else if (!noChao && velocidade.y != 0.f) {
        est = pulando;

        tempoParado = 0.f;
    }

    else if ((movendoDireita && !movendoEsquerda) || (movendoEsquerda && !movendoDireita)) {
        est = andando;

        if (correndo)
            est = estado::correndo;

        tempoParado = 0.f;
    }

    else {
        est = parado;

        tempoParado += pGG->getDeltaTime();

        /* Se o personagem ficar parado por mais disto, está ausente */
        if (tempoParado >= duracaoAusente) {
            est = ausente;
            estadoAntigo = ausente;
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
