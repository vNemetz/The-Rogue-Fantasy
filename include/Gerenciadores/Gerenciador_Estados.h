#pragma once
#include "Ente.h"
#include <map>
/*Usando o padrão de projeto "State" da referência bibliográfica "Design Patterns" - Gamma, Helm, Johnson, Vlissides*/

/* Classe abstrata de Estado, que será classe base de Fase, Menu, Placar e Menu de Pausa */
class Estado{
private:
    /* Tal qual a referência, a classe não possui atributo. */
public:
    Estado(){}
    virtual ~Estado(){}

    //virtual void alterarEstado() = 0;
    //virtual void executar() = 0;
};



namespace ger{

enum tipoEstado{
    fase = 0,
    menuPrincipal,
    menuPausa,
    placar,
    salvar
};

/* Classe "Context"  */
class Gerenciador_Estados{
private:
    Estado* pEstadoAtual;
    std::map<tipoEstado, Estado*> mapaEstados;

    /* Singleton - Padrão de Projeto */
    static ger::Gerenciador_Estados* instancia;

private:
    Gerenciador_Estados();
public:    
    static Gerenciador_Estados* getInstancia();
    ~Gerenciador_Estados();

    void requererEstado(); /*Executa o estado atual*/
    void setEstadoAtual(tipoEstado tEstado);
    Estado* getEstadoAtual();
    

};
}
