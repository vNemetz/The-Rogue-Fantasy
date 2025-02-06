#pragma once
#include "SFML/Graphics.hpp"
#include <functional>
namespace ger{
class Gerenciador_Input; 
}

namespace controle{

class Observador{
protected:
    ger::Gerenciador_Input* pGInput;
        std::map<sf::Keyboard::Key, std::function<void(bool)>> mapaTeclas;
public:
    Observador();
    Observador(ger::Gerenciador_Input* pGI = nullptr);
    virtual ~Observador();

    virtual void notificarApertada(sf::Keyboard::Key tecla) = 0;
    virtual void notificarSoltada(sf::Keyboard::Key tecla) = 0;

    void incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla);
    virtual void criarMapa() = 0;

};

}