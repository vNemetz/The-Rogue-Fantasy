#pragma once
#include "SFML/Graphics.hpp"
#include <functional>
namespace ger{
class Gerenciador_Input; 
}

namespace controle{

enum formaControle{
    controleJogador = 0,
    controleMenuPrincipal,
    controleMenuPausa,
    textoInput
};

class Observador{
protected:
    ger::Gerenciador_Input* pGInput;
    std::map<sf::Keyboard::Key, std::function<void(bool)>> mapaTeclas;
    formaControle tipoControle;
    bool ativo;
public:
    Observador();
    Observador(formaControle tipo, ger::Gerenciador_Input* pGI = nullptr);
    virtual ~Observador();

    virtual void notificarApertada(sf::Keyboard::Key tecla) = 0;
    virtual void notificarSoltada(sf::Keyboard::Key tecla) = 0;

    formaControle getTipoControle();

    void incluir_tecla(sf::Keyboard::Key tecla, std::function<void(bool)> funcaoTecla);
    virtual void criarMapa() = 0;
    void setAtivo(bool at);

};

}