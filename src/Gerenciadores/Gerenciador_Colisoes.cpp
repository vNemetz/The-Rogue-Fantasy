#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Entidades/Obstáculos/Obstaculo.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Aranha.h"
#include "Entidades/Projeteis/Projetil.h"
#include "Entidades/Projeteis/Teia.h"
#include <cmath>

namespace ger {

Gerenciador_Colisoes::Gerenciador_Colisoes() {
    listaObstaculos.clear();
    listaInimigos.clear();
    listaJogadores.clear();
    listaProjeteis.clear();
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    listaObstaculos.clear();
    listaInimigos.clear();
    listaJogadores.clear();
    listaProjeteis.clear();
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
        ent::pers::Inimigo* inimigo = listaInimigos[i];

        if (!inimigo || inimigo->getParaDeletar()) {
            listaInimigos.erase(listaInimigos.begin() + i);
            i--;
            continue;
        }
        
        for (int j = i + 1; j < listaInimigos.size(); j++) {
            ent::pers::Inimigo* inimigo2 = listaInimigos[j];
            
            if (!inimigo2 || inimigo2->getParaDeletar()) {
                listaInimigos.erase(listaInimigos.begin() + j);
                j--;
                continue;
            }

            if (verificarColisao(inimigo,inimigo2))
                tratarInimigoInimigo(inimigo, inimigo2);

            else if (inimigo->getPosition() == inimigo2->getPosition())
                inimigo->setPosition(inimigo->getPosition() - sf::Vector2f(0.f, 10.f));
        }
        
        for (int j = 0; j < listaJogadores.size(); j++) {
            if(listaJogadores[j]){
                ent::pers::Jogador* jogador = listaJogadores[j];

                if (!jogador || jogador->getParaDeletar()) {
                    listaJogadores.erase(listaJogadores.begin() + j);
                    j--;
                    continue;
                }

                if (verificarColisao(inimigo, jogador))
                        tratarJogadorInimigo(jogador, inimigo);
            }
        }
    }
    
    /* Verificar colisões dos obstáculos entre inimigos e entre o jogador */
    for (int i = 0; i < listaObstaculos.size(); i++) {
        ent::obs::Obstaculo* obstaculo = listaObstaculos[i];

        if (!obstaculo || obstaculo->getParaDeletar()) {
            listaObstaculos.erase(find(listaObstaculos.begin(), listaObstaculos.end(), obstaculo));
            i--;
            continue;
        }

        for (int j = i + 1; j < listaObstaculos.size(); j++) {
            ent::obs::Obstaculo* obstaculo2 = listaObstaculos[j];

            if (!obstaculo2 || obstaculo2->getParaDeletar()) {
                listaObstaculos.erase(find(listaObstaculos.begin(), listaObstaculos.end(), obstaculo2));
                j--;
                continue;
            }

            if (verificarColisao(obstaculo, obstaculo2)) {
                if (obstaculo->getID() != plataforma && obstaculo2->getID() == plataforma)
                    tratarEntidadeEstatica(obstaculo, obstaculo2);

                if (obstaculo->getID() == plataforma && obstaculo2->getID() != plataforma)
                    tratarEntidadeEstatica(obstaculo2, obstaculo);

                else if (obstaculo->getID() == espinho && obstaculo2->getID() == caixa)
                    tratarEntidadeEstatica(obstaculo2, obstaculo);

                else if (obstaculo->getID() == caixa && obstaculo2->getID() == espinho)
                    tratarEntidadeEstatica(obstaculo, obstaculo2);
            }
        }

        for (int j = 0; j < listaInimigos.size(); j++) {
            ent::pers::Inimigo* inimigo = listaInimigos[j];
            
            if (!inimigo || inimigo->getParaDeletar()) {
                listaInimigos.erase(listaInimigos.begin() + j);
                j--;
                continue;
            }

            if (verificarColisao(obstaculo, inimigo)) {
                if (obstaculo->getID() == plataforma)
                    tratarEntidadeEstatica(inimigo, obstaculo);

                else if (obstaculo->getID() == caixa)
                    tratarPersonagemCaixa(inimigo, static_cast<ent::obs::Caixa*>(obstaculo));

                else if (obstaculo->getID() == espinho)
                    tratarPersonagemEspinho(inimigo, static_cast<ent::obs::Espinho*>(obstaculo));
            }
        }

        for (int j = 0; j < listaJogadores.size(); j++) {
            ent::pers::Jogador* jogador = listaJogadores[j];
            if(jogador){
                if (verificarColisao(obstaculo, jogador)) {
                    if (obstaculo->getID() == plataforma)
                        tratarEntidadeEstatica(jogador, obstaculo);
                    
                    else if (obstaculo->getID() == caixa)
                        tratarPersonagemCaixa(jogador, static_cast<ent::obs::Caixa*>(obstaculo));
                    
                    else if (obstaculo->getID() == espinho)
                        tratarPersonagemEspinho(jogador, static_cast<ent::obs::Espinho*>(obstaculo));

                    else if (obstaculo->getID() == porta)
                        tratarJogadorPorta(jogador, static_cast<ent::obs::Porta*>(obstaculo));
                }

            }
        }
    }

