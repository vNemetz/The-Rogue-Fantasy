#pragma once
#include <iostream>
#include "Observador.h"
#include <SFML/Graphics.hpp>
namespace controle{

class Texto_Input : public controle::Observador{
private:

    std::string texto;

public:
    Texto_Input();
    ~Texto_Input();

    void notificarApertada(sf::Keyboard::Key tecla);

    void notificarSoltada(sf::Keyboard::Key tecla);

    std::string getTexto() const;

    void criarMapa();
    void limpar();
};

}

