#pragma once
#include "Ente.h"

namespace ent{
class Entidade : public Ente{
protected:
    int x;
    int y;
    //ostream buffer;
public:
    //Construtora e Destrutora
    Entidade();
    Entidade(ger::Gerenciador_Grafico* pGrafico);
    virtual ~Entidade();

    virtual void executar() = 0;
    virtual void salvar() = 0;
    void salvarDataBuffer();

    //...

};
}