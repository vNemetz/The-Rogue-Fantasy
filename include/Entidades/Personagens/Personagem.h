#pragma once
#include "Entidades/Entidade.h"

namespace ent {
namespace pers{

enum estado {
    parado,
    andando,
    pulando,
    atacando,
    morrendo,
    ausente,
    sofrendo
};

class Inimigo;

class Personagem : public Entidade {
protected:
    estado est;
    int numVidas;

    const float duracaoInvulneravel = 1.8f;
    const float duracaoAusente = 1.8f;

    float tempoParado;
    float tempoDano;

    /* Gravidade - Constantes */
    const float GRAVIDADE_REAL = 9.8f; // metros por segundo ao quadrado (m/s^2)
    const float ESCALA_GRAVIDADE_PIXEL = 100.f; // pixels por metro (px/m)
    const float GRAVIDADE = GRAVIDADE_REAL * ESCALA_GRAVIDADE_PIXEL; // pixels por segundo ao quadrado (px/s^2)

    /* Movimentação - Atributos */
    bool movendoEsquerda;
    bool movendoDireita;
    bool olhandoDireita;

    bool levandoDano;
    
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    ~Personagem();

    virtual void executar() = 0;

    /* Movimentação */
    virtual void mover();

    bool getOlhandoDireita() const {return olhandoDireita;}
    
    /* Estado */
    void atualizarEstado();
    void setEstado(estado est);
    estado getEstado() const;

    void setNumVidas(int numVidas) {this->numVidas = numVidas;}
    int getNumVidas() const {return numVidas;}

    virtual void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds) = 0;
};
}
}
