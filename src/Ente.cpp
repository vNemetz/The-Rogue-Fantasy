#include "Ente.h"

Ente::Ente()
    : Ente(vazio)
{
}

Ente::Ente(ID id)
    : id(id)
{
}

Ente::~Ente() {
    pGG = nullptr;
}

ger::Gerenciador_Grafico* Ente::pGG(nullptr);

void Ente::setID(ID id) {
    this->id = id;
}

ID Ente::getID() const {
    return id;
}

void Ente::setPGG(ger::Gerenciador_Grafico* pGrafico) {
    pGG = pGrafico;
}
