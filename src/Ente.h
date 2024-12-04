#pragma once
#include "Jogo.h"

#include "Gerenciador_Grafico.h"

#include <string>

class Ente{
protected:
    //Identificação única do Ente
    int id;
    static int cont;

    //Gráficos
    static ger::Gerenciador_Grafico* pGG;
    sf::Texture* pTextura;
    sf::Sprite* pSprite;

    //Desenhar
    sf::RenderTarget* pTarget; //Alvo da renderização (janela)
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
    void setTarget();
    sf::Sprite getSprite() const;
};