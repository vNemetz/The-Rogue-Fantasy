#include "Gerenciadores/Gerenciador_Colisoes.h"
#include <cmath>
#include <iostream>

namespace ger {

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    listaInimigos.clear();
    listaObstaculos.clear();
    jogador = nullptr;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    listaInimigos.clear();
    listaObstaculos.clear();

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
    for (int i = 0; i < listaInimigos.size(); i++) {
        ent::Entidade* pe1 = listaInimigos[i];
        
        for (int j = i + 1; j < listaInimigos.size(); j++) {
            ent::Entidade* pe2 = listaInimigos[j];

            if (verificarColisao(pe1, pe2)) {
                std::cout << "Colisão entre Inimigo e Inimigo\n";
            }
        }

        ent::Entidade* pe2 = jogador;
        if (verificarColisao(pe1, pe2)) {
                std::cout << "Colisão entre Inimigo e Jogador\n";
        }
    }

    // Verificar as colisões dos obstáculos entre inimigos e entre o jogador
    for (auto obstaculo : listaObstaculos) {
        ent::Entidade* pe1 = obstaculo;
        
        for (auto inimigo : listaInimigos) {
            ent::Entidade* pe2 = inimigo;

            if (verificarColisao(pe1, pe2)) {
                obstaculo->emColisao(pe2);
            }
        }

        ent::Entidade* pe2 = jogador;
        if (verificarColisao(pe1, pe2)) {
            obstaculo->emColisao(pe2);
        }
    }
}

const bool Gerenciador_Colisoes::verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    sf::FloatRect l1 = pe1->getSprite().getGlobalBounds();
    sf::FloatRect l2 = pe2->getSprite().getGlobalBounds();

    return l1.intersects(l2);
}

void Gerenciador_Colisoes::incluirInimigo(ent::pers::Inimigo* pi) {
    listaInimigos.push_back(pi);
}

void Gerenciador_Colisoes::incluirObstaculo(ent::obs::Obstaculo* po) {
    listaObstaculos.push_back(po);
}

void Gerenciador_Colisoes::setJogador(ent::pers::Jogador* jog) {
    jogador = jog;
}

}
