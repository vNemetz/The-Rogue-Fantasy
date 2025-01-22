#pragma once
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Window/Keyboard.hpp>

namespace ent {
namespace pers {

class Inimigo;

class Jogador : public Personagem {
private:
    int pontos;
    bool pulando;

    sf::Keyboard::Key botaoEsquerda;
    sf::Keyboard::Key botaoDireita;
    sf::Keyboard::Key botaoPular;
    sf::Keyboard::Key botaoCorrer;
    sf::Keyboard::Key botaoAtacar;

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
    void carregarControles(bool jogador1);
    
    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();
};
}
}