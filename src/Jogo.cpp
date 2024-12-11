#include "Jogo.h"
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Jogador.h"
#include <sstream>
//...

Jogo::Jogo() {
    srand(time(NULL));
    jogador = new pers::Jogador (sf::Vector2f(HEIGHT/2.0, WIDTH/2.0),sf::Vector2f(20.f, 20.f), vazio);
    jogador->setpGG(ger::Gerenciador_Grafico::getInstancia());

    executar();
}

Jogo::~Jogo(){
    delete jogador;
    jogador = nullptr;
}

void Jogo::moveEntes(){
}

void Jogo::executar(){
    if(ger::Gerenciador_Grafico::getInstancia()){
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
        while (ger::Gerenciador_Grafico::getInstancia()->getJanelaAberta()) {
            // Gerencia os eventos
            //gerGrafico->setVista(jogador->getPosition().x);
            ger::Gerenciador_Eventos::getInstancia()->setJogador(jogador);
            ger::Gerenciador_Eventos::getInstancia()->gerenciar();

            // Limpar a janela
            ger::Gerenciador_Grafico::getInstancia()->limpaJanela();
            
            jogador->atualizarPosicao();
            
            // Centraliza o campo de visão no jogador
            ger::Gerenciador_Grafico::getInstancia()->centralizarVista(static_cast<Ente*>(jogador));
            
            // Desenhar o jogador (ente)
            ger::Gerenciador_Grafico::getInstancia()->desenharEnte(static_cast<Ente*>(jogador));

            /*
            DEBUG:
            std::ostringstream oss;
            oss << "J: (" << (int) jogador->getPosition().x << ", " << (int) jogador->getPosition().y << ")";
            text.setString(oss.str());
            text.setPosition(gerGrafico->getVista().getCenter().x - gerGrafico->getVista().getSize().x/2.f, gerGrafico->getVista().getCenter().y - gerGrafico->getVista().getSize().y/2.f);
            gerGrafico->getJanela()->draw(text);
            */

            // Exibir a janela
            ger::Gerenciador_Grafico::getInstancia()->display();
        }
    }
}