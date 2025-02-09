#pragma once
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Window/Keyboard.hpp>

namespace ent {
namespace pers {

class Inimigo;

class Jogador : public Personagem {
private:
    bool pulando;
    bool jogador1;

    std::string botaoEsquerda;
    std::string botaoDireita;
    std::string botaoPular;
    std::string botaoCorrer;
    std::string botaoAtacar;
    
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam, bool jog);
    ~Jogador();

    void executar();
    void desenhar();

    /* Movimentação */
    void atualizarMovimentacao(bool estado, std::string key);
    void atualizarPosicao();
    void pular();
    void carregarControles();
    void incrementarPontos(int pontos);
    
    /* Animação */
    void atualizarElementosAnimacao();
    void setCorpo();

    /*Getters e Setters para SAVE*/
    int getPontos() const;
    void setPontos(int pts);
    bool getEhJogador1() const;
    void setEhJogador1(bool j1);
    bool getPulando() const;
    void setPulando(bool pulo);


};
}
}