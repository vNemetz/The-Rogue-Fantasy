#include "Gerenciadores/Gerenciador_Estados.h"
#include "Estados/Fases/Floresta.h"
#include "Gerenciadores/Gerenciador_Input.h"



namespace ger{
Gerenciador_Estados* Gerenciador_Estados::instancia(nullptr);

Gerenciador_Estados::Gerenciador_Estados():
pEstadoAtual(nullptr)
, mapaEstados()
{
    mapaEstados.clear();
    menus::Menu_Principal* menuPrincipal = new menus::Menu_Principal(this);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(menu, static_cast<Estado*>(menuPrincipal)));
    pEstadoAtual = mapaEstados[menu];
}

Gerenciador_Estados::~Gerenciador_Estados(){
    pEstadoAtual = nullptr;
    for(auto& par : mapaEstados){ 
        delete par.second;
        par.second = nullptr;
    }
}


Gerenciador_Estados* Gerenciador_Estados::getInstancia(){
    if(instancia == nullptr){
        instancia = new Gerenciador_Estados();
    }
    return instancia;
}

void Gerenciador_Estados::inicializarEstados()
{

    fases::Floresta* faseFloresta = new fases::Floresta(ger::Gerenciador_Colisoes::getInstancia());
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseFloresta) ) );
}

void Gerenciador_Estados::requererEstado() 
{
    pEstadoAtual->executar();
}

void Gerenciador_Estados::setEstadoAtual(tipoEstado tipo){
    switch (tipo){
        case menu:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[menu]);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(menu);
            break;
        case fase:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[fase]);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(fase);
            break;
        default:
            break;
    }
    
}
Estado *Gerenciador_Estados::getEstadoAtual(){
    if(pEstadoAtual){
        return pEstadoAtual;
    }else{return nullptr;}
}
}

Estado *ger::Gerenciador_Estados::getEstado(tipoEstado tipo)
{
        return mapaEstados[tipo];
}
