#include "Animacao_Composta.h"
#include <iostream>

namespace ElementosGraficos{
Animacao::Animacao(){}
Animacao::Animacao( sf::Vector2u numSprites, float tempoAnimacao)
: nSprites(numSprites), tempoPorAnimacao(tempoAnimacao), tempoTotal(0.0f), spriteAtual(0,0){
}
Animacao::~Animacao(){

}

void Animacao::setCorpo(sf::Texture* textura){
    if(textura){
    corpo.width = static_cast<float>(textura->getSize().x / nSprites.x); 
    corpo.height = static_cast<float>(textura->getSize().y / nSprites.y); 
    }
}
void Animacao::atualizar(/*tipoAnimacao tipo,*/ float deltaTime)
{
    spriteAtual.y = 0;
    tempoTotal += deltaTime;
    std::cout << tempoTotal << "\n";
    if(tempoTotal >= tempoPorAnimacao){
        std::cout << "Entrou no tempo\n";
        tempoTotal -= tempoPorAnimacao; // "-=" para deixar a animação mais "suave"
        spriteAtual.x++;
        if(spriteAtual.x >= nSprites.x){spriteAtual.x = 0;} //Para voltar ao começo da spritesheet
    }
    corpo.left = spriteAtual.x * corpo.width;
    corpo.top = spriteAtual.y * corpo.height;
}
sf::IntRect ElementosGraficos::Animacao::getCorpo() const {
    return sf::IntRect(static_cast<int>(corpo.left),
                       static_cast<int>(corpo.top),
                       static_cast<int>(corpo.width),
                       static_cast<int>(corpo.height));
}

}