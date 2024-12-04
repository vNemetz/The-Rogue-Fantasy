#pragma once
#include "Jogo.h"
#include "Gerenciador_Grafico.h"

class Ente{
protected:
    int id;
    static ger::Gerenciador_Grafico* pGG;
    sf::Texture* pTextura;
    sf::Sprite* pSprite;
    //...

public:
    //Construtora e Destrutora
    Ente();
    Ente(ger::Gerenciador_Grafico* pGrafico);
    ~Ente();

    //virtual void executar() = 0;

    //Gerenciador gráfico
    void setpGG(ger::Gerenciador_Grafico* pGrafico);
    
    //Gráficos
    void setTextura();
    void desenhar();
    void setSprite();
    sf::Sprite getSprite();
};