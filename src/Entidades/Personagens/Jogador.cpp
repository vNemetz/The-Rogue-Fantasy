#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cmath>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , pontos(0)
    , pulando(false)
{
}

Jogador::~Jogador()
{
}

void Jogador::executar() {
    atualizarPosicao();

    atualizarEstado();
    
    atualizarAnimacao();
}

void Jogador::desenhar() {
    if (pSprite) {
        pGG->desenharEntidade(this);
    }

    else {
        std::cerr << "Sprite do Jogador vazio!\n";
        exit(1);
    }
}

/* Movimentação */

void Jogador::atualizarMovimentacao(bool estado, sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::A:
            movendoEsquerda = estado;
            break;
        
        case sf::Keyboard::D:
            movendoDireita = estado;
            break;

        case sf::Keyboard::W:
            pulando = estado;
            break;

        case sf::Keyboard::LShift:
            correndo = estado;
            break;

        case sf::Keyboard::Space:
            if (estado)
                atacando = estado;
            break;

        default:
            break;
    }
}

void Jogador::atualizarPosicao() {
    if (pulando && noChao && !levandoDano)
        pular();
    
    if (vivo)
        mover();
}

void Jogador::pular() {
    velocidade.y = -600.f;
    noChao = false;
}

void Jogador::emColisaoInimigo(Inimigo* pI, sf::Vector2f ds) {
    if (!levandoDano) {
        bool inimigoADireita = pI->getPosition().x > posicao.x;

        // Se está atacando e acertando,
        // além da colisão ser horizontal, dá dano
        if (atacando && ((olhandoDireita && inimigoADireita) || (!olhandoDireita && !inimigoADireita)) && (ds.x > ds.y)) {
            pI->sofrerDano(static_cast<Personagem*>(this));
        }

        // Se não está atacando ou errando o ataque,
        // e o inimigo não está sofrendo, leva dano
        else if (pI->getEstado() != sofrendo) {
            sofrerDano(static_cast<Personagem*>(pI));
        }
    }
}

/* Animação */

void Jogador::atualizarElementosAnimacao() {
    switch (est) {
        case estado::pulando:
            setTextura("Rogue-Jump");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(7,1), 0.2f, ElementosGraficos::pulando);
            break;
        
        case andando:
            setTextura("Rogue-Walk");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6,1), 0.16f, ElementosGraficos::andando);
            break;
        
        case parado:
            setTextura("Rogue-Stand");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(1, 1), 0.001f, ElementosGraficos::parado);
            break;

        case ausente:
            setTextura("Rogue-Idle");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(17,1), 0.16f, ElementosGraficos::estatico);
            break;

        case sofrendo:
            setTextura("Rogue-Hurt");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(4, 1), 0.15f, ElementosGraficos::sofrendo);
            break;

        case estado::correndo:
            setTextura("Rogue-Run");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(8, 1), 0.1f, ElementosGraficos::correndo);
            break;

        case estado::atacando:
            setTextura("Rogue-Attack");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(7, 1), duracaoAtaque / 7.f, ElementosGraficos::atacando);
            break;

        case estado::morrendo:
            setTextura("Rogue-Death");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(10, 1), 0.15f, ElementosGraficos::morrendo);
            break;
        
        default:
            break;
    }

    setCorpo();
}

void Jogador::setCorpo() {
    if (pSprite) {
        /* Do corpo inteiro, frame pega apenas a parte em que há textura de fato */
        sf::IntRect frame = animacao.getCorpo();

        frame.top += 52;
        frame.height -= 52;
        
        if (frame.width > 0) {
            frame.left += 15;
            frame.width = 56;
        }

        else {
            frame.left -= 56;
            frame.width = -56;
        }

        if (est == estado::atacando) {
            if (frame.width > 0) {
                frame.width += 10;
            }
            else {
                frame.left += 10;
            }
        }

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);
        
        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}

}
}