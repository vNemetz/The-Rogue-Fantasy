#pragma once
#include "Observador.h"


namespace menus{
    class Menu;
}

namespace controle{

class Controle_Menu : public Observador{
private:
    menus::Menu* pMenuAtual;


public:
    Controle_Menu();
    Controle_Menu(formaControle tipoControle, ger::Gerenciador_Input* pGI = nullptr, 
        menus::Menu* pMenuAtual = nullptr);
    ~Controle_Menu();

    void setMenuAtual(menus::Menu* pMenuAtual);

    void notificarApertada(sf::Keyboard::Key tecla);
    void notificarSoltada(sf::Keyboard::Key tecla);

    void criarMapa();
    

};

}