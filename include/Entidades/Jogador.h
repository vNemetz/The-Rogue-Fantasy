#pragma once
#include "Entidades/Personagem.h"
#include "Animacao.h"

namespace ent {
namespace pers {

class Jogador : public Personagem {
private:
    int pontos;
    bool vivo;
    bool saltando;

    sf::IntRect corpo;
    ElementosGraficos::Animacao animacao;

public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam);
    ~Jogador();

    void executar();

    void atualizarMovimentacao(bool estado, sf::Keyboard::Key key);
    void atualizarPosicao();

    void pular();
    void desenhar();
    
    /* Animação */
    void atualizarAnimacao();
    void atualizarElementosAnimacao();
    
    void setCorpo();
    sf::IntRect getCorpo();

    void setVivo(bool vivo);
    bool getVivo() const;
};
}
}
