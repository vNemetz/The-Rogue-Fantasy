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

public:
    Inimigo();
    Inimigo(sf::Vector2f pos, sf::Vector2f tam);
    ~Inimigo();

    virtual void executar() = 0;
    virtual void atualizarElementosAnimacao() = 0;
    virtual void emColisaoInimigo(Inimigo* pI, sf::Vector2f ds) = 0;

    void incluirJogador(Jogador* jogador);

    //virtual void danificar(Jogador* p) = 0;
    //void salvarDataBuffer();
};
}
}
