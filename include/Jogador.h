#pragma once
#include "Personagem.h"


namespace pers{
class Jogador : public pers::Personagem{
private:
    int pontos;
    bool vivo;
    // Salva para que lados o jogador está se movendo
    std::vector<bool> movendoLados;

protected:
//...
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    ~Jogador();
    void executar();

    void alteraVivo(); //altera o valor de "vivo"
    bool getVivo();
    void mover(bool estado, sf::Keyboard::Key key);
    void atualizarPosicao();
};
}