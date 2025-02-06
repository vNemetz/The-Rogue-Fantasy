#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/Window/Keyboard.hpp>
#include "Controle/Controle_Jogador.h"
#include "Controle/Controle_Menu.h"



namespace ger {
/* Singleton - Padrão de Projeto */
Gerenciador_Input::Gerenciador_Input()
    : mapaTeclas()
    , jogador1(nullptr)
    , jogador2(nullptr)
    , pMenuPrincipal(nullptr)
    , pFaseAtual(nullptr)
    , pMenuPausa(nullptr)
    , pGerEstados(ger::Gerenciador_Estados::getInstancia())
    , listaObservadores()
{
    listaObservadores.clear();
    it = listaObservadores.begin();
    setMenuPrincipal(static_cast<menus::Menu_Principal*>(pGerEstados->getEstado(menu)));
    criarInputMapEstado(menu);
    iniciarListaObservadores();
}

Gerenciador_Input::~Gerenciador_Input() {
    mapaTeclas.clear();
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
    this->jogador1 = jogador1;
    for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        if((*it)->getTipoControle() == controle::formaControle::controleJogador){
            if (*it){
                static_cast<controle::Controle_Jogador*>(*it)->setJogador1(this->jogador1);
            }
        }
    }
}

void Gerenciador_Input::setJogador2(ent::pers::Jogador* jogador2) {
    this->jogador2 = jogador2;
    for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        if((*it)->getTipoControle() == controle::formaControle::controleJogador){
            if (*it){
            static_cast<controle::Controle_Jogador*>(*it)->setJogador2(this->jogador2);
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

void Gerenciador_Input::incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla)
{
    mapaTeclas[tecla] = funcaoTecla;
}

void Gerenciador_Input::checarEstado() const
{
    pGerEstados->getEstadoAtual();
}
void Gerenciador_Input::criarInputMapEstado(tipoEstado tipoEstado)
{
    switch(tipoEstado){
        case fase:
            setFaseAtual(static_cast<fases::Fase*>(pGerEstados->getEstadoAtual()));
            mapaTeclas.clear();
            //criarInputMapFase();
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if (*it){
                    if((*it)->getTipoControle() == controle::formaControle::controleJogador){
                        (*it)->setAtivo(true);
                    }else{
                        (*it)->setAtivo(false);
                    }
                }
            }
            break;
        case menu:
            mapaTeclas.clear();
            //criarInputMapMenuPrincipal();
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if((*it)->getTipoControle() == controle::formaControle::controleMenuPrincipal){
                    (*it)->setAtivo(true);
                }else{
                    (*it)->setAtivo(false);
                }
            }
            break;
        case pausa:
            setMenuPausa(static_cast<menus::Menu_Pausa*>(pGerEstados->getEstadoAtual()));
            mapaTeclas.clear();
            //criarInputMapPausa();
            for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
                if((*it)->getTipoControle() == controle::formaControle::controleMenuPausa){
                    (*it)->setAtivo(true);
                }else{
                    (*it)->setAtivo(false);
                }
            }
            break;
        default:
            break;
    }
}

void Gerenciador_Input::criarInputMapFase()
{
    /* Inicializa os comandos do jogo */
    /* Jogador 1 - Comandos*/
    incluir_tecla(sf::Keyboard::Key::A, [this](bool pressionado) {
        jogador1->atualizarMovimentacao(pressionado, "A");
    });

    incluir_tecla(sf::Keyboard::Key::D, [this](bool pressionado) {
        jogador1->atualizarMovimentacao(pressionado, "D");
    });

    incluir_tecla(sf::Keyboard::Key::W, [this](bool pressionado) {
        jogador1->atualizarMovimentacao(pressionado, "W");
    });

    incluir_tecla(sf::Keyboard::Key::LShift, [this](bool pressionado) {
        jogador1->atualizarMovimentacao(pressionado, "LShift");
    });

    incluir_tecla(sf::Keyboard::Key::Space, [this](bool pressionado) {
        jogador1->atualizarMovimentacao(pressionado, "Space");
    });

    /* Jogador 2 - Comandos */
    incluir_tecla(sf::Keyboard::Key::Left, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "Left");
    });

    incluir_tecla(sf::Keyboard::Key::Right, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "Right");
    });

    incluir_tecla(sf::Keyboard::Key::Up, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "Up");
    });

    incluir_tecla(sf::Keyboard::Key::K, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "K");
    });

    incluir_tecla(sf::Keyboard::Key::L, [this](bool pressionado) {
        if (jogador2)
            jogador2->atualizarMovimentacao(pressionado, "L");
    });

    /*Esc para abrir o menu de pausa*/
    incluir_tecla(sf::Keyboard::Key::Escape, [this](bool pressionado) {
        if(pFaseAtual)
            pFaseAtual->setBufferTime(0);
            pFaseAtual->executarEstado(pausa);
    });
}

