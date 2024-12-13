#pragma once
#include "Entidades/Jogador.h"
#include "Personagem.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace pers {

class Inimigo : public Personagem {
protected:
    int nivel_maldade;
    float raio;
    Jogador* jogador;
    sf::Clock clock;
    short moveAleatorio;
    void inicializa();

public:
    Inimigo();
    Inimigo(sf::Vector2f pos, sf::Vector2f tam, Jogador* jog);
    ~Inimigo();

    virtual void executar(); // = 0
    void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
    void movimentoAleatorio();

    //virtual void danificar(Jogador* p) = 0;
    //void salvarDataBuffer();
    // ...
};
}
}
