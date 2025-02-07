#include "Estados/Menus/Placar.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include <fstream>


namespace menus{

Placar::Placar():
    Placar(nullptr)
{

}

Placar::Placar(ger::Gerenciador_Estados* pGE):
    Menu(pGE, 0, 0, placar)
    , vetorTextos()
{
    it = vetorTextos.begin();
    setTexturaFundo("Menu-bg");
    sf::Vector2f posicaoBotao = sf::Vector2f(pSpriteFundo->getPosition().x+pSpriteFundo->getGlobalBounds().getSize().x/2.0f - 380.0f,
        HEIGHT/1.25f);
    adicionarBotao("Yellow-Button", sf::Vector2f(4.0f, 3.0f), "MENU PRINCIPAL",posicaoBotao);

    construirPlacar();

    //sf::Font* fonte = ger::Gerenciador_Grafico::getInstancia()->getFonte();
    //adicionarTexto(fonte, sf::Color::White, "Vinícius", sf::Vector2f(2.0f, 2.0f));
}

Placar::~Placar(){
    limparTextos();
}

void Placar::executarEstado(){

    switch (botaoSelecionado){
        case 0:
            pGEstados->setEstadoAtual(menu);
            break;
        default:
            break;
    }
}


void Placar::adicionarTexto(sf::Font * font, sf::Color cor, std::string stg, sf::Vector2f tam)
{
    ElementosGraficos::Texto* pTexto = new ElementosGraficos::Texto(font, cor, stg, tam);
    vetorTextos.push_back(pTexto);
}

void Placar::limparTextos()
{
    it = vetorTextos.begin();
    while(it != vetorTextos.end()){
        delete *it;
        *it = nullptr;
        it++;
    }
    
}

void Placar::desenhar()
{
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getJanela()->getDefaultView());
    ger::Gerenciador_Grafico::getInstancia()->desenharSprite(pSpriteFundo);
    desenharBotoes();
    desenharTextos();
    ger::Gerenciador_Grafico::getInstancia()->getJanela()->setView(ger::Gerenciador_Grafico::getInstancia()->getVista());

}

 void Placar::construirPlacar()
{
    std::ifstream arquivo;
    std::string caminho = PROJECT_ROOT;
    caminho += "/data/Leaderboard.txt";
    arquivo.open(caminho, std::ios::binary | std::ios::in);

    if(!arquivo){
        std::ofstream arquivoNovo(caminho, std::ios::out| std::ios::trunc);
        arquivoNovo.close();
    }
    int pontos = 0;
    std::string nome;
    std::string stringTexto;
    std::string stringPontos;

    ElementosGraficos::Texto* txt;
    float espacamento = 0.0f;

    for(int i = 0; i < 10; i++){
        nome = "";
        pontos = 0;
        stringPontos = "";

        std::getline(arquivo, stringPontos);
        std::getline(arquivo, nome);

        stringTexto = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10 ) + " - " + nome + " ";
        if(stringPontos.length() > 0){
            pontos = std::stoi(stringPontos);

            stringPontos  = std::to_string(pontos / 1000000);
            pontos %= 1000000;

            stringPontos += std::to_string(pontos / 100000);
            pontos %= 100000;

            stringPontos += std::to_string(pontos / 10000);
            pontos %= 10000;

            stringPontos += std::to_string(pontos / 1000);
            pontos %= 1000;

            stringPontos += std::to_string(pontos / 100);
            pontos %= 100;

            stringPontos += std::to_string(pontos / 10);
            pontos %= 10;
        
            stringPontos += std::to_string(pontos);
        }

        while(stringTexto.length() + stringPontos.length() < 85){
            stringTexto += " .";

        }
        stringTexto += " ";
        txt = new ElementosGraficos::Texto(ger::Gerenciador_Grafico::getInstancia()->getFonte(), sf::Color::White,
            stringTexto + stringPontos, sf::Vector2f(1.5f, 1.5f));
        sf::Vector2f posicao(130.0f, 60.f + espacamento);
        espacamento += 80.0f;
        txt->setPosicao(posicao);
        vetorTextos.push_back(txt);
    }
    arquivo.close();

}

void Placar::desenharTextos()
{
        it = vetorTextos.begin();
        while(it != vetorTextos.end()){
            ger::Gerenciador_Grafico::getInstancia()->desenharTexto((*it)->getTexto());
            it++;
        }
}
}
