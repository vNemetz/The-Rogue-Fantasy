#include "../include/Entidade.h"
//...
ent::Entidade::Entidade(){}

ent::Entidade::Entidade(ger::Gerenciador_Grafico* pGrafico = NULL): Ente(pGrafico), x(rand()%WIDTH), y(rand()%HEIGHT){}

ent::Entidade::~Entidade(){x = 0; y = 0;}

void ent::Entidade::salvarDataBuffer()
{
}
