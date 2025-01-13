#pragma once

#include "Entidades/Personagens/Jogador.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>

/* Gerenciadores - Namespace */
namespace ger {
class Gerenciador_Input {
private:
    std::map<sf::Keyboard::Key, std::function<void(bool)>> mapaTeclas;
    ent::pers::Jogador* jogador;

    /* Singleton - Padrão de Projeto */
    static Gerenciador_Input* instancia;

private:
    Gerenciador_Input();

public:
    ~Gerenciador_Input();

    static Gerenciador_Input* getInstancia();

    void setJogador(ent::pers::Jogador* jog);
    void incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla);
    
    void teclaApertada(sf::Keyboard::Key tecla);
    void teclaSoltada(sf::Keyboard::Key tecla);
};
}
