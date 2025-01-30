#pragma once
#include "Fase.h"

namespace fases{

class Castelo : public Fase{
private:

public:
    Castelo();
    ~Castelo();

    virtual void executar();
};
}