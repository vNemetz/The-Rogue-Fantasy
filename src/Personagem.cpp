#include "../include/Personagem.h"

pers::Personagem::Personagem() : ent::Entidade(NULL)
{
}

pers::Personagem::Personagem(ger::Gerenciador_Grafico *pGrafico) : ent::Entidade(pGrafico), num_vidas(0){

}

pers::Personagem::~Personagem(){

}
