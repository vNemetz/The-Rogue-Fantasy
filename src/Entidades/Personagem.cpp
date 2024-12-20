#include "Entidades/Personagem.h"

namespace ent {
namespace pers {

Personagem::Personagem()
    : Entidade()
    , num_vidas(0)
{
}

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : Entidade(pos, tam, id)
    , num_vidas(0)
{
}

Personagem::~Personagem(){
}

void Personagem::mover(sf::Vector2f novaPosicao) {
    pGG->updateDeltaTime();
    dt = pGG->getDeltaTime();

    sf::Vector2f ds(0.f, 0.f);

    setPosition(novaPosicao);
    // IMPLEMENTAR GRAVIDADE
}

}
}
