#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projeteis/Projetil.h"
#include <cmath>

namespace ger {

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    listaObstaculos.clear();
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    listaObstaculos.clear();
    listaInimigos->limpar();
    listaJogadores->limpar();
    listaProjeteis->limpar();
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
    for (int i = 0; i < listaInimigos->getTamanho(); i++) {
        ent::pers::Inimigo* inimigo = static_cast<ent::pers::Inimigo*>(listaInimigos->operator[](i));
        
        if (inimigo) {
            for (int j = i + 1; j < listaInimigos->getTamanho(); j++) {
                ent::pers::Inimigo* inimigo2 = static_cast<ent::pers::Inimigo*>(listaInimigos->operator[](j));
                
                if (inimigo2) {
                    if (verificarColisao(inimigo,inimigo2))
                            inimigo->emColisaoInimigo(inimigo2, calcularColisao(inimigo,inimigo2));

                    else if (inimigo->getPosition() == inimigo2->getPosition())
                        inimigo->setPosition(inimigo->getPosition() - sf::Vector2f(0.f, 0.5f));
                }
            }
            
            for (int j = 0; j < listaJogadores->getTamanho(); j++) {
                    if(listaJogadores->operator[](j)){
                    ent::pers::Jogador* jogador = static_cast<ent::pers::Jogador*>(listaJogadores->operator[](j));

                    if (jogador)
                        if (verificarColisao(inimigo, jogador))
                                jogador->emColisaoInimigo(inimigo, calcularColisao(inimigo,jogador));
                }
            }
        }
    }
    
    /* Verificar colisões dos obstáculos entre inimigos e entre o jogador */
    for (auto obstaculo : listaObstaculos) {
        ent::Entidade* pe1 = obstaculo;
        if (pe1) {
            for (int j = 0; j < listaInimigos->getTamanho(); j++) {
                ent::Entidade* pe2 = listaInimigos->operator[](j);
                if (pe2) {
                    if (verificarColisao(pe1, pe2)) {
                        obstaculo->emColisao(pe2, calcularColisao(pe1, pe2)); // Entre Obstáculo e Inimigo
                    }
                }
            }

            for (int j = 0; j < listaJogadores->getTamanho(); j++) {
                ent::Entidade* pe2 = listaJogadores->operator[](j);
                if (pe2) {
                    if (verificarColisao(pe1, pe2)) {
                        obstaculo->emColisao(pe2, calcularColisao(pe1, pe2)); // Entre Obstáculo e Jogador
                    }
                }
            }
        }
    }

    /* Verificar colisões dos projéteis entre obstáculos e jogador */
    for (int i = 0; i < listaProjeteis->getTamanho(); i++) {
        ent::prj::Projetil* projetil = static_cast<ent::prj::Projetil*>(listaProjeteis->operator[](i));
        
        if (projetil) {
            for (int j = 0; j < listaJogadores->getTamanho(); j++) {
                ent::pers::Jogador* jogador = static_cast<ent::pers::Jogador*>(listaJogadores->operator[](j));
                if (jogador) {
                    if (verificarColisao(projetil, jogador)) {
                        projetil->emColisaoPersonagem(jogador);
                    }
                }
            }

            for (auto obstaculo: listaObstaculos) {
                if (verificarColisao(projetil, obstaculo)) {
                    projetil->emColisaoObstaculo(obstaculo);
                }
            }
        }
    }

    /* Verificar colisões entre jogadores */
}

const bool Gerenciador_Colisoes::verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    sf::Vector2f ds = calcularColisao(pe1, pe2);

    return (ds.x < 0.f && ds.y < 0.f);
}

sf::Vector2f Gerenciador_Colisoes::calcularColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    if(pe1 && pe2){
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
    return sf::Vector2f(0.f, 0.f);
}

void Gerenciador_Colisoes::incluirObstaculo(ent::obs::Obstaculo* po) {
    listaObstaculos.push_back(po);
}

void Gerenciador_Colisoes::setListaProjeteis(lis::Lista_Entidades* listaProjeteis) {
    this->listaProjeteis = listaProjeteis;
}

void Gerenciador_Colisoes::setListaInimigos(lis::Lista_Entidades* listaInimigos) {
    this->listaInimigos = listaInimigos;
}

void Gerenciador_Colisoes::setListaJogadores(lis::Lista_Entidades* listaJogadores) {
    this->listaJogadores = listaJogadores;
}

void Gerenciador_Colisoes::limparListas() {
    listaObstaculos.clear();
    
    if (listaInimigos) listaInimigos->limpar();
    if (listaJogadores) listaJogadores->limpar();
    if (listaProjeteis) listaProjeteis->limpar();
}

}
