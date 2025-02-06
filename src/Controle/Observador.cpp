#include "Controle/Observador.h"

#include "Gerenciadores/Gerenciador_Input.h"


namespace controle{
Observador::Observador():
    Observador(nullptr)
{
}

Observador::Observador(ger::Gerenciador_Input* pGI):
    pGInput(pGI)
    , mapaTeclas()
{
    mapaTeclas.clear();
}

Observador::~Observador(){
    mapaTeclas.clear();
}

void Observador::incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla)
{
    mapaTeclas[tecla] = funcaoTecla;
}



}