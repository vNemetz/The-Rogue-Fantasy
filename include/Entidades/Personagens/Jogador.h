#pragma once
#include "Entidades/Personagens/Personagem.h"

namespace ent {
namespace pers {

class Inimigo;

class Jogador : public Personagem {
private:
    int pontos;
    bool pulando;

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