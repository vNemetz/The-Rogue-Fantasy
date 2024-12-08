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
    sf::RenderWindow* pJanela = gerGrafico->getJanela();

    while (pJanela->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            pJanela->close();
        if (evento.type == sf::Event::Resized) {
                // Ajusta a view (câmera) para a nova resolução
                if(gerGrafico){
                    gerGrafico->setTamanhoVista(static_cast<float>(evento.size.width), static_cast<float>(evento.size.height));
                    gerGrafico->setCentroVista(static_cast<float>(evento.size.width) / 2, static_cast<float>(evento.size.height) / 2);
                    pJanela->setView(gerGrafico->getVista());
                }
            }
    }
}
