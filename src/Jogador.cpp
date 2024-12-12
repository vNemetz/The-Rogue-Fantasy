#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

pers::Jogador::Jogador()
: pers::Personagem()
, vivo(true)
{
}

pers::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID id)
: pers::Personagem(pos, tam, id)
, vivo(true)
, movendoLados(4, false){
    setTextura();
    setSprite();
     animacao = ElementosGraficos::Animacao(pTextura, sf::Vector2u(7,3), 0.16f);
    pTarget = nullptr;
}

pers::Jogador::~Jogador() {
    vivo = false;
}

void pers::Jogador::executar() {
}

void pers::Jogador::alteraVivo() {
    vivo = !vivo;
}

bool pers::Jogador::getVivo() {
    return vivo;
}

void pers::Jogador::mover(bool estado, sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::A:
            movendoLados[0] = estado;
            break;
        
        case sf::Keyboard::D:
            movendoLados[1] = estado;
            break;

        case sf::Keyboard::W:
            movendoLados[2] = estado;
            break;

        case sf::Keyboard::S:
            movendoLados[3] = estado;
            break;

        default:
            break;
    }
}

void pers::Jogador::atualizarPosicao() {
    if (movendoLados[0])
        setPosition (sf::Vector2f(getPosition().x -1.f, getPosition()   .y));
    
    if (movendoLados[1])
        setPosition (sf::Vector2f(getPosition().x + 1.f, getPosition().y));
    
    if (movendoLados[2])
        setPosition (sf::Vector2f(getPosition().x, getPosition().y - 1.f));
    
    if (movendoLados[3])
        setPosition (sf::Vector2f(getPosition().x, getPosition().y + 1.f));
}

void pers::Jogador::setTextura(){
    std::string imagePath = PROJECT_ROOT;
    imagePath += "/assets/images/Rogue/spritesheet-rogue.png";
    pTextura->loadFromFile(imagePath);
}

void pers::Jogador::setCorpo() {
    if (pSprite) {
        sf::IntRect corpoAnimacao = animacao.getCorpo();
        pSprite->setOrigin(corpoAnimacao.width / 2.0f, corpoAnimacao.height / 2.0f);
        pSprite->setTextureRect(corpoAnimacao);
    }
}



void pers::Jogador::desenhar(){
    if(pTarget && pSprite)
        pTarget->draw(*pSprite);
}

/*Animação*/

void pers::Jogador::atualizaAnimacao(ElementosGraficos::tipoAnimacao tipo){
    animacao.atualizar(tipo, ger::Gerenciador_Grafico::getInstancia()->getDeltaTime());
    setCorpo();
}
