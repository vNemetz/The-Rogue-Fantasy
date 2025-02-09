#include "Entidades/Obstáculos/Obstaculo.h"

namespace ent {
namespace obs {

Obstaculo::Obstaculo()
    : Obstaculo(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), false, vazio)
{
}

Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, bool dan, ID id) 
    : Entidade(pos, tam, id)
    , danoso(dan)
{
}

Obstaculo::~Obstaculo() {
}

void Obstaculo::mover() {
    sf::Vector2f ds = posicao;
    
    dt = pGG->getDeltaTime();

    ds += velocidade * dt;

    setPosition(ds);
}

}
}
