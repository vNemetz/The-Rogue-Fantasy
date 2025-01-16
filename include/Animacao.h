#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace ElementosGraficos{

enum tipoAnimacao {
    inicial,
    estatico,
    atacando,
    andando,
    pulando,
    parado,
    sofrendo
};

class Animacao {
private:
    sf::Vector2u numSprites; // Número de sprites da Spritesheet
    sf::Vector2u spriteAtual;

    sf::IntRect corpo; // Pedaço do Spritesheet que contém o sprite atual

    tipoAnimacao tipo;

    float tempoPorAnimacao;
    float tempoTotal;

public:
    Animacao();
    Animacao(sf::Vector2u nSprites, float tempoAnimacao);
    ~Animacao();

    void atualizar(float deltaTime, bool olhandoDireita);
    void atualizarSpritesheet(sf::Texture* novaTextura, sf::Vector2u numSprites, float tempoPorAnimacao, tipoAnimacao novoTipo);
    
    void setCorpo(sf::Texture* textura);
    sf::IntRect getCorpo() const;
};

}
