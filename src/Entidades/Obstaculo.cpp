#include "Entidades/Obstaculo.h"

namespace ent {
namespace obs {

Obstaculo::Obstaculo() 
    : Entidade()
    , danoso(false)
{
}

Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, bool dan, ID id) 
    : Entidade(pos, tam, id)
    , danoso(dan)
{
}

Obstaculo::~Obstaculo() {
}

}
}