#pragma once
#include "Jogo.h"
class Ente;


//namespace dos gerenciadores
namespace ger{
class Gerenciador_Grafico{
private:

    sf::VideoMode videoMode; //Guarda altura e largura da tela
    sf::RenderWindow* pJanela; //Ponteiro para a janela onde tudo será renderizado
    //std::map<const char*, sf::Texture*> mapaTexturas;
    //sf::Texture* pFundo;
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();

    //Video Mode
    void setVideoMode();
    //Janela
    void setJanela();
    sf::RenderWindow* getJanela() const;
    //Texturas
    //void setTextura(const char *caminho);
    //Desenhar
    void desenharEnte(Ente* pE);
};
}