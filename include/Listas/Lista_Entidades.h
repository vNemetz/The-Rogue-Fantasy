#pragma once
#include "Jogo.h"
#include "Lista.h"

namespace ent {class Entidade;}

class Lista_Entidades {
private:
    Lista<ent::Entidade> LEs;

public:
    Lista_Entidades();
    ~Lista_Entidades();

    void incluir(ent::Entidade* pE);
    // TODO : void percorrer();
    //...
};
