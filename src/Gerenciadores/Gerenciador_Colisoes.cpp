#include "Gerenciadores/Gerenciador_Colisoes.h"
#include <cmath>
#include <iostream>

namespace ger {

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    LIs.clear();
    LOs.clear();
    jogador = nullptr;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    LIs.clear();
    LOs.clear();

    jogador = nullptr;
}

Gerenciador_Colisoes* Gerenciador_Colisoes::instancia(nullptr);

Gerenciador_Colisoes* Gerenciador_Colisoes::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Gerenciador_Colisoes();
    }

    return instancia;
}

void Gerenciador_Colisoes::executar() {
    // Verificar as colisões dos inimigos entre si e entre o jogador
    for (int i = 0; i < LIs.size(); i++) {
        ent::Entidade* pe1 = LIs[i];
        
        for (int j = i + 1; j < LIs.size(); j++) {
            ent::Entidade* pe2 = LIs[j];

            if (verificarColisao(pe1, pe2)) {
                //pe1->colidir(pe2);
                std::cout << "Colisão entre Inimigo e Inimigo\n";
            }
        }

        ent::Entidade* pe2 = jogador;
        if (verificarColisao(pe1, pe2)) {
                std::cout << "Colisão entre Inimigo e Jogador\n";
        }
    }

    // Verificar as colisões dos obstáculos entre inimigos e entre o jogador
    for (auto i : LOs) {
        ent::Entidade* pe1 = i;

        for (auto j : LIs) {
            ent::Entidade* pe2 = j;

            if (verificarColisao(pe1, pe2)) {
                //pe1->colidir(pe2);
                std::cout << "Colisão entre Obstáculo e Inimigo\n";
            }
        }

        ent::Entidade* pe2 = jogador;
        if (verificarColisao(pe1, pe2)) {
            //pe1->colidir(pe2);
            std::cout << "Colisão entre Obstáculo e Jogador\n";
        }
    }
}

const bool Gerenciador_Colisoes::verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    sf::Vector2f pos1 = pe1->getPosition();
    sf::Vector2f pos2 = pe2->getPosition();

    sf::Vector2f tam1 = pe1->getTamanho();
    sf::Vector2f tam2 = pe2->getTamanho();

    sf::Vector2f distanciaCentros(
        fabs((pos1.x+tam1.x/2.f) - (pos2.x + tam2.x/2.f)),
        fabs((pos1.y+tam1.y/2.f) - (pos2.y+tam2.y/2.f))
    );

    sf::Vector2f soma(tam1.x/2.f + tam2.x/2.f, tam1.y/2.f+tam2.y/2.f);

    sf::Vector2f ds(distanciaCentros.x-soma.x, distanciaCentros.y-soma.y);

    if (ds.x <= 0.f && ds.y <= 0.f) {
        return true;
    }
    
    return false;
}

void Gerenciador_Colisoes::incluirInimigo(ent::pers::Inimigo* pi) {
    LIs.push_back(pi);
}

void Gerenciador_Colisoes::incluirObstaculo(ent::obs::Obstaculo* po) {
    LOs.push_back(po);
}

void Gerenciador_Colisoes::setJogador(ent::pers::Jogador* jog) {
    jogador = jog;
}

}
