#pragma once
#include "Jogo.h"
class Ente;


//namespace dos gerenciadores
namespace ger{
class Gerenciador_Grafico{
private:

    sf::VideoMode videoMode;    //Guarda altura e largura da tela
    sf::RenderWindow* pJanela;  //Ponteiro para a janela onde tudo será renderizado
    sf::View vista;  //Para modularizar o tamanho da janela
    std::map<const char*, sf::Texture*> mapaTexturas;   //Mapa de texturas
    sf::Clock clock;
    static float deltaTime;

    //Padrão de Projeto Singleton
    static Gerenciador_Grafico* instancia;
    Gerenciador_Grafico();
public:
    ~Gerenciador_Grafico();
    static Gerenciador_Grafico* getInstancia();
    //Video Mode
    void setVideoMode();
    //Janela
    void setJanela();
    sf::RenderWindow* getJanela() const;
    sf::Vector2u getTamanhoJanela() const;
    void limpaJanela();
    void fechaJanela();
    bool pesquisaEventoJanela(sf::Event&);
    //Vista
    void setVista(float x);
    void setTamanhoVista(sf::Vector2f tam);
    void setCentroVista(sf::Vector2f pos);
    sf::View getVista() const;
    bool getJanelaAberta() const;
    void centralizarVista(Ente* e);
    //Clock
    void updateDeltaTime();
    //Texturas
     sf::Texture* carregarTextura(const char* caminho);
    //Desenhar
    void desenharEnte(Ente* pE) const;
    void desenhar(sf::RectangleShape* corpo) const;
};
}