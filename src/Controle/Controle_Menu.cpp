#include "Controle/Controle_Menu.h"
#include "Estados/Menus/Menu.h"

namespace controle{

Controle_Menu::Controle_Menu():
    Controle_Menu(nullptr)
{

}

Controle_Menu::Controle_Menu(ger::Gerenciador_Input* pGI, menus::Menu* pMenuAtual):
    Observador(pGI)
{
    setMenuAtual(pMenuAtual);
    criarMapa();
}

Controle_Menu::~Controle_Menu()
{
}

void Controle_Menu::setMenuAtual(menus::Menu *pMenuAtual)
{
    if(pMenuAtual){ this->pMenuAtual = pMenuAtual;}
}

void Controle_Menu::notificarApertada(sf::Keyboard::Key tecla)
{
    auto it = mapaTeclas.find(tecla);
    
    // Procura a tecla no mapa, se achar executa a função como verdadeira
    if (it != mapaTeclas.end())
        it->second(true);
}

void Controle_Menu::notificarSoltada(sf::Keyboard::Key tecla)
{
    auto it = mapaTeclas.find(tecla);
    
    // Procura a tecla no mapa, se achar executa a função como falsa
    if (it != mapaTeclas.end())
        it->second(false);
}

void Controle_Menu::criarMapa()
{
    incluir_tecla(sf::Keyboard::Key::Down, [this](bool pressionado) {
        if (pMenuAtual){
            pMenuAtual->alterarBotaoSelecionado(1);
        }
    });
    incluir_tecla(sf::Keyboard::Key::Up, [this](bool pressionado) {
        if (pMenuAtual)
            pMenuAtual->alterarBotaoSelecionado(-1);
    });
    incluir_tecla(sf::Keyboard::Key::Enter, [this](bool pressionado) {
        if(pMenuAtual && pMenuAtual->getBufferTime() > 0.12f){
            pMenuAtual->setBufferTime(0);
            pMenuAtual->executarEstado();
        }
    });
}

}