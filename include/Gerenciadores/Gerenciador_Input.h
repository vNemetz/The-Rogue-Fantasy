#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Estados/Estado.h"
#include "Gerenciador_Estados.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>

/* Gerenciadores - Namespace */
namespace ger {
class Gerenciador_Input {
private:
    std::map<sf::Keyboard::Key, std::function<void(bool)>> mapaTeclas;
    /* Ponteiros para fase: */
    ent::pers::Jogador* jogador1;
    ent::pers::Jogador* jogador2;   
    /* Ponteiros para o Menu: */
    menus::Menu_Principal* pMenuPrincipal;

    ger::Gerenciador_Estados* pGerEstados;

    /* Singleton - Padrão de Projeto */
    static Gerenciador_Input* instancia;

private:
    Gerenciador_Input();

public:
    ~Gerenciador_Input();

    static Gerenciador_Input* getInstancia();

    void setJogador(ent::pers::Jogador* jogador);
    void setJogador2(ent::pers::Jogador* jogador2);

    void setMenuPrincipal(menus::Menu_Principal* pMenuP);

    void incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla);
    void checarEstado() const;
     void criarInputMapEstado(tipoEstado tipoEstado); /*Cria o input map com base no estado atual*/
     void criarInputMapFase(); /*Cria o input map para uma fase*/
    void criarInputMapMenuPrincipal();

    void teclaApertada(sf::Keyboard::Key tecla);
    void teclaSoltada(sf::Keyboard::Key tecla);
};
}
