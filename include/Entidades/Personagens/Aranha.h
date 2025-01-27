#pragma once

#include "Entidades/Personagens/Inimigo.h"

namespace ent {
namespace pers {

class Aranha : public Inimigo {
private:
    float raioAtaque;

public:
    Aranha();
    Aranha(sf::Vector2f pos, sf::Vector2f tam);
    ~Aranha();

    void executar();
    void atacar(Jogador* jogador);

    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};

}
}
