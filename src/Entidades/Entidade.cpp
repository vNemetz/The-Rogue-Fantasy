#include "Entidades/Entidade.h"

namespace ent {

Entidade::Entidade()
    : Entidade(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), vazio)
{
}

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f esc, ID id)
    : Ente(id)
    , velocidade(0.f, 0.f)
    , velocidadeMaxima(0.f, 0.f)
    , dt(0.f)
    , noChao(false)
    , posicao(pos)
    , escala(esc)
    , tamanho()
{
    pTextura = new sf::Texture();  // Aloca memória para pTextura
    pSprite = new sf::Sprite();    // Aloca memória para pSprite
}

Entidade::~Entidade() {
    delete pTextura;  // Libera a memória alocada para pTextura
    delete pSprite;   // Libera a memória alocada para pSprite
    
    pSprite = nullptr;
    pTextura = nullptr;
}

sf::Vector2f Entidade::getVelocidade() const {
    return velocidade;
}

void Entidade::setVelocidade(sf::Vector2f velocidade) {
    this->velocidade = velocidade;
}

void Entidade::setVelocidadeMaxima(sf::Vector2f velocidadeMaxima) {
    this->velocidadeMaxima = velocidadeMaxima;
    velocidade.y = velocidadeMaxima.y;
}

void Entidade::salvarDataBuffer()
{
}

bool Entidade::getNoChao() const {
    return noChao;
}

void Entidade::setNoChao(bool noChao) {
    this->noChao = noChao;
}

/* Gráficos */

void Entidade::setTextura(const char *nomeImagem) {
    pTextura = pGG->getTextura(nomeImagem);

    tamanho.x = pTextura->getSize().x * escala.x;
    tamanho.y = pTextura->getSize().y * escala.y;

    carregarSprite();
}

void Entidade::desenhar() {
    pGG->desenharEntidade(this);
}

void Entidade::desenharHitbox() {
    sf::RectangleShape debugShape;
    debugShape.setSize(sf::Vector2f(tamanho.x, tamanho.y));
    debugShape.setPosition(pSprite->getPosition());
    debugShape.setOutlineColor(sf::Color::Red);
    debugShape.setOutlineThickness(1);
    debugShape.setFillColor(sf::Color::Transparent);
    pGG->getJanela()->draw(debugShape);
}

void Entidade::carregarSprite() {
    pSprite->setTexture(*pTextura, false);
    pSprite->setPosition(posicao);
    pSprite->setScale(escala.x, escala.y);
}

sf::Sprite* Entidade::getSprite() const {
    return pSprite;
}

sf::IntRect Entidade::getCorpo() const {
    return pSprite->getTextureRect();
}

sf::Vector2f Entidade::getPosition() const {
    return pSprite->getPosition();
}

void Entidade::setPosition(sf::Vector2f pos) {
    if ((pos.y < 0) || (pos.y + tamanho.y > 975))
        pos.y = getPosition().y;
    
    posicao = pos;
    pSprite->setPosition(pos);
}

sf::Vector2f Entidade::getTamanho() const {
    return tamanho;
}

}
