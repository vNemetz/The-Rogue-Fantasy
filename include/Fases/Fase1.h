#pragma once
#include "Fases/Fase.h"

namespace Fases{

class FaseUm: public Fase{
private:

public:
    FaseUm(ger::Gerenciador_Colisoes gC);
    ~FaseUm();
    virtual void executar();
};
}