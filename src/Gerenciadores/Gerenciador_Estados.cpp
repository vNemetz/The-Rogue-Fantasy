#include "Gerenciadores/Gerenciador_Estados.h"
#include "Estados/Fases/Floresta.h"
#include "Estados/Fases/Castelo.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Estados/Fases/Castelo.h"



namespace ger{
Gerenciador_Estados* Gerenciador_Estados::instancia(nullptr);

Gerenciador_Estados::Gerenciador_Estados():
pEstadoAtual(nullptr)
, mapaEstados()
, multijogador(false)
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
    fases::Floresta* faseFloresta = new fases::Floresta();
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseFloresta) ) );

    //fases::Castelo* faseCastelo = new fases::Castelo();
    //mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseCastelo) ) );

    menus::Menu_Pausa* menuPausa = new menus::Menu_Pausa(ger::Gerenciador_Estados::getInstancia());
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(pausa, static_cast<Estado*>(menuPausa) ) );

}

void Gerenciador_Estados::requererEstado() 
{
    if(pEstadoAtual){
    pEstadoAtual->executar();
    }

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
        case pausa:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[pausa]);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(pausa);
            break;
        default:
            break;
    }
    
}
 void Gerenciador_Estados::setMultijogador(bool multi)
{
    multijogador = multi;
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

void ger::Gerenciador_Estados::proximaFase(int numFase)
{
    if(numFase == 1){
            if(mapaEstados[fase]){
            delete mapaEstados[fase];
            mapaEstados.erase(fase);
        }
        ger::Gerenciador_Colisoes::getInstancia()->limparListas();
        fases::Castelo* faseCastelo = new fases::Castelo();
        pEstadoAtual = faseCastelo;

        mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseCastelo) ) );
        faseCastelo->setPGG(ger::Gerenciador_Grafico::getInstancia());
    }
}

void ger::Gerenciador_Estados::reiniciarJogo()
{
    ger::Gerenciador_Colisoes::getInstancia()->limparListas();
    if(mapaEstados[fase]){
        delete mapaEstados[fase];
        mapaEstados.erase(fase);
    }
    fases::Floresta* faseFloresta = new fases::Floresta();
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseFloresta) ) );
    faseFloresta->setPGG(ger::Gerenciador_Grafico::getInstancia());
    

    // fases::Castelo* faseCastelo = new fases::Castelo();
    // mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseCastelo) ) );
    // faseCastelo->setPGG(ger::Gerenciador_Grafico::getInstancia());
}
