#pragma once
#include "Entidades/Personagem.h"
#include "Animacao.h"

namespace ent {
namespace pers {

class Jogador : public Personagem {
private:
    int pontos;
    bool vivo;
    bool pulando;
    sf::IntRect corpo;
    ElementosGraficos::Animacao animacao;

protected:
//...
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam);
    ~Jogador();

    void executar();

    void alteraVivo(); //altera o valor de "vivo"
    bool getVivo() const;
    void atualizarEstado(bool estado, sf::Keyboard::Key key);
    void atualizarPosicao();
    void desenhar();
    void pular();
    void setEstado(estado es);


    /*Animação*/
    void setCorpo();
    sf::IntRect getCorpo();
    void setCorpoAnimacao();
    void atualizaTempoAnimacao(float dt);
    void atualizaElementosAnimacao();
};
}
}
