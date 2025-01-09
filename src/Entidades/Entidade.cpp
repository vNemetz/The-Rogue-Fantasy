#include "Entidades/Entidade.h"

namespace ent {

Entidade::Entidade()
    : Entidade(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), vazio)
{
}

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Ente(pos, tam, id)
    , velocidade(0.f, 0.f)
    , dt(0.f)
    , noChao(false)
{
}

Entidade::~Entidade()
{
}

sf::Vector2f Entidade::getVelocidade() const {
    return velocidade;
}

void Entidade::setVelocidade(sf::Vector2f velocidade) {
    this->velocidade = velocidade;
}

void Entidade::setVelocidadeVertical(float vy) {
    velocidade.y = vy;
}


void Entidade::salvarDataBuffer()
{
}

bool Entidade::getNoChao() const {
    return noChao;
}

void Entidade::setNoChao(bool noChao) {
    this->noChao = noChao;
}

}
