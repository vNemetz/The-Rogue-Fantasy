#pragma once
#include "Entidades/Entidade.h"
#include "ElementosGraficos/Animacao.h"

namespace ent {
namespace pers{

enum estado {
    parado,
    andando,
    correndo,
    pulando,
    atacando,
    morrendo,
    ausente,
    sofrendo
};

class Inimigo;

class Personagem : public Entidade {
protected:
    bool vivo;
    int numVidas;
    int pontos;

    /* Estado */
    estado est;
    float tempoParado;
    const float duracaoAusente = 1.8f;
    float tempoDano;
    const float duracaoInvulneravel = 1.8f;
    float tempoAtaque;
    float duracaoAtaque = 0.5f; // Duração Total do Ataque
    float tempoMorrendo;
    const float duracaoMorrendo = 2.f;

    /* Movimentação - Atributos */
    bool movendoEsquerda;
    bool movendoDireita;
    bool olhandoDireita;
    bool correndo;
    bool levandoDano;
    bool atacando;
    bool morto;

    bool podeAtacar;

    /* Knockback - Constantes */
    const float knockbackHorizontal = 500.f;
    const float knockbackVertical = 300.f;

    /* Animação */
    ElementosGraficos::Animacao animacao;
    
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id = vazio);
    ~Personagem();

    virtual void executar() = 0;

    /* Movimentação */
    virtual void mover();
    void sofrerDano(sf::Vector2f posicaoAtacante);
    bool getOlhandoDireita() const;
    
    /* Estado */
    void atualizarEstado();
    void setEstado(estado est);
    estado getEstado() const;

    void setVivo(bool vivo);
    bool getVivo() const;
    void setNumVidas(int numVidas);
    int getNumVidas() const;
    bool getAtacando() const;
    bool getLevandoDano() const;
    int getPontos() const;

    /* Animação */
    void atualizarAnimacao();
    virtual void atualizarElementosAnimacao() = 0;
};
}
}
