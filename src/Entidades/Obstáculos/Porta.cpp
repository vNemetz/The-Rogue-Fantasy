#include "Entidades/Obstáculos/Porta.h"
#include "Entidades/Obstáculos/Obstaculo.h"

namespace ent {
namespace obs {


Porta::Porta()
    : Porta(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
{
}

Porta::Porta(sf::Vector2f pos, sf::Vector2f tam)
    : Obstaculo(pos, tam, false, plataforma)
    , est(fechado)
    , tempoAbrindo(0.f)
{
    setTextura("Door-Closed");
}

Porta::~Porta()
{
}

void Porta::executar() {
    atualizarEstado();
    atualizarElementosAnimacao();
}

void Porta::atualizarEstado() {
    if (aberta) {
        if (tempoAbrindo < duracaoAbrindo) {
            tempoAbrindo += pGG->getDeltaTime();
            est = estado::abrindo;
        }

        else
            est = estado::aberto;
    }

    else
        est = estado::fechado;
}

void Porta::emColisao(Entidade* pE, sf::Vector2f ds) {
}

void Porta::setAberta(bool aber) {
    aberta = aber;
}

bool Porta::getAberta() const {
    return aberta;
}

estado Porta::getEstado() const {
    return est;
}

/* Animação */
void Porta::atualizarElementosAnimacao() {
    animacao.atualizar(pGG->getDeltaTime(), true);

    switch (est) {
        case estado::aberto:
            setTextura("Door-Opened");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(1, 1), 0.001f, ElementosGraficos::parado);
            break;

        case estado::abrindo:
            setTextura("Door-Opening");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(6, 1), duracaoAbrindo / 6.f, ElementosGraficos::andando);
            break;

        case estado::fechado:
            setTextura("Door-Closed");
            animacao.atualizarSpritesheet(pTextura, sf::Vector2u(1, 1), 0.001f, ElementosGraficos::estatico);
            break;
    }

    setCorpo();
}

void Porta::setCorpo() {
    if (pSprite) {
        sf::IntRect frame = animacao.getCorpo();

        frame.top = 4;
        frame.height = 105 - 4;

        if (frame.width >= 0) {
            frame.left += 24;
            frame.width = 102 - 24;
        }

        else {
            frame.left -= 26;
            frame.width = -78;
        }

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);

        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}

}
}
