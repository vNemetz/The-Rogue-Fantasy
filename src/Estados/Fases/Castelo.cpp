#include "Estados/Fases/Castelo.h"
#include <fstream>
#include <iostream>

fases::Castelo::Castelo():
Fase(1)
{
}

fases::Castelo::~Castelo()
{
}

void fases::Castelo::executar()
{
}

void fases::Castelo::criarFundo(){
    pFundo = ger::Gerenciador_Grafico::getInstancia()->getTextura("Castle");
    spriteFundo.setTexture(*pFundo);

    sf::Vector2u tamanhoFundo = pFundo->getSize();
    sf::Vector2u tamanhoJanela = ger::Gerenciador_Grafico::getInstancia()->getJanela()->getSize();
    spriteFundo.setScale(
        static_cast<float>(tamanhoJanela.x) / tamanhoFundo.x,
        static_cast<float>(tamanhoJanela.y) / tamanhoFundo.y
    );
}

void fases::Castelo::criarMapa(){
    std::ifstream arquivoMapa;
    std::string linha;
    std::string caminho = PROJECT_ROOT;
    caminho += "/maps/mapaCastelo.txt";

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
