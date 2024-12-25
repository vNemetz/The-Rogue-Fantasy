#include "Entidades/Jogador.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Personagem()
    , vivo(true)
    , pontos(0)
    , corpo()
    , animacao(sf::Vector2u(6,1), 0.16f)
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , vivo(true)
    , pontos(0)
    , movendoLados(4, false)
    , animacao(sf::Vector2u(6, 1), 0.16f)
    , corpo()
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

bool Jogador::getVivo() {
    return vivo;
}

void Jogador::mover(bool estado, sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::A:
            movendoLados[0] = estado;
            break;
        
        case sf::Keyboard::D:
            movendoLados[1] = estado;
            break;

        case sf::Keyboard::W:
            movendoLados[2] = estado;
            break;

        case sf::Keyboard::S:
            movendoLados[3] = estado;
            break;

        default:
            break;
    }
}

void Jogador::atualizarPosicao() {
    if (movendoLados[0])
        setPosition (sf::Vector2f(getPosition().x -velocidade.x, getPosition().y));
    
    if (movendoLados[1])
        setPosition (sf::Vector2f(getPosition().x + velocidade.x, getPosition().y));
    
    if (movendoLados[2])
        setPosition (sf::Vector2f(getPosition().x, getPosition().y - velocidade.y));
    
    if (movendoLados[3])
        setPosition (sf::Vector2f(getPosition().x, getPosition().y + velocidade.y));
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
