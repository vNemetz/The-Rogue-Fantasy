#pragma once
#include "Jogo.h"
class Ente;


//namespace dos gerenciadores
namespace ger{
class Gerenciador_Grafico{
private:

    sf::VideoMode videoMode; //Guarda altura e largura da tela
    sf::RenderWindow* pJanela; //Ponteiro para a janela onde tudo será renderizado
    //sf::Texture* pFundo;

protected:
//...
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();

    //Video Mode
    void setVideoMode();
    //Janela
    void setJanela();
    sf::RenderWindow* getJanela() const;
    //Desenhar
    void desenharEnte(Ente* pE);
};
}