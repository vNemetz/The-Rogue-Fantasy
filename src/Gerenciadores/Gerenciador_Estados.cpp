#include "Gerenciadores/Gerenciador_Estados.h"

namespace ger{
Gerenciador_Estados::Gerenciador_Estados():
pEstadoAtual(nullptr)
{
}

Gerenciador_Estados::~Gerenciador_Estados(){
    pEstadoAtual = nullptr;
}

Gerenciador_Estados* Gerenciador_Estados::instancia(nullptr);

Gerenciador_Estados* Gerenciador_Estados::getInstancia(){
    if(instancia == nullptr){
        instancia = new Gerenciador_Estados();
    }
    return instancia;
}

void Gerenciador_Estados::requererEstado()
{
    //pEstadoAtual->executar();
}

void Gerenciador_Estados::setEstadoAtual(tipoEstado tEstado){
    if(tEstado == fase){
        
    }
}
Estado *Gerenciador_Estados::getEstadoAtual(){
    if(pEstadoAtual){
        return pEstadoAtual;
    }else{return nullptr;}
}
}