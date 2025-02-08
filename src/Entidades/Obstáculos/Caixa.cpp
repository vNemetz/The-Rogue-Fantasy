#include "Entidades/Obstáculos/Caixa.h"

namespace ent {
namespace obs {

Caixa::Caixa()
    : Caixa(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam)
    : Obstaculo(pos, tam, false, caixa)
    , movendo(false)
{
    setTextura("Box");
    setFatorDeLentidao(0.5f);
}

Caixa::~Caixa()
{
}

void Caixa::executar() {
    movendo = false;
    aplicarGravidade();

    mover();
}

void Caixa::setFatorDeLentidao(float fatorDeLentidao)
{
    this->fatorDeLentidao = fatorDeLentidao;
}

float Caixa::getFatorDeLentidao() const
{
    return fatorDeLentidao;
}

bool Caixa::getMovendo() const {
    return movendo;
}

void Caixa::setMovendo(bool movendo) {
    this->movendo = movendo;
}

}
}