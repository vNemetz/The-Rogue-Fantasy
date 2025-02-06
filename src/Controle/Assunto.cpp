#include "Controle/Assunto.h"

namespace controle{
Assunto::Assunto():
    listaObservadores()
{
    listaObservadores.clear();
    it = listaObservadores.begin();
}

Assunto::~Assunto(){
    for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        if(*it){
            delete (*it);
            (*it) = nullptr;
        }
    }
    listaObservadores.clear();
}


void Assunto::teclaApertada(sf::Keyboard::Key tecla)
{
    for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        if(*it){
            (*it)->notificarApertada(tecla);
        }
    }
}

void Assunto::teclaSoltada(sf::Keyboard::Key tecla)
{
    for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        if(*it){
            (*it)->notificarSoltada(tecla);
        }
    }
}

}