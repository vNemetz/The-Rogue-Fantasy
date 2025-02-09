#pragma once
#include "Ente.h"
#include <SFML/System/Vector2.hpp>
#include <climits>

namespace ger { class Mediador; }

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
    bool lento;
    float tamanhoFase;

    bool paraDeletar;

    ger::Mediador* mediador;

    /* Gravidade - Constantes */
    const float GRAVIDADE_REAL = 9.8f; // metros por segundo ao quadrado (m/s^2)
    const float ESCALA_GRAVIDADE_PIXEL = 100.f; // pixels por metro (px/m)
    const float GRAVIDADE = GRAVIDADE_REAL * ESCALA_GRAVIDADE_PIXEL; // pixels por segundo ao quadrado (px/s^2)
    
public:
    Entidade();
    Entidade(sf::Vector2f pos, sf::Vector2f esc, ID id = vazio);
    virtual ~Entidade();

    virtual void executar() = 0;
    //virtual void salvar() = 0;
    void salvarDataBuffer();

    void aplicarGravidade();

    sf::Vector2f getVelocidade() const;
    void setVelocidade(sf::Vector2f velocidade);
    void setVelocidadeMaxima(sf::Vector2f velocidadeMaxima);
    sf::Vector2f getVelocidadeMaxima() const;
    
    bool getNoChao() const;
    void setNoChao(bool noChao);
    void setLento(bool lento);
    
    /* Gráficos */
    void setTextura(std::string nomeImagem);
    virtual void desenhar();
    void desenharHitbox();
    
    void carregarSprite();
    sf::Sprite* getSprite() const;
    
    virtual sf::IntRect getCorpo() const;

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f pos);

    sf::Vector2f getTamanho() const;

    void setTamanhoFase(float tamanhoFase);
    bool getParaDeletar() const;
    void setParaDeletar(bool paraDeletar);
};
}
