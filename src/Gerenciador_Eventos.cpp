#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"

ger::Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico* gG)
    : gerGrafico(gG)
{
}

ger::Gerenciador_Eventos::~Gerenciador_Eventos() {
    gerGrafico = nullptr;
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
                gerGrafico->setCentroVista(sf::Vector2f(static_cast<float>(evento.size.width) / 2, static_cast<float>(evento.size.height) / 2));
            }
        }
    }
}
