#include "Estados/Fases/Floresta.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Entidades/Obstáculos/Porta.h"
#include <iostream>
#include <fstream>

fases::Floresta::Floresta():
Fase(0)
,faseFinalizada(false)
{
    criarMapa();
    criarFundo();
    criarInimigos();
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
            if(linha[i] != ' ') {
                if (linha[i] == 'g')
                    goblins.push_back(sf::Vector2i(i, j));

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

void fases::Floresta::criarInimigos() {
    // Randomiza a quantidade de inimigos, com um mínimo de 3 de cada
    if (goblins.size() >= 3) {
        unsigned int quantidadeGoblins = (rand() % (goblins.size() - 2)) + 3;

        for (int i = 0; i < quantidadeGoblins; i++) {
            unsigned int goblinRandom = (rand() % (goblins.size()));
            
            criarEntidade('g', goblins[goblinRandom]);
            
            goblins.erase(goblins.begin() + goblinRandom);
        }
    }

    else {
        for (auto goblin : goblins) {
            criarEntidade('g', goblin);
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

void fases::Floresta::checaObjetivo(){
    if(listaInimigos.getTamanho() == 0){
        proximaFase();
    }
}

void fases::Floresta::proximaFase()
{
    pGEstados = ger::Gerenciador_Estados::getInstancia();
    if(pGEstados){
        pGEstados->proximaFase(1, pontos);
    }
}
