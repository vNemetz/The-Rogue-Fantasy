#include "Entidades/Entidade.h"

namespace ent {
ent::Entidade::Entidade(): Ente(){}

ent::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id): Ente(pos, tam, id){}

ent::Entidade::~Entidade(){}


void ent::Entidade::salvarDataBuffer()
{
}
}
