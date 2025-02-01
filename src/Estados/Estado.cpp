#include "Gerenciadores/Gerenciador_Estados.h"
#include "Estados/Estado.h"


Estado::Estado():
bufferTime(0)
{
}   

Estado::Estado(tipoEstado tipo, ger::Gerenciador_Estados *pGE) : 
id(tipo)
, pGEstados(pGE)
, bufferTime(0)
{
}
void Estado::setGerenciadorEstados(ger::Gerenciador_Estados *pGE)
{
    if(pGE){pGEstados = pGE;}
}

float Estado::getBufferTime() const
{
    return bufferTime;
}
tipoEstado Estado::getID() const
{
    return id;
}

void Estado::setBufferTime(float bt)
{
    bufferTime = bt;
}
