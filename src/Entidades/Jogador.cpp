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
    , animacao(sf::Vector2u(6,1), 0.025f)
    , pulando(false)
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , vivo(true)
    , pontos(0)
    , animacao(sf::Vector2u(6, 1), 0.025f)
    , corpo()
    , pulando(false)
{

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

}
void pers::Jogador::desenhar(){
    if(pSprite){
        std::cout << "IntRect: "
                  << animacao.getCorpo().left << ", "
                  << animacao.getCorpo().top << ", "
                  << animacao.getCorpo().width << ", "
                  << animacao.getCorpo().height << std::endl;
        pGG->desenharEnte(this);
    }
    else{std::cerr << "Sprite vazio\n";}
}

void pers::Jogador::setCorpo(){
    if(pSprite){pSprite->setTextureRect(animacao.getCorpo());}
}

void pers::Jogador::setCorpoAnimacao(){
        if(pTextura){
        animacao.setCorpo(pTextura);
    }
}
void pers::Jogador::atualizaAnimacao(float dt)
{
    animacao.atualizar(/*static_cast<ElementosGraficos::tipoAnimacao> (1),*/ dt);
    setCorpo();
}
}
