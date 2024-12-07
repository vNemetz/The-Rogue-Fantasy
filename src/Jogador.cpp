#include "Jogador.h"

pers::Jogador::Jogador(): pers::Personagem(NULL), vivo(true){}

pers::Jogador::Jogador(ger::Gerenciador_Grafico *pGrafico): pers::Personagem(pGrafico), vivo(true){

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
    if(key == sf::Keyboard::A){setPosition(getPosition().x -1.f, getPosition().y);}
    else if(key == sf::Keyboard::D){setPosition(getPosition().x + 1.f, getPosition().y);}
    else if(key == sf::Keyboard::W){setPosition(getPosition().x, getPosition().y-1.f);}
    else if(key == sf::Keyboard::S){setPosition(getPosition().x, getPosition().y+1.f);}
}