#pragma once
#include "Ente.h"
#include <map>
#include "Estados/Estado.h"
#include "Estados/Menus/Menu_Principal.h"
/*Usando o padrão de projeto "State" da referência bibliográfica "Design Patterns" - Gamma, Helm, Johnson, Vlissides*/

/* Classe abstrata de Estado, que será classe base de Fase, Menu, Placar e Menu de Pausa */


namespace ger{

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

    void inicializarEstados();
    void requererEstado(); /*Executa o estado atual*/
    void setEstadoAtual(tipoEstado tEstado);
    Estado* getEstadoAtual();
    

};
}
