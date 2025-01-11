#pragma once
#include "Fases/Fase.h"

namespace Fase{

class FaseUm: public Fase{
private:

public:
    FaseUm();
    ~FaseUm();
    virtual void executar();
};
}