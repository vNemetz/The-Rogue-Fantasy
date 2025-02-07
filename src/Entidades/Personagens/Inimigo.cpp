#include "Entidades/Personagens/Inimigo.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace ent {
namespace pers {

Inimigo::Inimigo()
    : Inimigo(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam) 
    : Personagem(pos, tam, inimigo)
    , nivel_maldade(1)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::incluirJogador(Jogador* jogador) {
    jogadores.push_back(jogador);
}

void Inimigo::persegueJogador(Jogador* jogador) {
    if(jogador){
        sf::Vector2f posJogador = jogador->getPosition();
        sf::Vector2f posInimigo = getPosition();

        if (posJogador.x > posInimigo.x) {
            movendoDireita = true;
            movendoEsquerda = false;
        }

        else {
            movendoDireita = false;
            movendoEsquerda = true;
        }
    }
}

float Inimigo::distanciaJogador(Jogador* jogador) const {
    if(jogador){
        sf::Vector2f posicaoJogador = jogador->getPosition();
        sf::Vector2f posicaoInimigo = posicao;

        posicaoJogador.x += jogador->getTamanho().x / 2.f;
        posicaoInimigo.x += tamanho.x / 2.f;

        sf::Vector2f dist = posicaoJogador - posicaoInimigo;
        float moduloDist = sqrt(pow((dist.x),2) + pow(dist.y, 2));
        return moduloDist;
    }
    return 0;
}

Jogador* Inimigo::jogadorMaisProximo() const {
    float menorDist = INT_MAX;
    Jogador* jogadorMenosDistante = nullptr;

    for (int i = 0; i < jogadores.size(); i++) {
            if(jogadores[i]){
            Jogador* jogador = jogadores[i];

            if (!jogador->getParaDeletar()) {
                float distancia = distanciaJogador(jogador);

                if (distancia < menorDist) {
                    jogadorMenosDistante = jogador;
                    menorDist = distancia;
                }
            }
        }
    }

    return jogadorMenosDistante;
}

}
}
