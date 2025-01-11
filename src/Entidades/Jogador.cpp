#include "Entidades/Jogador.h"
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
        pGG->desenharEnte(this);
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

void pers::Jogador::setCorpoAnimacao(){
        if(pTextura){
        animacao.setCorpo(pTextura);
    }
}
void pers::Jogador::atualizaTempoAnimacao(float dt)
{
    animacao.atualizar(dt);
    atualizaElementosAnimacao();
}

void pers::Jogador::atualizaElementosAnimacao(){
    if(est == andando){
        setTextura("/assets/images/Rogue/rogue-walk.png");
        animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6,1), 0.03f);
    }
    else if(est == atacando){
        setTextura("/assets/images/Rogue/rogue-attack.png");
        animacao.atualizarSpritesheet(pTextura, sf::Vector2u(7,1), 0.03f);
    }
    else if(est == pulado){
        setTextura("/assets/images/Rogue/rogue-jump.png");
        animacao.atualizarSpritesheet(pTextura, sf::Vector2u(7,1), 0.06f);
    }
    else if(est == parado){
        setTextura("/assets/images/Rogue/rogue.png");
        animacao.atualizarSpritesheet(pTextura, sf::Vector2u(1,1), 0.03f);
    }
    setCorpo();
}
}
