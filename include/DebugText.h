#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

class DebugText {
private:
    sf::Font font;
    sf::Text text;
public:
    DebugText() {
        std::string fontPath = PROJECT_ROOT;
        fontPath += "/assets/fonts/Arial.ttf";
        if (!font.loadFromFile(fontPath)) {
            throw std::runtime_error("Erro ao carregar a fonte: " + fontPath);
        }
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
    }

    void update(const sf::Vector2f& playerPosition, const sf::View& view) {
        std::ostringstream oss;
        oss << "J: (" << static_cast<int>(playerPosition.x) << ", " << static_cast<int>(playerPosition.y) << ")";
        text.setString(oss.str());
        text.setPosition(
            view.getCenter().x - view.getSize().x / 2.f,
            view.getCenter().y - view.getSize().y / 2.f
        );
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};
