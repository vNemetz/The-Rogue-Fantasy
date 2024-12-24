#pragma once
#include "Entidades/Personagem.h"


namespace ent {
namespace pers {

class Jogador : public Personagem {
private:
    int pontos;
    bool vivo;
    bool pulando;
    sf::IntRect corpo;

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

    void pular();

    /*Animação*/
    //void atualizaAnimacao(ElementosGraficos::tipoAnimacao tipo);
};
}
}
