#pragma once

enum tipoEstado{
    fase = 0,
    menu,
    pausa,
    placar,
    salvar,
    config
};
namespace ger{
class Gerenciador_Estados;
}

class Estado{
protected:
    ger::Gerenciador_Estados* pGEstados;
    tipoEstado id;
    
   float bufferTime; // Para 1 click das setinhas não valerem por 2 alterações de botão (tempo entre "apertos" do botão)
public:
    Estado();
    Estado(tipoEstado tipo, ger::Gerenciador_Estados* pGE = nullptr);
    virtual ~Estado(){}

    void setGerenciadorEstados(ger::Gerenciador_Estados* pGE);
    float getBufferTime() const;
    //void executarEstado() = 0;
    tipoEstado getID() const;
    void setBufferTime(float bt);
    virtual void executar() = 0;
};
