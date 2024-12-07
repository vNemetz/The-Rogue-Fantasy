#include "Personagem.h"

pers::Personagem::Personagem() : ent::Entidade()
{
}

pers::Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ID id) : 
ent::Entidade(pos, tam, id), num_vidas(0){
}

pers::Personagem::~Personagem(){

}
