#include "Gerenciadores/Gerenciador_Estados.h"
#include "Estados/Estado.h"
Estado::Estado()
{
}   

Estado::Estado(tipoEstado tipo, ger::Gerenciador_Estados *pGE) : 
id(tipo)
, pGEstados(pGE)
{
}
void Estado::setGerenciadorEstados(ger::Gerenciador_Estados *pGE)
{
    if(pGE){pGEstados = pGE;}
}

void Estado::alterarEstado(tipoEstado tipo)
{
    pGEstados->setEstadoAtual(tipo);
}
