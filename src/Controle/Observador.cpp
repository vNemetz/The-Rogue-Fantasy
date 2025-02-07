#include "Controle/Observador.h"
#include "Gerenciadores/Gerenciador_Input.h"



namespace controle{
Observador::Observador():
    Observador(controleMenuPrincipal, nullptr)
{
}

Observador::Observador(formaControle tipo, ger::Gerenciador_Input* pGI):
    ativo(false)
    , pGInput(pGI)
    , mapaTeclas()
    , tipoControle(tipo)
{
    mapaTeclas.clear();
}

Observador::~Observador(){
    mapaTeclas.clear();
}
formaControle Observador::getTipoControle()
{
    return (this->tipoControle);
}
void Observador::incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla)

{
    mapaTeclas[tecla] = funcaoTecla;
}

void Observador::setAtivo(bool at)
{
    ativo = at;
}
}