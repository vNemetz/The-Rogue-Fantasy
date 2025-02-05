#pragma once

#include "Entidades/Personagens/Inimigo.h"

namespace ent {
namespace pers {

class Cavaleiro : public Inimigo {
private:
    float raioAtaque;

public:
    Cavaleiro();
    Cavaleiro(sf::Vector2f pos, sf::Vector2f tam);
    ~Cavaleiro();

    void executar();
    void atacar(Jogador* jogador);
    void parar();

    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};

}
}