#pragma once
#include "Entidades/Personagens/Inimigo.h"
#include <cmath>

namespace ent {
namespace pers {
class Goblin : public Inimigo {
private:
    float raio;
    // ...

public:
    Goblin();
    Goblin(sf::Vector2f pos, sf::Vector2f tam, Jogador* jog);
    ~Goblin();

    void executar();
    sf::Vector2f persegueJogador();
    //void danificar(Jogador* p);
    void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds);
};
}
}

