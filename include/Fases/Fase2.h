#pragma once
#include "Fases/Fase.h"

namespace Fases{

class FaseDois : public Fase{
private:

public:
    FaseDois(ger::Gerenciador_Colisoes gC);
    ~FaseDois();

    virtual void executar();
};
}