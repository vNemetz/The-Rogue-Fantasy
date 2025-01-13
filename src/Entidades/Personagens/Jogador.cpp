#include "Entidades/Personagens/Jogador.h"
#include <iostream>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Jogador(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , pontos(0)
    , vivo(true)
    , animacao(sf::Vector2u(6, 1), 0.03f)
    , saltando(false)
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

void Jogador::atualizarMovimentacao(bool estado, sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::A:
            movendoEsquerda = estado;
            break;
        
        case sf::Keyboard::D:
            movendoDireita = estado;
            break;

        case sf::Keyboard::W:
            saltando = estado;
            break;

        default:
            break;
    }
}

void Jogador::atualizarPosicao() {
    if (saltando && noChao)
        pular();
    
    mover();
}

void Jogador::pular() {
    velocidade.y = -600.f;
    noChao = false;
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

/* Animação */

void Jogador::atualizarAnimacao() {
    atualizarElementosAnimacao();
    
    animacao.atualizar(pGG->getDeltaTime(), olhandoDireita);
}

void Jogador::atualizarElementosAnimacao() {
    switch (est) {
        case pulando:
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
        
        default:
            break;
    }

    setCorpo();
}

void Jogador::setCorpo() {
    if (pSprite) {
        /* Do corpo inteiro, frame pega apenas a parte em que há textura de fato */
        sf::IntRect frame = animacao.getCorpo();

        if (frame.width > 0) {
            frame.left += 15;
            frame.width = 56;
        }

        else {
            frame.left -= 56;
            frame.width += 66;
        }

        frame.top += 52;
        frame.height -= 52;

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);
        
        if (frame.width <= 0)
            tamanho.x = -tamanho.x;

        /* HITBOX DEBUG */
        /*
        sf::RectangleShape debugShape;
        debugShape.setSize(sf::Vector2f(tamanho.x, tamanho.y));
        debugShape.setPosition(pSprite->getPosition());
        debugShape.setOutlineColor(sf::Color::Red);
        debugShape.setOutlineThickness(1);
        debugShape.setFillColor(sf::Color::Transparent);
        pGG->getJanela()->draw(debugShape);
        */
    }
}

sf::IntRect Jogador::getCorpo() const {
    return corpo;
}

void Jogador::setVivo(bool vivo) {
    this->vivo = vivo;
}

bool Jogador::getVivo() const {
    return vivo;
}

}
}