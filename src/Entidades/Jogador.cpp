#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace ent {
namespace pers {
Jogador::Jogador()
    : Personagem()
    , vivo(true)
    , pontos(0)
    , pulando(false)
{
}

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam)
    : Personagem(pos, tam, jogador)
    , vivo(true)
    , pontos(0)
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
}
