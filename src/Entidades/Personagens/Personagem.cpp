#include "Entidades/Personagens/Personagem.h"

namespace ent {
namespace pers {

Personagem::Personagem()
    : Personagem(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), ID::vazio)
{
}

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Entidade(pos, tam, id)
    , vivo(true)
    , numVidas(3)
    , est(parado)
    , tempoParado(0.f)
    , tempoDano(0.f)
    , tempoAtaque(0.f)
    , tempoMorrendo(0.f)
    , movendoEsquerda(false)
    , movendoDireita(false)
    , olhandoDireita(true)
    , correndo(false)
    , levandoDano(false)
    , atacando(false)
    , podeAtacar(true)
    , animacao()
{
}

Personagem::~Personagem()
{
}

/* Movimentação */

void Personagem::mover() {
    sf::Vector2f ds(0.f, 0.f); // Guarda a variação de movimento atual
    dt = pGG->getDeltaTime(); // Guarda os segundos passados em dt

    /* Atualiza o movimento horizontal */
    if (numVidas <= 0) {
        if (noChao) {
            paraDeletar = true;
        }
    }

    else if (levandoDano) {
        if (noChao)
            levandoDano = false;
    }

    else if (movendoDireita && !movendoEsquerda) {
        if (correndo && noChao)
            velocidade.x = velocidadeMaxima.x * 1.4f;

        else if (correndo && !noChao && velocidade.x != 0.f)
            velocidade.x = velocidade.x;
        
        else
            velocidade.x = velocidadeMaxima.x;
    }

    else if (movendoEsquerda && !movendoDireita) {
        if (correndo && noChao)
            velocidade.x = -velocidadeMaxima.x * 1.4f;

        else if (correndo && !noChao && velocidade.x != 0.f)
            velocidade.x = velocidade.x;
        
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

    if (est == sofrendo || est == morrendo)
        olhandoDireita = !olhandoDireita; // Se está levando dano, é ao contrário

    /* Atualiza a posição do sprite */
    setPosition((ds + posicao));
}

void Personagem::sofrerDano(Entidade* atacante) {
    if (!levandoDano) {
        levandoDano = true;
        tempoDano = 0.f;
        numVidas--;

        /* Knockback */
        setPosition(posicao + sf::Vector2f(0.f, -15.f));
        noChao = false;
        velocidade = sf::Vector2f(knockbackHorizontal, -knockbackVertical);

        if (atacante->getPosition().x > posicao.x) {
            velocidade.x *= -1; // Direção do Knockback vai depender da visão do atacante
        }
    }
}

bool Personagem::getOlhandoDireita() const {
    return olhandoDireita;
}

/* Estado */

void Personagem::atualizarEstado() {
    estado estadoAntigo = est;

    if (numVidas <= 0) {
        est = estado::morrendo;

        tempoMorrendo += pGG->getDeltaTime();

        if (tempoMorrendo >= duracaoMorrendo) {
            paraDeletar = true;
        }
    }
    
    else if (levandoDano) {
        est = sofrendo;

        tempoDano += pGG->getDeltaTime();

        /* Se acabar o tempo de invulnerabilidade */
        if (tempoDano >= duracaoInvulneravel) {
            levandoDano = false;
            tempoDano = 0.f;
        }
    }

    else if (atacando) {
        est = estado::atacando;
        podeAtacar = false;

        tempoAtaque += pGG->getDeltaTime();
        if (tempoAtaque >= duracaoAtaque) {
            tempoAtaque = 0.f;
            atacando = false;
            podeAtacar = true;
        }
    }

    else if (!noChao && velocidade.y != 0.f) {
        est = pulando;
    }

    else if ((movendoDireita && !movendoEsquerda) || (movendoEsquerda && !movendoDireita)) {
        est = andando;

        if (correndo && noChao) {
            est = estado::correndo;
        }
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

    /* Reinicia o tempo */
    if (est != estado::atacando) {
        tempoAtaque = 0.f;
        atacando = false;
    }

    if (est != estado::parado && est != estado::ausente) {
        tempoParado = 0.f;
    }
    
    if (est != estado::morrendo) {
        tempoMorrendo = 0.f;
    }
}

void Personagem::setEstado(estado est) {
    this->est = est;
}

estado Personagem::getEstado() const {
    return est;
}

void Personagem::setVivo(bool vivo) {
    this->vivo = vivo;
}

bool Personagem::getVivo() const {
    return vivo;
}

void Personagem::setNumVidas(int numVidas) {
    this->numVidas = numVidas;
}

int Personagem::getNumVidas() const {
    return numVidas;
}

/* Animação */

void Personagem::atualizarAnimacao() {
    atualizarElementosAnimacao();

    animacao.atualizar(pGG->getDeltaTime(), olhandoDireita);
}

}
}
