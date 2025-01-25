#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace ger{

Gerenciador_Eventos::Gerenciador_Eventos()
    : jogador(nullptr)
{
    gerColisoes = Gerenciador_Colisoes::getInstancia();
    gerInput = Gerenciador_Input::getInstancia();
}

Gerenciador_Eventos::~Gerenciador_Eventos(){
    jogador = nullptr;
}

Gerenciador_Eventos* Gerenciador_Eventos::instancia(nullptr);


Gerenciador_Eventos* Gerenciador_Eventos::getInstancia(){
    if(instancia == nullptr){
        instancia = new Gerenciador_Eventos();
    }
    return instancia;
}

void Gerenciador_Eventos::setJogador(ent::pers::Jogador *jog){
    jogador = jog;
}

void Gerenciador_Eventos::gerenciar() {
    sf::Event evento;
    while (ger::Gerenciador_Grafico::getInstancia()->pesquisaEventoJanela(evento)) {
        if (evento.type == sf::Event::Closed) {
            ger::Gerenciador_Grafico::getInstancia()->fechaJanela();
        }

        if (evento.type == sf::Event::Resized) {
            if (ger::Gerenciador_Grafico::getInstancia()) {
                ger::Gerenciador_Grafico::getInstancia()->setTamanhoVista(sf::Vector2f(static_cast<float>(evento.size.width), static_cast<float>(evento.size.height)));
                ger::Gerenciador_Grafico::getInstancia()->setCentroVista(jogador->getPosition());
            }
        }
        
        if (evento.type == sf::Event::KeyPressed) {
            Gerenciador_Input::getInstancia()->teclaApertada(evento.key.code);
        }

        if (evento.type == sf::Event::KeyReleased) {
            Gerenciador_Input::getInstancia()->teclaSoltada(evento.key.code);
        }
    }
}
}
