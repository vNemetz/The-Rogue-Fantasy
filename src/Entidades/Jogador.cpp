#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Personagem()
    , vivo(true)
    , pontos(0)
    , corpo()
    , animacao(sf::Vector2u(6,1), 0.03f)
    , pulando(false)
{
    est = parado;
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , vivo(true)
    , pontos(0)
    , animacao(sf::Vector2u(6, 1), 0.03f)
    , corpo()
    , pulando(false)
{
    est = parado;
}

Jogador::~Jogador() {
    vivo = false;
    pontos = 0;
}

void Jogador::executar() {
    atualizarPosicao();
}

void Jogador::alteraVivo() {
    vivo = !vivo;
}

bool Jogador::getVivo() const {
    return vivo;
}

void Jogador::atualizarEstado(bool estado, sf::Keyboard::Key key) {
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

        default:
            break;
    }
}

void Jogador::atualizarPosicao() {
    if (pulando && noChao)
        pular();

    mover();
}

void Jogador::pular() {
    velocidade.y = -600.f;
    noChao = false;
}

void Jogador::setEstado(estado es){
    est = es;
}
}
void pers::Jogador::desenhar(){
    if(pSprite){
        pGG->desenharEnte(this);
    }
    else{std::cerr << "Sprite vazio\n";}
}

void pers::Jogador::setCorpo(){
    setCorpoAnimacao();
    if(pSprite){pSprite->setTextureRect(animacao.getCorpo());}
}

sf::IntRect pers::Jogador::getCorpo(){
    return corpo;
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
        setTextura("/assets/images/Rogue/rogue-idle.png");
        animacao.atualizarSpritesheet(pTextura, sf::Vector2u(1,1), 0.03f);
    }
    setCorpo();
}
}
