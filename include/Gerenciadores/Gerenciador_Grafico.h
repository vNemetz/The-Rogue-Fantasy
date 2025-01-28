#pragma once
#include <SFML/Graphics.hpp>

namespace ent {class Entidade;}

/* Gerenciadores - Namespace */
namespace ger{
class Gerenciador_Grafico{
private:

    sf::VideoMode videoMode;    // Guarda altura e largura da tela
    sf::RenderWindow* pJanela;  // Ponteiro para a janela onde tudo será renderizado
    sf::View vista;  // Para modularizar o tamanho da janela
    std::map<std::string, sf::Texture*> mapaTexturas;   // Mapa de texturas
    sf::Clock clock;
    static float deltaTime;
    sf::Font* fonteSmacky; 

    /* Singleton - Padrão de Projeto */
    static Gerenciador_Grafico* instancia;
    Gerenciador_Grafico();

public:
    ~Gerenciador_Grafico();
    static Gerenciador_Grafico* getInstancia();

    /* Video Mode (Resolução) */
    void setVideoMode();
    
    /* Janela */
    void setJanela();
    sf::RenderWindow* getJanela() const;
    sf::Vector2u getTamanhoJanela() const;
    bool getJanelaAberta() const;
    void limpaJanela();
    void fechaJanela();
    bool pesquisaEventoJanela(sf::Event&);
    void  display();
    
    /* Vista */
    void setVista(float x);
    sf::View getVista() const;
    void setTamanhoVista(sf::Vector2f tam);
    void setCentroVista(sf::Vector2f pos);
    void centralizarVista(ent::Entidade* e);
    void redimensionar(float aspect_ratio); // Redimensiona pJanela
    
    /* Clock */
    void updateDeltaTime();
    float getDeltaTime();
    float reiniciarClock();
    
    /* Texturas */
    sf::Texture* carregarTextura(std::string caminhoImagem, std::string nomeImagem);
    sf::Texture* getTextura(std::string nomeImagem);
    void setFonte();
    sf::Font* getFonte() const;

    /* Renderização */
    void desenharEntidade(ent::Entidade* pE) const;
    void desenhar(sf::RectangleShape* corpo) const;
    void desenharSprite(sf::Sprite* pS) const;
    void desenharTexto(sf::Text* text) const;
};
}