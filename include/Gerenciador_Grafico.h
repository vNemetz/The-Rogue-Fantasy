#pragma once
#include "Jogo.h"
class Ente;


//namespace dos gerenciadores
namespace ger{
class Gerenciador_Grafico{
private:

    sf::VideoMode videoMode; //Guarda altura e largura da tela
    sf::RenderWindow* pJanela; //Ponteiro para a janela onde tudo será renderizado
    sf::View vista; //Para o tamanho da janela
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
    void setVista();
    void setTamanhoVista(float largura, float altura);
    void setCentroVista(float largura, float altura);
    sf::View getVista();
    //Texturas
    //void setTextura(const char *caminho);
    //Desenhar
    void desenharEnte(Ente* pE);
};
}