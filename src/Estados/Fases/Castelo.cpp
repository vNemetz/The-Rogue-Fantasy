#include "Estados/Fases/Castelo.h"
#include <fstream>
#include <iostream>


fases::Castelo::Castelo():
Castelo(1, false)

{
    criarFundo();
    if(!carregada){
        criarMapa();
        criarEntidades();
        pJog1->setPontos(pontos);
    }else{
        std::string caminho = PROJECT_ROOT;
        caminho += "/data/savedGame.json";
        carregarJogo(caminho);
    }
}

fases::Castelo::Castelo(int pts,  bool carreg):
Fase(1, carreg)
{
    criarFundo();
    if(!carregada){
        setPontuacao(pts);
        criarMapa();
        criarEntidades();
        pJog1->setPontos(pontos);
    }else{
        std::string caminho = PROJECT_ROOT;
        caminho += "/data/savedGame.json";
        carregarJogo(caminho);
    }
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
                if (linha[i] == 'c')
                    cavaleiros.push_back(sf::Vector2i(i, j));
                
                else if (linha[i] == 'a')
                    aranhas.push_back(sf::Vector2i(i, j));

                else if (linha[i] == '*')
                    plataformasVoadoras.push_back(sf::Vector2i(i, j));

                else if (linha[i] == 'e')
                    espinhos.push_back(sf::Vector2i(i, j));

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

void fases::Castelo::criarEntidades(){
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

    // Randomiza as Plataformas (pelo menos 3)
    if (plataformasVoadoras.size() >= 3) {
        unsigned int quantidadePlataformas = (rand() % (plataformasVoadoras.size() - 2)) + 3;

        for (int i = 0; i < quantidadePlataformas; i++) {
            unsigned int plataformaRandom = (rand() % plataformasVoadoras.size());

            criarEntidade('*', plataformasVoadoras[plataformaRandom]);

            plataformasVoadoras.erase(plataformasVoadoras.begin() + plataformaRandom);
        }
    }

    else {
        for (auto plataforma: plataformasVoadoras)
            criarEntidade('*', plataforma);
    }

    // Randomiza os Espinhos (pelo menos 3)
    if (espinhos.size() >= 3) {
        unsigned int quantidadeEspinhos = (rand() % (espinhos.size() - 2)) + 3;

        for (int i = 0; i < quantidadeEspinhos; i++) {
            unsigned int espinhoRandom = (rand() % espinhos.size());

            criarEntidade('e', espinhos[espinhoRandom]);

            espinhos.erase(espinhos.begin() + espinhoRandom);
        }
    }

    else {
        for (auto espinho: espinhos)
            criarEntidade('e', espinho);
    }
}