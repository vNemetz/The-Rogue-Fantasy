#include "Entidade.h"
//...
ent::Entidade::Entidade(): Ente(){}

ent::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, ID id): Ente(pos, tam, id){}

ent::Entidade::~Entidade(){/*x = 0; y = 0;*/}

void ent::Entidade::salvarDataBuffer()
{
}
