#pragma once
#include "Fases/Fase.h"

namespace Fase{

class FaseDois : public Fase{
private:

public:
    FaseDois();
    ~FaseDois();
    
    virtual void executar();
};
}