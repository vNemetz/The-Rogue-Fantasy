#pragma once
#include <vector>
#include "ElementosGraficos/Botao.h"
class Menu : public Estado{
protected:
    std::vector<ElementosGraficos::Botao*> vetorBotoes;
    std::vector<ElementosGraficos::Botao*>::iterator it;
    int botaoSelecionado;
    int minimo;
    int maximo;
    bool ativo;
    sf::Texture* pTexturaFundo;
    sf::Sprite* pSpriteFundo;
public:
    Menu();
    ~Menu();
    void alterarAtivo();
    bool getAtivo() const;
    void setTexturaFundo();
    void setSpriteFundo();
    
    
};