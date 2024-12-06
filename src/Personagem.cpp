#include "Personagem.h"

pers::Personagem::Personagem() : ent::Entidade(NULL)
{
}

pers::Personagem::Personagem(ger::Gerenciador_Grafico *pGrafico) : ent::Entidade(pGrafico), num_vidas(0){

}

pers::Personagem::~Personagem(){

}

void pers::Personagem::mover(sf::Keyboard::Key key){
    if(key == sf::Keyboard::A){setPosition(getPosition().x -1.f, getPosition().y);}
    else if(key == sf::Keyboard::D){setPosition(getPosition().x +1.f, getPosition().y);}
    else if(key == sf::Keyboard::Backspace){/*Pular*/}
    else if(key == sf::Keyboard::S){/*Agachar*/}
}

