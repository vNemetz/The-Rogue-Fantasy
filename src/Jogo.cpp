#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Jogador.h"
#include <sstream>
//...

Jogo::Jogo() 
: gerGrafico(ger::Gerenciador_Grafico::getInstancia()){
    srand(time(NULL));
    jogador = new pers::Jogador (sf::Vector2f(HEIGHT/2.0, WIDTH/2.0),sf::Vector2f(20.f, 20.f), vazio);
    gerEventos = new ger::Gerenciador_Eventos(gerGrafico, jogador);
   // e = new Ente(gerGrafico);

    executar();
}

Jogo::~Jogo(){
   // delete e;
    delete jogador;
    delete gerGrafico;
    delete gerEventos;
    //e = NULL;
    gerGrafico = NULL;
    gerEventos = NULL;
    jogador = NULL;
}

void Jogo::moveEntes(){
}

void Jogo::executar(){
    if(gerGrafico){
        jogador->setpGG(gerGrafico);
        jogador->setTarget();

        /*
        DEBUG:
        sf::Font font;
        std::string str = PROJECT_ROOT;
        str += "/assets/fonts/Arial.ttf";
        font.loadFromFile(str);
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(0.f, 0.f);
        */

        // Loop principal do jogo
        while (gerGrafico->getJanelaAberta()) {
            // Gerencia os eventos
            //gerGrafico->setVista(jogador->getPosition().x);
            gerEventos->gerenciar();

            // Limpar a janela
            gerGrafico->limpaJanela();
            
            jogador->atualizar();
            
            // Centraliza o campo de visão no jogador
            gerGrafico->centralizarVista(static_cast<Ente*>(jogador));
            
            // Desenhar o jogador (ente)
            gerGrafico->desenharEnte(static_cast<Ente*>(jogador));

            /*
            DEBUG:
            std::ostringstream oss;
            oss << "J: (" << (int) jogador->getPosition().x << ", " << (int) jogador->getPosition().y << ")";
            text.setString(oss.str());
            text.setPosition(gerGrafico->getVista().getCenter().x - gerGrafico->getVista().getSize().x/2.f, gerGrafico->getVista().getCenter().y - gerGrafico->getVista().getSize().y/2.f);
            gerGrafico->getJanela()->draw(text);
            */

            // Exibir a janela
            gerGrafico->getJanela()->display();
        }
    }
}