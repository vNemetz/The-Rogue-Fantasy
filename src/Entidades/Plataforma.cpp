#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"

namespace ent {
namespace obs {

Plataforma::Plataforma()
    : Obstaculo()
    , altura(0)
{
}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, bool dan, int alt)
    : Obstaculo(pos, tam, dan, plataforma)
    , altura(alt)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() {
}

void Plataforma::emColisao(Entidade* pE, sf::Vector2f ds) {
    if (pE->getID() == jogador || pE->getID() == inimigo) {
        emColisaoPersonagem(static_cast<pers::Personagem*>(pE), ds);
    }
}

void Plataforma::emColisaoPersonagem(pers::Personagem* pPers, sf::Vector2f ds) {
    sf::Vector2f posicaoPers = pPers->getPosition();
    sf::Vector2f tamanhoPers = pPers->getTamanho();
    sf::Vector2f velocidadePers = pPers->getVelocidade();

    if (ds.x < 0.f && ds.y < 0.f) {
        // Se a colisão é no eixo x
        if (ds.x > ds.y) {
            if (posicaoPers.x < posicao.x)
                posicaoPers.x += ds.x;

            else
                posicaoPers.x -= ds.x;
        }
        
        // Se a colisão é no eixo y
        else {
            if (posicaoPers.y < posicao.y) {
                posicaoPers.y += ds.y;

                if (pPers->getID() == jogador) {
                    pPers->setNoChao(true);
                }
            }

            else {
                posicaoPers.y -= ds.y;
            }

            velocidadePers.y = 0;
        }
    }

    pPers->setPosition(posicaoPers);
    pPers->setVelocidade(velocidadePers);
}

}
}

