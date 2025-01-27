#include "Entidades/Personagens/Aranha.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace ent {
namespace pers {

Aranha::Aranha()
    : Aranha(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Aranha::Aranha(sf::Vector2f pos, sf::Vector2f tam)
    : Inimigo(pos, tam)
    , raioAtaque(800.f)
{
    raioDetect = 1000.f;
    duracaoAtaque = 1.5f;
}


Aranha::~Aranha()
{
}

void Aranha::executar() {
    if (jogadores.size() > 0) {
        // Se há jogadores, selecionar o que está mais próximo
        // e então se mover a ele
        Jogador* jogadorMenosDistante = jogadorMaisProximo();
        float distancia = distanciaJogador(jogadorMenosDistante);
        
        if (distancia <= raioAtaque) {
            atacar(jogadorMenosDistante);
        }

        else if (distancia <= raioDetect) {
            persegueJogador(jogadorMenosDistante);
        }

        else {
            movendoEsquerda = false;
            movendoDireita = false;
        }
    }

    mover();

    atualizarEstado();

    atualizarAnimacao();
}

void Aranha::atacar(Jogador* jogador) {
    movendoEsquerda = false;
    movendoDireita = false;

    if (jogador->getPosition().x > posicao.x)
        olhandoDireita = true;

    else
        olhandoDireita = false;

    atacando = true;
    // Lança o projétil
}

void Aranha::atualizarElementosAnimacao() {
    switch (est) {
        case parado:
            setTextura("Spider-Idle");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(4, 1), 0.20f, ElementosGraficos::parado);
            break;

        case andando:
            setTextura("Spider-Walk");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6, 1), 0.16f, ElementosGraficos::andando);
            break;

        case sofrendo:
            setTextura("Spider-Hurt");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(3, 1), 0.13f, ElementosGraficos::sofrendo);
            break;

        case estado::atacando:
            setTextura("Spider-Attack");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(3, 1), duracaoAtaque / 7.f, ElementosGraficos::atacando);
            break;
        
        default:
            break;
    }

    setCorpo();
}

void Aranha::setCorpo() {
    if (pSprite) {
        sf::IntRect frame = animacao.getCorpo();

        frame.top += 40;
        frame.height = 90 - 40 - 5;

        if (frame.width > 0) {
            frame.left += 30;
            frame.width = 75;
        }

        else {
            frame.left -= 23;
            frame.width = -75;
        }

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);

        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}

}
}