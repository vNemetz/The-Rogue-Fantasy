#pragma once

#include <SFML/Graphics.hpp>

#include "Gerenciadores/Gerenciador_Grafico.h"

#define HEIGHT 1080
#define WIDTH 1920


enum ID {
    vazio = 0,
    jogador,
    plataforma,
    inimigo,
    projetil,
    menu,
    fase
};

class Ente {
protected:
    ID id; // Identificação única do Ente

    sf::Vector2f posicao;
    sf::Vector2f tamanho;
    sf::Vector2f escala;

    /* Gráficos */
    static ger::Gerenciador_Grafico* pGG;
    sf::Texture* pTextura;
    sf::Sprite* pSprite;
    
    //...

public:
    Ente();
    Ente(sf::Vector2f posicao, sf::Vector2f escala, ID id = vazio);
    virtual ~Ente();
    
    virtual void executar() = 0;

    /* ID */
    ID getID() const;
    void setID(ID id);
    
    /* Gráficos */
    void setpGG(ger::Gerenciador_Grafico* pGrafico);
    void setTextura(const char *nomeImagem);
    virtual void desenhar();

    void carregarSprite();
    sf::Sprite* getSprite() const;
    
    virtual sf::IntRect getCorpo() const;

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;

    sf::Vector2f getTamanho() const;
};
