#include "Ente.h"
#include "Gerenciadores/Gerenciador_Grafico.h"

Ente::Ente() {
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
}

Ente::Ente(sf::Vector2f pos, sf::Vector2f tam, ID id)
    : id(id)
    , posicao(pos)
    , tamanho(tam)
{
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite

    setTarget();
}

Ente::~Ente() {
    delete pTextura;  // Libera a memória alocada para pTextura
    delete pSprite;   // Libera a memória alocada para pSprite
    
    pSprite = NULL;
    pTextura = NULL;
    pGG = NULL;
}  

ger::Gerenciador_Grafico* Ente::pGG(NULL); //atributo static

void Ente::setpGG(ger::Gerenciador_Grafico* pGrafico){ //testa e seta o pGG
    if(pGrafico){pGG = pGrafico;}
}

//Gráficos
void Ente::setSprite(){
    pSprite->setTexture(*pTextura, false);
    pSprite->setPosition(posicao);
}

void Ente::setTarget(){
    if(pGG){pTarget = (pGG->getJanela());}
}

sf::Sprite Ente::getSprite() const{
    return *pSprite;
}

void Ente::setTextura(sf::Texture* pTex) {
    pTextura = pTex;

    setSprite();
}

void Ente::desenhar() {
    pTarget->draw(getSprite());
}

void Ente::setPosition(sf::Vector2f pos) {
    if (pos.y < 0)
        pos.y = getPosition().y;

    pSprite->setPosition(pos);
}
sf::Vector2f Ente::getPosition() const {
    return pSprite->getPosition();
}

void Ente::setID(ID idPar){
    id = idPar;
}
ID Ente::getID(){
    return id;
}