    /* Verificar colisões dos projéteis entre obstáculos e jogador */
    for (int i = 0; i < listaProjeteis.size(); i++) {
        ent::prj::Projetil* projetil = listaProjeteis[i];
        
        if (!projetil || projetil->getParaDeletar()) {
            listaProjeteis.erase(listaProjeteis.begin() + i);
            i--;
            continue;
        }

        for (int j = 0; j < listaJogadores.size(); j++) {
            ent::pers::Jogador* jogador = listaJogadores[j];
            
            if (jogador) {
                if (verificarColisao(projetil, jogador)) {
                    tratarProjetilPersonagem(projetil, jogador);
                }
            }
        }

        for (auto obstaculo: listaObstaculos) {
            if (verificarColisao(projetil, obstaculo)) {
                if (obstaculo->getID() != porta)
                    tratarProjetilObstaculo(projetil, obstaculo);
            }
        }

        for (auto inimigo: listaInimigos) {
            if (verificarColisao(projetil, inimigo) && !dynamic_cast<ent::pers::Aranha*>(inimigo))
                projetil->setParaDeletar(true);
        }
    }
}

const bool Gerenciador_Colisoes::verificarColisao(ent::Entidade* pe1, ent::Entidade* pe2) const {
    if(pe1 && pe2){
        sf::Vector2f ds = calcularColisao(pe1, pe2);
        return (ds.x < 0.f && ds.y < 0.f);
    }

    return false;
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
    return sf::Vector2f(0.0f, 0.0f);
}

/* Tratamento de colisões */

void Gerenciador_Colisoes::tratarJogadorInimigo(ent::pers::Jogador* jogador, ent::pers::Inimigo* inimigo) {
    if(jogador && inimigo){
        if (!jogador->getLevandoDano()) {
            bool inimigoADireita = inimigo->getPosition().x > jogador->getPosition().x;
            sf::Vector2f ds = calcularColisao(jogador, inimigo);

            // Se o jogador está atacando e acertando,
            // além da colisão ser horizontal, 
            // e também se o inimigo não estiver sofrendo dano nem morrendo,
            // dá dano
            if (jogador->getAtacando() && ((jogador->getOlhandoDireita() && inimigoADireita) || (!jogador->getOlhandoDireita() && !inimigoADireita)) && (ds.x > ds.y)) {
                if ((inimigo->getEstado() != ent::pers::estado::sofrendo) && (inimigo->getEstado() != ent::pers::estado::morrendo)) {
                    inimigo->sofrerDano(jogador->getPosition());
                    
                    if (inimigo->getNumVidas() <= 0) {
                        jogador->incrementarPontos(inimigo->getPontos());
                    }
                }
            }

            // Se não está atacando ou errando o ataque,
            // e o inimigo não está sofrendo, leva dano
            else if (inimigo->getEstado() != ent::pers::estado::sofrendo && inimigo->getEstado() != ent::pers::estado::morrendo) {
                jogador->sofrerDano(inimigo->getPosition());
            }
        }
    }
}

