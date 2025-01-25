#include "Estados/Estado.h"
#include "Gerenciadores/Gerenciador_Estados.h"


Estado::Estado(tipoEstado tipo, Gerenciador_Estados *pGE):
id(tipo)
, pGEstados(pGE)
{
}
void Estado::setGerenciadorEstados(Gerenciador_Estados *pGE)
{
    if(pGE){pGEstados = pGE;}
}

void Estado::alterarEstado(tipoEstado tipo)
{
    pGEstados->setEstadoAtual(tipo);
}
