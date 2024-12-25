#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace ElementosGraficos{

enum tipoAnimacao{
    estatico = 1,
    andando = 3,
    atacando = 2
};

class Animacao{
private:
    sf::Vector2u nSprites;  //Número de sprites da spritesheet
    sf::Vector2u spriteAtual;
    tipoAnimacao tipo;  //Tipo da animação

    float tempoTotal; //Tempo total decorrido
    float tempoPorAnimacao;
    sf::IntRect corpo; //O retângulo que fica sobre o sprite da spritesheet que queremos usar no momento

public:
    Animacao();
    Animacao( sf::Vector2u numSprites, float tempoAnimacao);
    ~Animacao();

    void setCorpo(sf::Texture* textura);
    void atualizar(/*tipoAnimacao tipo,*/ float deltaTime);
    
    sf::IntRect getCorpo() const;
    
};
}