void Gerenciador_Colisoes::tratarInimigoInimigo(ent::pers::Inimigo* inimigo1, ent::pers::Inimigo* inimigo2) {
    if(inimigo1 && inimigo2){
        sf::Vector2f posicaoInimigo = inimigo2->getPosition();
        sf::Vector2f tamanhoPers = inimigo2->getTamanho();
        sf::Vector2f velocidadeInimigo = inimigo2->getVelocidade();

        sf::Vector2f ds = calcularColisao(inimigo1, inimigo2);

        if (ds.x != 0.f && ds.y != 0.f) {
            // Se a colisão é no eixo x
            if (ds.x > ds.y) {
                if (posicaoInimigo.x < inimigo1->getPosition().x)
                    posicaoInimigo.x += ds.x;

                else
                    posicaoInimigo.x -= ds.x;
            }
        }

        inimigo2->setPosition(posicaoInimigo);
        inimigo2->setVelocidade(velocidadeInimigo);
    }
}

void Gerenciador_Colisoes::tratarEntidadeEstatica(ent::Entidade* dinamica, ent::Entidade* estatica) {
    if (dinamica && estatica) {
        sf::Vector2f posicaoEnt = dinamica->getPosition();
        sf::Vector2f velocidadeEnt = dinamica->getVelocidade();
        sf::Vector2f ds = calcularColisao(dinamica, estatica);

        if (ds.x < 0.f && ds.y < 0.f) {
            // Se a colisão é no eixo x
            if (ds.x > ds.y) {
                ds.x = ceil(ds.x);
                if (posicaoEnt.x < estatica->getPosition().x)
                    posicaoEnt.x += ds.x;

                else
                    posicaoEnt.x -= ds.x;
            }
            
            // Se a colisão é no eixo y
            else {
                ds.y = ceil(ds.y);
                if (posicaoEnt.y < estatica->getPosition().y) {
                    posicaoEnt.y += ds.y;

                    velocidadeEnt.y = 0;
                    dinamica->setNoChao(true);
                }

                else {
                    posicaoEnt.y -= ds.y;
                    
                    if (velocidadeEnt.y < 0)
                        velocidadeEnt.y = 0;
                }
            }
        }

        dinamica->setPosition(posicaoEnt);
        dinamica->setVelocidade(velocidadeEnt);
    }
}

void Gerenciador_Colisoes::tratarProjetilPersonagem(ent::prj::Projetil* projetil, ent::pers::Personagem* personagem) {
    if (projetil && personagem) {
        bool projetilADireita = projetil->getPosition().x > personagem->getPosition().x;
        sf::Vector2f ds = calcularColisao(personagem, projetil);

        // Se o personagem não estiver atacando a teia, sofre dano
        if (!(personagem->getAtacando() && ((personagem->getOlhandoDireita() && projetilADireita) || (!personagem->getOlhandoDireita() && !projetilADireita)) && (ds.x > ds.y))) {
            
            // Se for uma teia, calcula o dano antes
            if (dynamic_cast<ent::prj::Teia*>(projetil))
                static_cast<ent::prj::Teia*>(projetil)->calcularDano();

            personagem->sofrerDano(projetil->getPosition(), projetil->getDano());
        }
        
        projetil->setParaDeletar(true);
    }
}

void Gerenciador_Colisoes::tratarProjetilObstaculo(ent::prj::Projetil* projetil, ent::obs::Obstaculo* obstaculo) {
    projetil->setParaDeletar(true);
}

void Gerenciador_Colisoes::tratarJogadorPorta(ent::pers::Jogador* jogador, ent::obs::Porta* porta) {
    /* TODO */
}

