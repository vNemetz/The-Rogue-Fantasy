#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

ger::Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico* gG, pers::Jogador* jog)
: gerGrafico(gG)
, jogador(jog)
{
}

ger::Gerenciador_Eventos::~Gerenciador_Eventos() {
    gerGrafico = nullptr;
    jogador = nullptr;
}

void ger::Gerenciador_Eventos::gerenciar() {
    sf::Event evento;
    while (gerGrafico->pesquisaEventoJanela(evento)) {
        if (evento.type == sf::Event::Closed) {
            gerGrafico->fechaJanela();
        }

        if (evento.type == sf::Event::Resized) {
            if (gerGrafico) {
                gerGrafico->setTamanhoVista(sf::Vector2f(static_cast<float>(evento.size.width), static_cast<float>(evento.size.height)));
                gerGrafico->setCentroVista(jogador->getPosition());
            }
        }
        
        if (evento.type == sf::Event::KeyPressed) {
            jogador->mover(true, evento.key.code);
        }

        if (evento.type == sf::Event::KeyReleased) {
            jogador->mover(false, evento.key.code);
        }
    }
}
