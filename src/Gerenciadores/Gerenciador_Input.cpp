#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/Window/Keyboard.hpp>
#include "Controle/Controle_Jogador.h"
#include "Controle/Controle_Menu.h"




namespace ger {
/* Singleton - Padrão de Projeto */
Gerenciador_Input::Gerenciador_Input()
    : jogador1(nullptr)
    , jogador2(nullptr)
    , pMenuPrincipal(nullptr)
    , pFaseAtual(nullptr)
    , pMenuPausa(nullptr)
    , pMenuFim(nullptr)
    , pGerEstados(ger::Gerenciador_Estados::getInstancia())
{
    it = listaObservadores.begin();
    setMenuPrincipal(static_cast<menus::Menu_Principal*>(pGerEstados->getEstado(menu)));
    criarInputMapEstado(menu);
}

Gerenciador_Input::~Gerenciador_Input() {
    jogador1 = nullptr;
    jogador2 = nullptr;
    
    pMenuPrincipal = nullptr;
    pFaseAtual = nullptr;
    pMenuPausa = nullptr;

    for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        if(*it){
            delete (*it);
            (*it) = nullptr;
        }
    }
    listaObservadores.clear();
}

Gerenciador_Input* Gerenciador_Input::instancia(nullptr);

Gerenciador_Input* Gerenciador_Input::getInstancia() {
   if(instancia == nullptr)
        instancia = new Gerenciador_Input();
    
    return instancia;
}

/* Gerenciador de Input */
void Gerenciador_Input::setJogador(ent::pers::Jogador* jogador1) {
    if(jogador1){
        this->jogador1 = jogador1;
        for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
            if((*it)->getTipoControle() == controle::formaControle::controleJogador){
                if (*it){
                    static_cast<controle::Controle_Jogador*>(*it)->setJogador1(this->jogador1);
                }
            }
        }
    }
}

void Gerenciador_Input::setJogador2(ent::pers::Jogador* jogador2) {
    if(jogador2){
    this->jogador2 = jogador2;
        for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
            if((*it)->getTipoControle() == controle::formaControle::controleJogador){
                if (*it){
                static_cast<controle::Controle_Jogador*>(*it)->setJogador2(this->jogador2);
                }
            }
        }
    }
}

void Gerenciador_Input::setMenuPrincipal(menus::Menu_Principal *pMenuP)
{
    if(pMenuP){
        pMenuPrincipal = pMenuP;
        bool controleMenuPrincipal = false;   
        for(it = listaObservadores.begin(); it != listaObservadores.end() && controleMenuPrincipal == false; it++){
            if((*it)->getTipoControle() == controle::formaControle::controleJogador){
                static_cast<controle::Controle_Menu*>(*it)->setMenuAtual(pMenuPrincipal);
                controleMenuPrincipal = true;
            }
        }
    }
}

void Gerenciador_Input::setFaseAtual(fases::Fase *pAtual)
{
    if(pAtual){
        pFaseAtual = pAtual;
        bool controleJogador = false;   
        for(it = listaObservadores.begin(); it != listaObservadores.end() && controleJogador == false; it++){
            if((*it)->getTipoControle() == controle::formaControle::controleJogador){
                static_cast<controle::Controle_Jogador*>(*it)->setFaseAtual(pFaseAtual);
                controleJogador = true;
            }
        }
    }
}

void Gerenciador_Input::setMenuPausa(menus::Menu_Pausa *pMenuPause)
{
    if(pMenuPause){
        pMenuPausa = pMenuPause;
        bool controleMenuPausa = false;   
        for(it = listaObservadores.begin(); it != listaObservadores.end() && controleMenuPausa == false; it++){
            if((*it)->getTipoControle() == controle::formaControle::controleMenuPausa){
                static_cast<controle::Controle_Menu*>(*it)->setMenuAtual(pMenuPausa);
                controleMenuPausa = true;
            }
        }
    }
}

void Gerenciador_Input::setMenuFim(menus::Menu_Fim *pMenuFim)
{
    if(pMenuFim){
        this->pMenuFim = pMenuFim;
        bool controleMenuFim = false;   
        for(it = listaObservadores.begin(); it != listaObservadores.end() && controleMenuFim == false; it++){
            if((*it)->getTipoControle() == controle::formaControle::controleMenuFim){
                static_cast<controle::Controle_Menu*>(*it)->setMenuAtual(pMenuFim);
                controleMenuFim = true;
            }
        }
    }

}


void Gerenciador_Input::criarInputMapEstado(tipoEstado tipoEstado)
{
    switch(tipoEstado){
        case fase:
            setFaseAtual(static_cast<fases::Fase*>(pGerEstados->getEstadoAtual()));
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if (*it){
                    if((*it)->getTipoControle() == controle::formaControle::controleJogador){
                        (*it)->setAtivo(true);
                    }else{
                        (*it)->setAtivo(false);
                    }
                }
            }
            if(pMenuFim)
                pMenuFim->ativarBufferTexto(false);
            break;
        case menu:
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if(*it){
                    if((*it)->getTipoControle() == controle::formaControle::controleMenuPrincipal){
                        (*it)->setAtivo(true);
                    }else{
                        (*it)->setAtivo(false);
                    }
                }
            }
            if(pMenuFim)
            pMenuFim->ativarBufferTexto(false); 
            break;
        case pausa:
            setMenuPausa(static_cast<menus::Menu_Pausa*>(pGerEstados->getEstadoAtual()));
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if((*it)->getTipoControle() == controle::formaControle::controleMenuPausa){
                    (*it)->setAtivo(true);
                }else{
                    (*it)->setAtivo(false);
                }
            }
            break;
        case fim:
            setMenuFim(static_cast<menus::Menu_Fim*>(pGerEstados->getEstadoAtual()));
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if((*it)->getTipoControle() == controle::formaControle::controleMenuFim){ 
                    (*it)->setAtivo(true);
                }
                else if((*it)->getTipoControle() == controle::formaControle::textoInput){
                    (*it)->setAtivo(true);
                }
                else{
                    (*it)->setAtivo(false);
                }
            }
            break;
        default:
            break;
    }
}

void Gerenciador_Input::iniciarListaObservadores()
{
    controle::Controle_Menu* controleMenuPrincipal = new controle::Controle_Menu(controle::formaControle::controleMenuPrincipal,
         this, pMenuPrincipal);
    controleMenuPrincipal->setAtivo(true);
    incluirObservador(static_cast<controle::Observador*> (controleMenuPrincipal));
    
    controle::Controle_Menu* controleMenuPausa = new controle::Controle_Menu(controle::formaControle::controleMenuPausa,
         this, pMenuPausa);
    incluirObservador(static_cast<controle::Observador*> (controleMenuPausa));
    controleMenuPausa->setAtivo(false);

    controle::Controle_Jogador* controleJogador = new controle::Controle_Jogador(controle::formaControle::controleJogador,this, jogador1, jogador2, pFaseAtual);
    incluirObservador(static_cast<controle::Observador*>(controleJogador));
    controleJogador->setAtivo(false);
    
    controle::Controle_Menu* controleMenuFim = new controle::Controle_Menu(controle::formaControle::controleMenuFim,
        this, pMenuFim);
    incluirObservador(static_cast<controle::Observador*>(controleMenuFim));
    controleMenuFim->setAtivo(false);

}

}
 
