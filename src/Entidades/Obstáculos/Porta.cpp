#include "Entidades/Obstáculos/Porta.h"

namespace ent{
obs::Porta::Porta():
    animacao(sf::Vector2u(10,1), 0.14f)
{   
     //pTextura = ger::Gerenciador_Grafico::getInstancia()->getTextura("Static-door");
     //pSprite->setTexture(*pTextura, true);
     /*if(pTextura){
        animacao.atualizarSpritesheet(pTextura, sf::Vector2u(10,1), 0.14f, ElementosGraficos::estatico);
        setCorpo();
     }*/
     pSprite->setPosition(sf::Vector2f(2100.f, 800.f));
}

obs::Porta::~Porta()
{

}

void obs::Porta::atualizarAnimacao()
{   
    //for(int i = 0; i < 5; i++){ //Para rodar a animação completa da porta
        animacao.atualizar(pGG->getDeltaTime(), true);
    //}
}

void obs::Porta::setCorpo()
{
    if (pSprite) {
        sf::IntRect frame = animacao.getCorpo();

        pSprite->setTextureRect(frame);

        tamanho = sf::Vector2f(frame.width*escala.x, frame.height*escala.y);
        
        if (frame.width <= 0)
            tamanho.x = -tamanho.x;
    }
}



void obs::Porta::executar()
{
    //atualizarAnimacao();
    pGG->desenharSprite(pSprite);   
}

void obs::Porta::emColisao(Entidade* pE, sf::Vector2f ds){

}
}

