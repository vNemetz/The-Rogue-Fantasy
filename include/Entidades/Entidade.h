#pragma once
#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace ent {

class Entidade : public Ente {
protected:
    sf::Texture* pTextura;
    sf::Sprite* pSprite;

    sf::Vector2f posicao;
    sf::Vector2f tamanho;
    sf::Vector2f escala;
    
    sf::Vector2f velocidade;
    sf::Vector2f velocidadeMaxima;
    float dt;
    bool noChao;

    //ostream buffer;
    
public:
    Entidade();
    Entidade(sf::Vector2f pos, sf::Vector2f esc, ID id = vazio);
    virtual ~Entidade();

    virtual void executar() = 0;
    //virtual void salvar() = 0;
    void salvarDataBuffer();

    sf::Vector2f getVelocidade() const;
    void setVelocidade(sf::Vector2f velocidade);
    void setVelocidadeMaxima(sf::Vector2f velocidadeMaxima);
    
    bool getNoChao() const;
    void setNoChao(bool noChao);
    
    /* Gráficos */
    void setTextura(const char *nomeImagem);
    virtual void desenhar();
    void desenharHitbox();
    
    void carregarSprite();
    sf::Sprite* getSprite() const;
    
    virtual sf::IntRect getCorpo() const;

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f pos);

    sf::Vector2f getTamanho() const;
};
}
