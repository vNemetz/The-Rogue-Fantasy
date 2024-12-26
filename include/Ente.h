#pragma once

#include <SFML/Graphics.hpp>

#include "Gerenciadores/Gerenciador_Grafico.h"

#define HEIGHT 1080
#define WIDTH 1920


enum ID{
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
    //Identificação única do Ente
    ID id;
    sf::Vector2f posicao;
    sf::Vector2f tamanho;
    sf::Vector2f escala;

    //Gráficos
    static ger::Gerenciador_Grafico* pGG;
    sf::Texture* pTextura;
    sf::Sprite* pSprite;
    
    //...

public:
    //Construtora e Destrutora
    Ente();
    Ente(sf::Vector2f posicao, sf::Vector2f escala, ID id = vazio);
    virtual ~Ente();

    virtual void executar() = 0;

    ID getID() const;
    void setID(ID idPar);

    //virtual void executar() = 0;

    //Gerenciador gráfico
    void setpGG(ger::Gerenciador_Grafico* pGrafico);
    
    //Gráficos
    void setTextura(const char *caminhoImagem);
    virtual void desenhar();
    void carregarSprite();
    sf::Sprite* getSprite() const;
    virtual sf::IntRect getCorpo() const;
  

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;

    sf::Vector2f getTamanho() const;
};
