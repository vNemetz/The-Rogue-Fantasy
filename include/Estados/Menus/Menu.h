#pragma once
#include <vector>
#include "ElementosGraficos/Botao.h"
#include "Estados/Estado.h"

namespace menus{
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
    Menu(ger::Gerenciador_Estados* pGE);
    ~Menu();
    void alterarAtivo();
    bool getAtivo() const;
    void setTexturaFundo(std::string nomeImg);
    void setSpriteFundo();
    void setBotaoSelecionado(int botao);
    void limparVetorBotoes();
    void adicionarBotao(std::string nomeImg);    
    void desenharBotoes();

    void checarBotoes();
    void desenhar();

    virtual void executar();
};
}