#pragma once
#include "Fase.h"

namespace fases{

class Castelo : public Fase{
private:

public:
    Castelo(ger::Gerenciador_Colisoes* pGC);
    ~Castelo();

    virtual void executar();
};
}