void Gerenciador_Input::criarInputMapMenuPrincipal()
{
    incluir_tecla(sf::Keyboard::Key::Down, [this](bool pressionado) {
        if (pMenuPrincipal){
            pMenuPrincipal->alterarBotaoSelecionado(1);
        }
    });
    incluir_tecla(sf::Keyboard::Key::Up, [this](bool pressionado) {
        if (pMenuPrincipal)
            pMenuPrincipal->alterarBotaoSelecionado(-1);
    });
    incluir_tecla(sf::Keyboard::Key::Enter, [this](bool pressionado) {
        if(pMenuPrincipal && pMenuPrincipal->getBufferTime() > 0.12f){
            pMenuPrincipal->setBufferTime(0);
            pMenuPrincipal->executarEstado();
        }
    });
    
}

void Gerenciador_Input::criarInputMapPausa()
{
    incluir_tecla(sf::Keyboard::Key::Down, [this](bool pressionado) {
        if (pMenuPausa){
            pMenuPausa->alterarBotaoSelecionado(1);
        }
    });
    incluir_tecla(sf::Keyboard::Key::Up, [this](bool pressionado) {
        if (pMenuPausa)
            pMenuPausa->alterarBotaoSelecionado(-1);
    });
    incluir_tecla(sf::Keyboard::Key::Enter, [this](bool pressionado) {
        if(pMenuPausa && pMenuPausa->getBufferTime() > 0.12f){
            pMenuPausa->setBufferTime(0);
            pMenuPausa->executarEstado();
        }
    });

    
}

void Gerenciador_Input::iniciarListaObservadores()
{
    controle::Controle_Menu* controleMenuPrincipal = new controle::Controle_Menu(controle::formaControle::controleMenuPrincipal,
         this, pMenuPrincipal);
    controleMenuPrincipal->setAtivo(true);
    listaObservadores.push_back(static_cast<controle::Observador*> (controleMenuPrincipal));
    
    controle::Controle_Menu* controleMenuPausa = new controle::Controle_Menu(controle::formaControle::controleMenuPausa,
         this, pMenuPausa);
    listaObservadores.push_back(static_cast<controle::Observador*> (controleMenuPausa));

    controle::Controle_Jogador* controleJogador = new controle::Controle_Jogador(controle::formaControle::controleJogador,this, jogador1, jogador2, pFaseAtual);
    listaObservadores.push_back(static_cast<controle::Observador*>(controleJogador));

}

void Gerenciador_Input::teclaApertada(sf::Keyboard::Key tecla)
{
    /*auto it = mapaTeclas.find(tecla);
    
    // Procura a tecla no mapa, se achar executa a função como verdadeira
    if (it != mapaTeclas.end())
        it->second(true);
    */
   //mapaTeclas[tecla] = true;
   for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        (*it)->notificarApertada(tecla);
   }
}

void Gerenciador_Input::teclaSoltada(sf::Keyboard::Key tecla) {

    /*auto it = mapaTeclas.find(tecla);

    // Procura a tecla no mapa, se achar executa a função como falsa
    if (it != mapaTeclas.end())
        it->second(false);*/
    //mapaTeclas[tecla] = false;
   for(it = listaObservadores.begin(); it != listaObservadores.end(); it++){
        (*it)->notificarSoltada(tecla);
   }
}
} 
