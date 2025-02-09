#include "Entidades/Personagens/Cavaleiro.h"

namespace ent {
namespace pers {

Cavaleiro::Cavaleiro()
    : Cavaleiro(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Cavaleiro::Cavaleiro(sf::Vector2f pos, sf::Vector2f tam)
    : Inimigo(pos, tam)
    , raioAtaque(160.f)
{
    setTextura("Knight-Idle");
    setVelocidadeMaxima(sf::Vector2f(250.f, 250.f));
    
    raioDetect = 700.f;
    duracaoAtaque = 0.35f;
    numVidas = 5;
    pontos = 300;
}

Cavaleiro::~Cavaleiro()
{
}

void Cavaleiro::executar() {
    if (jogadores.size() > 0) {
        // Se há jogadores, selecionar o que está mais próximo
        // e então se mover a ele
        Jogador* jogadorMenosDistante = jogadorMaisProximo();
        float distancia = distanciaJogador(jogadorMenosDistante);
        
        if (distancia <= raioAtaque)
            atacar(jogadorMenosDistante);

        else if (distancia <= raioDetect && (std::abs(jogadorMaisProximo()->getPosition().x - posicao.x) > 5.f))
            persegueJogador(jogadorMenosDistante);

        else
            parar();
    }

    else
        parar();

    mover();

    atualizarEstado();

    atualizarAnimacao();
}

void Cavaleiro::atacar(Jogador* jogador) {
    parar();

        if(jogador){
        if (jogador->getPosition().x > posicao.x)
            olhandoDireita = true;

        else
            olhandoDireita = false;

        atacando = true;
    }
}

void Cavaleiro::parar() {
    movendoEsquerda = false;
    movendoDireita = false;
}

/* Animação */
void Cavaleiro::atualizarElementosAnimacao() {
    switch (est) {
        case parado:
            setTextura("Knight-Idle");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(3, 1), 0.25f, ElementosGraficos::parado);
            break;

        case andando:
            setTextura("Knight-Walk");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6, 1), 0.16f, ElementosGraficos::andando);
            break;

        case sofrendo:
            setTextura("Knight-Hurt");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(2, 1), 0.33f, ElementosGraficos::sofrendo);
            break;

        case estado::atacando:
            setTextura("Knight-Attack");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(4, 1), duracaoAtaque / 4.f, ElementosGraficos::atacando);
            break;

        case estado::morrendo:
            setTextura("Knight-Death");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(4, 1), 0.2f, ElementosGraficos::morrendo);
            break;
        
        default:
            break;
    }

    setCorpo();
}

void Cavaleiro::setCorpo() {
    if (pSprite) {
        sf::IntRect frame = animacao.getCorpo();

        frame.top += 80;
        frame.height = 170 - 80;

        if (frame.width > 0) {
            frame.left += 90;
            frame.width = 168 - 90;
        }

        else {
            frame.left -= 88;
            frame.width = -78;
        }

        switch (est) {
            case estado::atacando:
                if (frame.width > 0) {
                    frame.width += 45;
                }
                
                else {
                    frame.left += 45;
                    frame.width -= 45;
                }
                break;
            
            case estado::sofrendo:
                frame.top += 5;
                frame.height -= 5;

                if (frame.width > 0) {
                    frame.left -= 22;
                }

                else {
                    frame.width -= 22;
                }
                break;

            case estado::morrendo:
                frame.top += 5;
                frame.height -= 4;

                if (frame.width > 0) {
                    frame.width += 31 + 54;
                    frame.left -= 54;
                }

                else {
                    frame.left += 31;
                    frame.width -= 54 + 31;
                }
                break;
            
            default:
                break;
        }

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);

        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}

}
}