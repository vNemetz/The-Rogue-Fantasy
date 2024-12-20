#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>
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

bool Jogador::getVivo() const {
    return vivo;
}

void Jogador::atualizarEstado(bool estado, sf::Keyboard::Key key) {
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
    sf::Vector2f novaPosicao = getPosition();

    if (movendoLados[0])
        novaPosicao.x -= velocidade.x;
    
    if (movendoLados[1])
        novaPosicao.x += velocidade.x;
    
    if (movendoLados[2])
        novaPosicao.y -= velocidade.y;
    
    if (movendoLados[3])
        novaPosicao.y += velocidade.y;

    mover(novaPosicao);
}
}
}
