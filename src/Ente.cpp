#include "../include/Ente.h"
#include "../include/Gerenciador_Grafico.h"

Ente::Ente() : id(cont++){
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
    setTextura();
    setSprite();
    setTarget();
}

int Ente::cont(0);

Ente::Ente(ger::Gerenciador_Grafico* pGrafico = NULL) : id(cont++){
    setpGG(pGrafico);
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
    setTextura();
    setSprite();
    setTarget();
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
    pSprite->setPosition(sf::Vector2f((float)(rand() % 810), (float)(rand() % 600)));
}

void Ente::setTarget(){
    if(pGG){pTarget = (pGG->getJanela());}
}

sf::Sprite Ente::getSprite() const{
    return *pSprite;
}

void Ente::setTextura(){
    std::string imagePath = PROJECT_ROOT;
    imagePath += "/assets/images/Rogue/rogue.png";
    
    pTextura->loadFromFile(imagePath);
}
void Ente::desenhar(){
    pTarget->draw(getSprite());
}
