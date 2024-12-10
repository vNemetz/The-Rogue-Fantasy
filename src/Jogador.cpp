#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

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
    switch (key) {
        case sf::Keyboard::A:
            setPosition (sf::Vector2f(getPosition().x -1.f, getPosition()   .y));
            break;
        
        case sf::Keyboard::D:
            setPosition (sf::Vector2f(getPosition().x + 1.f, getPosition().y));
            break;

        case sf::Keyboard::W:
            setPosition (sf::Vector2f(getPosition().x, getPosition().y - 1.f));
            break;

        case sf::Keyboard::S:
            setPosition (sf::Vector2f(getPosition().x, getPosition().y + 1.f));
            break;

        default:
            break;
    }

}