void Gerenciador_Colisoes::tratarPersonagemCaixa(ent::pers::Personagem* personagem, ent::obs::Caixa* caixa) {
    if(personagem && caixa){
        sf::Vector2f posicaoCaixa = caixa->getPosition();
        sf::Vector2f posicaoPers = personagem->getPosition();
        sf::Vector2f velocidadePers = personagem->getVelocidade();

        sf::Vector2f ds = calcularColisao(personagem, caixa);

        if (ds.x < 0.f && ds.y < 0.f) {
            // Se a colisão é no eixo x
            if (ds.x > ds.y) {
                ds.x = ceil(ds.x);

                if (!caixa->getMovendo()) {
                    if (posicaoCaixa.x < personagem->getPosition().x)
                        posicaoCaixa.x += ds.x;

                    else
                        posicaoCaixa.x -= ds.x;
                    

                    personagem->setLentidao(caixa->getFatorDeLentidao());
                    personagem->setLento(true);
                    caixa->setMovendo(true);
                }

                else {
                    if (posicaoCaixa.x < personagem->getPosition().x)
                        posicaoPers.x -= ds.x;

                    else
                        posicaoPers.x += ds.x;
                }
            }
            
            // Se a colisão é no eixo y
            else {
                ds.y = ceil(ds.y);
                if (posicaoCaixa.y > personagem->getPosition().y) {
                    posicaoPers.y += ds.y;

                    personagem->setNoChao(true);
                }

                else {
                    posicaoCaixa.y -= ds.y;
                    caixa->setVelocidade(sf::Vector2f(caixa->getVelocidade().x, 0.f));
                }
            }
        }

        personagem->setPosition(posicaoPers);
        personagem->setVelocidade(velocidadePers);
        caixa->setPosition(posicaoCaixa);
    }
}

void Gerenciador_Colisoes::tratarPersonagemEspinho(ent::pers::Personagem* personagem, ent::obs::Espinho* espinho) {
    if(personagem && espinho){
        sf::Vector2f posicaoPers = personagem->getPosition();
        sf::Vector2f velocidadePers = personagem->getVelocidade();
        sf::Vector2f ds = calcularColisao(personagem, espinho);
        
        if (ds.x < 0.f && ds.y < 0.f) {
            // Se a colisão é no eixo x
            if (ds.x > ds.y) {
                ds.x = ceil(ds.x);
                if (posicaoPers.x < espinho->getPosition().x)
                    posicaoPers.x += ds.x;

                else
                    posicaoPers.x -= ds.x;
            }
            
            // Se a colisão é no eixo y
            else {
                ds.y = ceil(ds.y);
                if (posicaoPers.y < espinho->getPosition().y) {
                    posicaoPers.y -= ds.y;
                    sf::Vector2f posicaoAtacante = espinho->getPosition();
                    posicaoAtacante.x += espinho->getTamanho().x / 2.f;

                    personagem->sofrerDano(posicaoAtacante);
                    return;
                }
                
                // Se a colisão é no eixo y
                else {
                    posicaoPers.y -= ds.y;
                    
                    if (velocidadePers.y < 0)
                        velocidadePers.y = 0;
                }
            }

            personagem->setPosition(posicaoPers);
            personagem->setVelocidade(velocidadePers);
        }

    }
}

void Gerenciador_Colisoes::incluirEntidade(ent::Entidade* entidade) {
    if (entidade->getID() == jogador)
        incluirJogador(static_cast<ent::pers::Jogador*>(entidade));

    else if (entidade->getID() == inimigo)
        incluirInimigo(static_cast<ent::pers::Inimigo*>(entidade));
    
    else if (entidade->getID() == projetil)
        incluirProjetil(static_cast<ent::prj::Projetil*>(entidade));
    
    else
        incluirObstaculo(static_cast<ent::obs::Obstaculo*>(entidade));
}

void Gerenciador_Colisoes::incluirObstaculo(ent::obs::Obstaculo* po) {
    listaObstaculos.push_back(po);
}

void Gerenciador_Colisoes::incluirJogador(ent::pers::Jogador* jogador) {
    listaJogadores.push_back(jogador);
}

void Gerenciador_Colisoes::incluirInimigo(ent::pers::Inimigo* inimigo) {
    listaInimigos.push_back(inimigo);
}

void Gerenciador_Colisoes::incluirProjetil(ent::prj::Projetil* projetil) {
    listaProjeteis.push_back(projetil);
}

void Gerenciador_Colisoes::limparListas() {
    listaObstaculos.clear();
    listaInimigos.clear();
    listaJogadores.clear();
    listaProjeteis.clear();
}

}
