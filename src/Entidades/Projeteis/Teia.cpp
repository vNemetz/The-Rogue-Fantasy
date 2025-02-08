#include "Entidades/Projeteis/Teia.h"

namespace ent {
namespace prj {

Teia::Teia()
    : Teia(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false)
{
}

Teia::Teia(sf::Vector2f pos, sf::Vector2f esc, bool aDireita)
    : Projetil(pos, esc, aDireita)
{
    setTextura("Web");
    dano = 1.f;

    velocidadeInicial = sf::Vector2f(700.f, -450.f);
    velocidade = velocidadeInicial;

    velocidadeInicial.y *= -1;

    if (!paraDireita) {
        velocidade.x *= -1;
    }
}

Teia::~Teia()
{
}

void Teia::executar() {
    aplicarGravidade();
    mover();
}

void Teia::mover() {
    sf::Vector2f ds(0.f, 0.f);
    dt = pGG->getDeltaTime();

    ds += velocidade * dt;

    setPosition(ds + posicao);
}

void Teia::setPosicaoInicial(sf::Vector2f posicaoInicial) {
    this->posicaoInicial = posicaoInicial;
}

void Teia::calcularDano() {
    double novoDano = 0.0;

    /* Usa a área varrida em baixo da trajetória da teia para o dano */
    sf::Vector2f posicaoFinal = posicao;

    double deltaX = posicaoFinal.x - posicaoInicial.x;

    /*  Explicação do Dano (Integral - Ensino Superior):
     *  Equação da Trajetória da Teia:
     *  y(x) = y0 + vy(x - x0)/vx - g/2 * ((x - x0)/vx)^2
     *
     *  Podemos integrar y(x) usando apenas técnicas simples como de substituição.
     *  Fazendo isso para o intervalo x0 a xf, obtemos:
     *  I = y0(xf - x0) + vy/(2*vx) * (xf - x0)^2 - g/(6*vx^2) * (xf - x0)^3
     */

    // Calcula a integral (área)
    novoDano += posicaoInicial.y * deltaX;
    novoDano += velocidadeInicial.y * deltaX * deltaX / (2 * velocidadeInicial.x);
    novoDano -= GRAVIDADE * deltaX * deltaX * deltaX  / (6 * velocidadeInicial.x * velocidadeInicial.x);

    // Torna o dano proporcional à área cálculada
    if (novoDano < 0.f) novoDano = -novoDano;

    novoDano /= 1000.f;
    
    if (novoDano > 75.f) novoDano = 4.f;
    else if (novoDano > 50.f) novoDano = 3.f;
    else if (novoDano > 25.f) novoDano = 2.f;
    else novoDano = 1.f;
    
    setDano(novoDano);
}

}
}
