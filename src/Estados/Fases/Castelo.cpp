#include "Estados/Fases/Castelo.h"
#include <fstream>
#include <iostream>
#include "Entidades/Obstáculos/Porta.h"


fases::Castelo::Castelo():
Fase(1)
{
    criarMapa();
    criarFundo();
    criarInimigos();

}

fases::Castelo::~Castelo()
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
        std::cerr << "Erro ao abrir o arquivo de Mapa do Castelo\n";
    }

    int j = 0;
    while(std::getline(arquivoMapa, linha)){
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ' ') {
                if (linha[i] == 'g'){
                    std::cout<<"cavaleiro\n";
                    cavaleiros.push_back(sf::Vector2i(i, j));
                }   
                else if (linha[i] == 'a')
                    aranhas.push_back(sf::Vector2i(i, j));

                else
                    criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }

    arquivoMapa.close();
}

    void fases::Castelo::checaObjetivo()
{
}

void fases::Castelo::criarInimigos(){
    // Randomiza a quantidade de inimigos, com um mínimo de 3 de cada

    if (cavaleiros.size() >= 3) {
        unsigned int quantidadeCavaleiros = (rand() % (cavaleiros.size() - 2)) + 3;

        for (int i = 0; i < quantidadeCavaleiros; i++) {
            unsigned int cavaleiroRandom = (rand() % (cavaleiros.size()));
            
            criarEntidade('c', cavaleiros[cavaleiroRandom]);
            
            cavaleiros.erase(cavaleiros.begin() + cavaleiroRandom);
        }
    }

    else {
        for (auto cavaleiro : cavaleiros) {
            criarEntidade('c', cavaleiro);
        }
    }
    
    if (aranhas.size() >= 3) {
        unsigned int quantidadeAranhas = (rand() % (aranhas.size() - 2)) + 3;

        for (int i = 0; i < quantidadeAranhas; i++) {
            unsigned int aranhaRandom = (rand() % (aranhas.size()));
            
            criarEntidade('a', aranhas[aranhaRandom]);

            aranhas.erase(aranhas.begin() + aranhaRandom);
        }
    }

    else {
        for (auto aranha : aranhas) {
            criarEntidade('a', aranha);
        }
    }
}