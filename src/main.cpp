#include "Jogo.h"
#include "Ente.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "oJogo");
    Ente e;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpar a janela
        window.clear(sf::Color::Black);

        // Desenhar o sprite
        window.draw(e.getSprite());

        // Exibir a janela
        window.display();
        }

    return 0;
}