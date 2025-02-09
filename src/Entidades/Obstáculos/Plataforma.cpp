#include "Entidades/Obstáculos/Plataforma.h"
#include <cmath>


namespace ent {
namespace obs {

Plataforma::Plataforma()
    : Plataforma(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false, 0)
{
}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt)
    : Obstaculo(pos, tam, dan, plataforma)
    , altura(alt)
    , empuxo(GRAVIDADE)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() {
    aplicarGravidade();
    aplicarEmpuxo();

    mover();
}

void Plataforma::aplicarEmpuxo() {
    if (!noChao) {
        velocidade.y -= empuxo * dt;
    }

    else {
        velocidade.y = 0.f;
    }
}

tipoPlataforma Plataforma::getTipoPlataforma() const
{
    return (tipo);
}

void Plataforma::setTipoPlataforma(tipoPlataforma tip) 
{
    tipo = tip;
}
}
}

