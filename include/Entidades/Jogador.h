#pragma once
#include "Entidades/Personagem.h"
#include "Animacao_Composta.h"

namespace ent {
namespace pers {

class Jogador : public Personagem {
private:
    int pontos;
    bool vivo;
    // Salva para que lados o jogador está se movendo
    std::vector<bool> movendoLados;
    sf::IntRect corpo;
    ElementosGraficos::Animacao animacao;

protected:
//...
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam);
    ~Jogador();
    void executar();

    void alteraVivo(); //altera o valor de "vivo"
    bool getVivo();
    void mover(bool estado, sf::Keyboard::Key key);
    void atualizarPosicao();
    void desenhar();

    /*Animação*/
    void setCorpo();
    void setCorpoAnimacao();
    void atualizaAnimacao(float dt );
};
}
}
