#pragma once
#include "Fase.h"

namespace fases{

class Floresta :public Fase{
private:
    bool faseFinalizada;
public:
    Floresta();
    ~Floresta();
    virtual void criarFundo();
    virtual void criarMapa();

};
}   