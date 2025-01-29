#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Listas/Lista_Entidades.h"
#include <cmath>

namespace ger {

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    listaInimigos.clear();
    listaObstaculos.clear();
    listaJogadores.clear();
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    listaInimigos.clear();
    listaObstaculos.clear();
    listaJogadores.clear();
}

Gerenciador_Colisoes* Gerenciador_Colisoes::instancia(nullptr);

Gerenciador_Colisoes* Gerenciador_Colisoes::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Gerenciador_Colisoes();
    }

    return instancia;
}

void Gerenciador_Colisoes::executar() {
    /* Verificar colisões dos inimigos entre si e entre o jogador */
    for (int i = 0; i < listaInimigos.size(); i++) {
        ent::Entidade* pe1 = listaInimigos[i];
        
        for (int j = i + 1; j < listaInimigos.size(); j++) {
            ent::Entidade* pe2 = listaInimigos[j];

            if (verificarColisao(pe1, pe2)) {
                ent::pers::Personagem* pP1 = static_cast<ent::pers::Personagem*>(pe1);
                pP1->emColisaoInimigo(static_cast<ent::pers::Inimigo*>(pe2), calcularColisao(pe1,pe2));
            }

            else if (pe1->getPosition() == pe2->getPosition()) {
                pe1->setPosition(pe1->getPosition() - sf::Vector2f(0.f, 0.5f));
            }
        }
        
        for (auto jogador: listaJogadores) {
            ent::Entidade* pe2 = jogador;
            if (verificarColisao(pe1, pe2)) {
                jogador->emColisaoInimigo(static_cast<ent::pers::Inimigo*>(pe1), calcularColisao(pe1,pe2));
            }
        }
    }
    
    /* Verificar colisões dos obstáculos entre inimigos e entre o jogador */
    for (auto obstaculo : listaObstaculos) {
        ent::Entidade* pe1 = obstaculo;
        
        for (auto inimigo : listaInimigos) {
            ent::Entidade* pe2 = inimigo;

            if (verificarColisao(pe1, pe2)) {
                obstaculo->emColisao(pe2, calcularColisao(pe1, pe2)); // Entre Obstáculo e Inimigo
            }
        }

        for (auto jogador: listaJogadores) {
            ent::Entidade* pe2 = jogador;
            if (verificarColisao(pe1, pe2)) {
                obstaculo->emColisao(pe2, calcularColisao(pe1, pe2)); // Entre Obstáculo e Jogador
            }
        }
    }

    /* Verificar colisões dos projéteis entre obstáculos e jogador */
    for (int i = 0; i < listaProjeteis->getTamanho(); i++) {
        ent::prj::Projetil* projetil = static_cast<ent::prj::Projetil*>(listaProjeteis->operator[](i));
        
        if (projetil) {
            for (auto jogador: listaJogadores) {
                if (verificarColisao(projetil, jogador)) {
                    projetil->emColisaoPersonagem(jogador);
                }
            }

            for (auto obstaculo: listaObstaculos) {
                if (verificarColisao(projetil, obstaculo)) {
                    projetil->emColisaoObstaculo();
                }
            }
        }
    }

    /* Verificar colisões entre jogadores */
    if (listaJogadores.size() > 1) {
        // TODO: COLISÃO ENTRE JOGADORES
    }
}

const bool Gerenciador_Colisoes::verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    sf::Vector2f ds = calcularColisao(pe1, pe2);

    return (ds.x < 0.f && ds.y < 0.f);
}

sf::Vector2f Gerenciador_Colisoes::calcularColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    sf::Vector2f pos1 = pe1->getPosition();
    sf::Vector2f pos2 = pe2->getPosition();

    sf::Vector2f tam1 = pe1->getTamanho();
    sf::Vector2f tam2 = pe2->getTamanho();

    sf::Vector2f distanciaEntreCentros(
        fabs((pos1.x + tam1.x/2.f) - (pos2.x + tam2.x/2.f)),
        fabs((pos1.y + tam1.y/2.f) - (pos2.y + tam2.y/2.f))
    );

    sf::Vector2f somaMetadeRetangulo(tam1.x/2.f + tam2.x/2.f, tam1.y/2.f + tam2.y/2.f);
    
    sf::Vector2f ds(
        (distanciaEntreCentros.x - somaMetadeRetangulo.x),
        (distanciaEntreCentros.y - somaMetadeRetangulo.y)
    );

    return ds;
}

void Gerenciador_Colisoes::incluirInimigo(ent::pers::Inimigo* pi) {
    listaInimigos.push_back(pi);
}

void Gerenciador_Colisoes::incluirObstaculo(ent::obs::Obstaculo* po) {
    listaObstaculos.push_back(po);
}

void Gerenciador_Colisoes::incluirJogador(ent::pers::Jogador* jog) {
    listaJogadores.push_back(jog);
}

void Gerenciador_Colisoes::setListaProjeteis(lis::Lista_Entidades* listaProjeteis) {
    this->listaProjeteis = listaProjeteis;
}

}
