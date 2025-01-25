#pragma once

enum tipoEstado{
    fase = 0,
    menuPrincipal,
    menuPausa,
    placar,
    salvar
};

class Gerenciador_Estados;
class Estado{
private:
    Gerenciador_Estados* pGEstados;
    tipoEstado id;
public:
    Estado(tipoEstado tipo, Gerenciador_Estados* pGE = nullptr);
    virtual ~Estado(){}

    void setGerenciadorEstados(Gerenciador_Estados* pGE);
    void alterarEstado(tipoEstado tipo);
    tipoEstado getID() const;
    //virtual void alterarEstado() = 0;
    virtual void executar() = 0;
};
