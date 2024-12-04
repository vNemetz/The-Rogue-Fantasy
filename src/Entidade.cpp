#include "Entidade.h"
//...

ent::Entidade::Entidade(): x(rand()%WIDTH), y(rand()%HEIGHT){}

ent::Entidade::~Entidade(){x = 0; y = 0;}

void ent::Entidade::salvarDataBuffer()
{
}
