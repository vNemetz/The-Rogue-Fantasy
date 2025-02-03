#include "Estados/Fases/Floresta.h"
#include <iostream>
#include <fstream>

fases::Floresta::Floresta():
Fase(0)
,faseFinalizada(false)
{
    criarMapa();
    criarFundo();
}

fases::Floresta::~Floresta()
{
}

void fases::Floresta::criarFundo(){
    pFundo = ger::Gerenciador_Grafico::getInstancia()->getTextura("Forest");
    spriteFundo.setTexture(*pFundo);

    sf::Vector2u tamanhoFundo = pFundo->getSize();
    sf::Vector2u tamanhoJanela = ger::Gerenciador_Grafico::getInstancia()->getJanela()->getSize();
    spriteFundo.setScale(
        static_cast<float>(tamanhoJanela.x) / tamanhoFundo.x,
        static_cast<float>(tamanhoJanela.y) / tamanhoFundo.y
    );
}

void fases::Floresta::criarMapa(){
    std::ifstream arquivoMapa;
    std::string linha;
    std::string caminho = PROJECT_ROOT;
    caminho += "/maps/mapaFloresta.txt";

    arquivoMapa.open(caminho);
    if(!arquivoMapa.is_open()){
        std::cerr << "Erro ao abrir o arquivo de Mapa da Floresta\n";
    }
    int j = 0;
    while(std::getline(arquivoMapa, linha)){
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ' '){
                criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }
    
    arquivoMapa.close();
}