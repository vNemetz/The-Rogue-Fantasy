#pragma once
#include "Entidades/Personagens/Inimigo.h"
#include <cmath>

namespace ent {
namespace pers {

enum EstadoIdle {
    PARADO,
    DIREITA,
    ESQUERDA
};

class Goblin : public Inimigo {
private:
    float tempoSemDetectar;

    EstadoIdle estadoIdle; // Salva o estado da patrulha

public:
    Goblin();
    Goblin(sf::Vector2f pos, sf::Vector2f tam);
    ~Goblin();

    void executar();

    /* Movimentação */
    void movimentoAleatorio();
    
    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};
}
}

