#pragma once
#include "Entidades/Personagens/Jogador.h"
#include "Personagem.h"
#include <SFML/System/Vector2.hpp>

namespace ent {
namespace pers {

class Inimigo : public Personagem {
protected:
    int nivel_maldade;
    std::vector<Jogador*> jogadores;

    float raioDetect;

public:
    Inimigo();
    Inimigo(sf::Vector2f pos, sf::Vector2f tam);
    ~Inimigo();

    virtual void executar() = 0;
    virtual void atualizarElementosAnimacao() = 0;
    void incluirJogador(Jogador* jogador);
    void persegueJogador(Jogador* jogador);

    float distanciaJogador(Jogador* jogador) const;
    Jogador* jogadorMaisProximo() const;
};
}
}
