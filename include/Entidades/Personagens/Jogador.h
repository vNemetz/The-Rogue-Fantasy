#pragma once
#include "Entidades/Personagens/Personagem.h"
#include "Animacao.h"

namespace ent {
namespace pers {
class Inimigo;

class Jogador : public Personagem {
private:
    int pontos;
    bool vivo;
    bool saltando;

    const float knockbackHorizontal = 700.f;
    const float knockbackVertical = 300.f;

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
    
    void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds);
    
    /* Animação */
    void atualizarAnimacao();
    void atualizarElementosAnimacao();
    
    void setCorpo();
    sf::IntRect getCorpo() const;

    void setVivo(bool vivo);
    bool getVivo() const;
};
}
}