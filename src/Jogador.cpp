#include "Jogador.h"

pers::Jogador::Jogador(): pers::Personagem(), vivo(true){}

pers::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID id): 
pers::Personagem(pos, tam, id), vivo(true){

}

pers::Jogador::~Jogador(){
    vivo = false;
}

void pers::Jogador::executar(){
    
}

void pers::Jogador::alteraVivo(){
    vivo = !vivo;
}
bool pers::Jogador::getVivo(){
    return vivo;
}
void pers::Jogador::mover(sf::Keyboard::Key key){
    if(key == sf::Keyboard::A){setPosition (sf::Vector2f(getPosition().x -1.f, getPosition().y));}
    else if(key == sf::Keyboard::D){setPosition (sf::Vector2f(getPosition().x + 1.f, getPosition().y));}
    else if(key == sf::Keyboard::W){setPosition (sf::Vector2f(getPosition().x, getPosition().y-1.f));}
    else if(key == sf::Keyboard::S){setPosition(sf::Vector2f(getPosition().x, getPosition().y+1.f));}
}