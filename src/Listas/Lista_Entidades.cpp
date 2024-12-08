#include "Listas/Lista_Entidades.h"

Lista_Entidades::Lista_Entidades() {
}

Lista_Entidades::~Lista_Entidades() {
}

void Lista_Entidades::incluir(ent::Entidade* pE) {
    LEs.incluir(pE);
}
