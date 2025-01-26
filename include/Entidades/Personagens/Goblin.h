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
    float raioDetect;
    float tempoSemDetectar;

    EstadoIdle estadoIdle; // Salva o estado da patrulha

public:
    Goblin();
    Goblin(sf::Vector2f pos, sf::Vector2f tam);
    ~Goblin();

    void executar();

    /* Movimentação */
    void persegueJogador(int idx);
    void movimentoAleatorio();

    void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds);
    
    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};
}
}

