#include "Entidades/Personagens/Goblin.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace pers {

Goblin::Goblin()
    : Goblin(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Goblin::Goblin(sf::Vector2f pos, sf::Vector2f tam)
    : Inimigo(pos, tam)
    , raioDetect(600)
    , tempoSemDetectar(0.f)
    , estadoIdle(PARADO)
{
}

Goblin::~Goblin()
{
}

void Goblin::executar() {
    if (jogadores.size() > 0) {
        // Se há jogadores, selecionar o que está mais próximo
        // e então se mover a ele

        float menorDist = INT_MAX;
        int jogadorMaisProximo = 0;

        for (int i = 0; i < jogadores.size(); i++) {
            Jogador* jogador = jogadores[i];
            sf::Vector2f dist = jogador->getPosition() - posicao;
            float moduloDist = sqrt(pow((dist.x),2) + pow(dist.y, 2));

            if (moduloDist < menorDist) {
                jogadorMaisProximo = i;
                menorDist = moduloDist;
            }
        }

        if (menorDist <= raioDetect) {
            persegueJogador(jogadorMaisProximo);

            tempoSemDetectar = 0.f;
            estadoIdle = PARADO;
        }
    }

    else {
        movimentoAleatorio();
    }

    mover();

    atualizarEstado();

    atualizarAnimacao();
}

/* Movimentação */

void Goblin::persegueJogador(int idx) {
    Jogador* jogador = jogadores[idx];

    sf::Vector2f posJogador = jogador->getPosition();
    sf::Vector2f posInimigo = getPosition();

    if (posJogador.x > posInimigo.x) {
        movendoDireita = true;
        movendoEsquerda = false;
    }

    else {
        movendoDireita = false;
        movendoEsquerda = true;
    }
}

void Goblin::movimentoAleatorio() {
    /* Movimento aleatório se não detectar nada */
    tempoSemDetectar += pGG->getDeltaTime();
    
    switch (estadoIdle) {
        case PARADO:
            if (tempoSemDetectar >= 2.5f) {
                /* Decide aleatoriamente o próximo movimento */
                int roll = rand() % 100;
                if (roll % 2 == 0) {
                    estadoIdle = DIREITA;
                }
                
                else {
                    estadoIdle = ESQUERDA;
                }
                tempoSemDetectar = 0.f; // Reseta o temporizador
            }
            movendoDireita = false;
            movendoEsquerda = false;
            break;

        case DIREITA:
            if (tempoSemDetectar >= 1.5f) {
                estadoIdle = PARADO; // Após 1 segundo, volta para o estado parado
                tempoSemDetectar = 0.f; // Reseta o temporizador
            }
            movendoDireita = true;
            movendoEsquerda = false;
            break;

        case ESQUERDA:
            if (tempoSemDetectar >= 1.5f) {
                estadoIdle = PARADO; // Após 1 segundo, volta para o estado parado
                tempoSemDetectar = 0.f; // Reseta o temporizador
            }
            movendoDireita = false;
            movendoEsquerda = true;
            break;
    }
}

void Goblin::emColisaoInimigo(Inimigo* pI, sf::Vector2f ds) {
    sf::Vector2f posicaoInimigo = pI->getPosition();
    sf::Vector2f tamanhoPers = pI->getTamanho();
    sf::Vector2f velocidadeInimigo = pI->getVelocidade();

    if (ds.x != 0.f && ds.y != 0.f) {
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

/* Animação */

void Goblin::atualizarElementosAnimacao() {
    switch (est) {
        case parado:
            setTextura("Goblin-Idle");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(4, 1), 0.20f, ElementosGraficos::parado);
            break;

        case andando:
            setTextura("Goblin-Walk");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6, 1), 0.16f, ElementosGraficos::andando);
            break;

        case sofrendo:
            setTextura("Goblin-Hurt");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(3, 1), 0.13f, ElementosGraficos::sofrendo);
            break;
        
        default:
            break;
    }

    setCorpo();
}

void Goblin::setCorpo() {
    if (pSprite) {
        sf::IntRect frame = animacao.getCorpo();

        frame.top += 32;
        frame.height = 89 - 32;

        if (frame.width > 0) {
            frame.left += 30;
            frame.width = 70;
        }

        else {
            frame.left -= 28;
            frame.width = -70;
        }

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);

        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}

}
}
