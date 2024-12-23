#pragma once
#include "Entidades/Inimigo.h"
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
    void persegueJogador();
    //void danificar(Jogador* p);
};
}
}

