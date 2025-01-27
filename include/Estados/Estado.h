#pragma once

enum tipoEstado{
    fase = 0,
    menu,
    placar,
    salvar
};
namespace ger{
class Gerenciador_Estados;
}

class Estado{
protected:
    ger::Gerenciador_Estados* pGEstados;
    tipoEstado id;
public:
    Estado();
    Estado(tipoEstado tipo, ger::Gerenciador_Estados* pGE = nullptr);
    virtual ~Estado(){}

    void setGerenciadorEstados(ger::Gerenciador_Estados* pGE);
    void alterarEstado(tipoEstado tipo);
    tipoEstado getID() const;
    virtual void executar() = 0;
};
