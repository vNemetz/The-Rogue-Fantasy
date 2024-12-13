#include "Entidades/Jogador.h"
#include <SFML/Window/Keyboard.hpp>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Personagem()
    , vivo(true)
    , pontos(0)
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , vivo(true)
    , pontos(0)
    , movendoLados(4, false)
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
}
