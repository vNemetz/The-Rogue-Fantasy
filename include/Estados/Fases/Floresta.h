#pragma once
#include "Fase.h"

namespace fases{

class Floresta :public Fase{
private:
    bool faseFinalizada;
public:
    Floresta(ger::Gerenciador_Colisoes* pGC);
    ~Floresta();
    virtual void criarFundo();
    virtual void criarMapa();

};
}   