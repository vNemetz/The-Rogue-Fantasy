#include "Entidades/Plataforma.h"
#include "Entidades/Jogador.h"
#include "Entidades/Obstaculo.h"
#include "Entidades/Personagem.h"
#include <SFML/System/Vector2.hpp>

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

void Plataforma::obstacular(pers::Jogador* p) {
}

void Plataforma::emColisao(Entidade* pE) {
    if (pE->getID() == jogador || pE->getID() == inimigo) {
        pers::Personagem* pPers = static_cast<pers::Personagem*>(pE);

        sf::Vector2f novaPosicao = pPers->getPosition();

        sf::FloatRect limitesEntidade = pE->getSprite().getGlobalBounds();
        sf::FloatRect limitesPlataforma = getSprite().getGlobalBounds();

        if (limitesEntidade.intersects(limitesPlataforma)) {
            // Calcula a sobreposição em cada eixo
            float sobreposicaoX = std::min(limitesEntidade.left + limitesEntidade.width, limitesPlataforma.left + limitesPlataforma.width) 
                                - std::max(limitesEntidade.left, limitesPlataforma.left);

            float sobreposicaoY = std::min(limitesEntidade.top + limitesEntidade.height, limitesPlataforma.top + limitesPlataforma.height) 
                                - std::max(limitesEntidade.top, limitesPlataforma.top);


            // Decide o eixo de correção (prioriza o eixo com menor sobreposição)
            
            if (sobreposicaoX < sobreposicaoY) {
                // Correção no eixo X
                if (limitesEntidade.left < limitesPlataforma.left) {
                    novaPosicao += sf::Vector2f(-sobreposicaoX, 0.0f); // Empurrar para a esquerda
                }
                
                else {
                    novaPosicao += sf::Vector2f(sobreposicaoX, 0.0f);  // Empurrar para a direita
                }
            }

            else {
                // Correção no eixo Y
                if (limitesEntidade.top < limitesPlataforma.top) {
                    novaPosicao += sf::Vector2f(0.0f, -sobreposicaoY); // Empurrar para cima
                }
                
                else {
                    novaPosicao += sf::Vector2f(0.0f, sobreposicaoY); // Empurrar para baixo
                }
            }
        }

        pPers->mover(novaPosicao);
    }
}

}
}

