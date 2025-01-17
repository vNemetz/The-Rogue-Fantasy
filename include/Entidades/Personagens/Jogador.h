#pragma once
#include "Entidades/Personagens/Personagem.h"

namespace ent {
namespace pers {

class Inimigo;

class Jogador : public Personagem {
private:
    int pontos;
    bool pulando;

    /* Knockback - Constantes */
    const float knockbackHorizontal = 700.f;
    const float knockbackVertical = 300.f;

public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam);
    ~Jogador();

    void executar();
    void desenhar();

    /* Movimentação */
    void atualizarMovimentacao(bool estado, sf::Keyboard::Key key);
    void atualizarPosicao();
    void pular();
    void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds);
    
    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};
}
}