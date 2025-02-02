#include "Entidades/Obstáculos/Caixa.h"


ent::obs::Caixa::Caixa():
    Obstaculo()
{

}

ent::obs::Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam, ID id):
    Obstaculo(pos, tam, false, obstaculo)
{

}

ent::obs::Caixa::~Caixa()
{

}

void ent::obs::Caixa::setFatorDeLentidao(float lentidao)
{
    fatorDeLentidao = lentidao;
}

float ent::obs::Caixa::getFatorDeLentidao() const
{
    return fatorDeLentidao;
}

void ent::obs::Caixa::executar(){

}
