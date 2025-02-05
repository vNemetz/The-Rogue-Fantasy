#pragma once
#include "Menu.h"
#include "ElementosGraficos/Texto.h"

namespace menus{

class Placar : public Menu{
private:
    std::vector<ElementosGraficos::Texto*> vetorTextos;
    std::vector<ElementosGraficos::Texto*>::iterator it;
public:
    Placar();
    Placar(ger::Gerenciador_Estados* pGE = nullptr);
    ~Placar();

    void adicionarTexto(sf::Font* font, sf::Color cor, std::string stg, sf::Vector2f tam);
    void limparTextos();
    void desenhar() override;
    void construirPlacar();

    void desenharTextos();
    void executarEstado();
};

}