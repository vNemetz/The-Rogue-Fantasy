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

void Assunto::incluirObservador(controle::Observador *obs)
{
    if(obs){
        listaObservadores.push_back(obs);
    }
}

void Assunto::excluirObservador(controle::Observador *obs)
{
    if(obs){
        for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
            if((*it)->getTipoControle() == obs->getTipoControle()){
                Observador* aux = obs;
                listaObservadores.remove(obs);
                delete aux;
                aux = nullptr;
                return;
            }
        }
    }
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