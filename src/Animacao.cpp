#include "Animacao.h"

namespace ElementosGraficos{

Animacao::Animacao()
    : Animacao(sf::Vector2u(0, 0), 0.f)
{
}

Animacao::Animacao(sf::Vector2u nSprites, float tempoAnimacao)
    : numSprites(nSprites)
    , tempoPorAnimacao(tempoAnimacao)
    , tempoTotal(0.0f)
    , spriteAtual(0,0)
    , tipo(inicial)
{
}

Animacao::~Animacao()
{
}

void Animacao::atualizar(float deltaTime, bool olhandoDireita) {
    tempoTotal += deltaTime;

    if (tempoTotal >= tempoPorAnimacao) {
        tempoTotal -= tempoPorAnimacao; // "-=" para deixar a animação mais suave
        
        spriteAtual.x++;
        if (spriteAtual.x >= numSprites.x) {
            spriteAtual.x = 0; // Para voltar ao começo da spritesheet
        }

        spriteAtual.y++;
        if (spriteAtual.y >= numSprites.y) {
            spriteAtual.y = 0; // Para voltar ao começo da spritesheet
        }
    }

    corpo.top = spriteAtual.y * corpo.height;

    /* Inverte o lado se está para esquerda */
    if (olhandoDireita) {
        corpo.left = spriteAtual.x * abs(corpo.width);
        corpo.width = abs(corpo.width);
    }

    else {
        corpo.left = (spriteAtual.x + 1) * abs(corpo.width);
        corpo.width = -abs(corpo.width);
    }
}

void Animacao::atualizarSpritesheet(sf::Texture *novaTextura, sf::Vector2u numSprites, float tempoPorAnimacao, tipoAnimacao novoTipo) {
    if (tipo != novoTipo) {
        this->numSprites.x = numSprites.x;
        this->numSprites.y = numSprites.y;

        this->tempoPorAnimacao = tempoPorAnimacao;

        setCorpo(novaTextura); // Atualiza o tamanho do corpo

        /* Reinicialização da Animação a cada vez que muda */
        tempoTotal = 0.f;
        spriteAtual = sf::Vector2u(0, 0);

        tipo = novoTipo;
    }
}

void Animacao::setCorpo(sf::Texture* textura) {
    if (textura) {
        corpo.width = static_cast<float>(textura->getSize().x) / numSprites.x; 
        corpo.height = static_cast<float>(textura->getSize().y) / numSprites.y; 
    }
}

sf::IntRect ElementosGraficos::Animacao::getCorpo() const {
    return sf::IntRect(static_cast<int>(corpo.left),
                       static_cast<int>(corpo.top),
                       static_cast<int>(corpo.width),
                       static_cast<int>(corpo.height));
}

}
