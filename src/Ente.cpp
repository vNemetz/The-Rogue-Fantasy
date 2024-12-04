#include "Ente.h"

Ente::Ente() : pSprite(NULL), pTextura(NULL){
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
    setTextura();
    setSprite();
}

Ente::Ente(ger::Gerenciador_Grafico* pGrafico = NULL) : pSprite(NULL), pTextura(NULL){
    setpGG(pGrafico);
}
Ente::~Ente(){
    delete pTextura;  // Libera a memória alocada para pTextura
    delete pSprite;   // Libera a memória alocada para pSprite
    pSprite = NULL;
    pTextura = NULL;
}

ger::Gerenciador_Grafico* Ente::pGG(NULL); //atributo static

void Ente::setpGG(ger::Gerenciador_Grafico* pGrafico){ //testa e seta o pGG
    if(pGrafico){pGG = pGrafico;}
}

//Gráficos
void Ente::setSprite(){
    pSprite->setTexture(*pTextura, false);
    pSprite->setPosition(sf::Vector2f(100.f, 100.f));
}

sf::Sprite Ente::getSprite(){
    return *pSprite;
}

void Ente::setTextura(){
    pTextura->loadFromFile("../assets/images/Rogue/rogue.png");
}
void Ente::desenhar()
{
}
