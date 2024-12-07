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
    sf::RenderWindow* janela = gerGrafico->getJanela();

    while (janela->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            janela->close();
    }
}
