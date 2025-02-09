#include "Estados/Fases/Floresta.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include <iostream>
#include <fstream>

fases::Floresta::Floresta(bool carreg):
Fase(0, carreg)
,faseFinalizada(false)
{
    criarFundo();
    if(!carregada){
        criarMapa();
        criarEntidades();
    }else{
        std::string caminho = PROJECT_ROOT;
        caminho += "/data/savedGame.json";
        carregarJogo(caminho);
    } 

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

                else if (linha[i] == '*')
                    plataformasVoadoras.push_back(sf::Vector2i(i, j));

                else if (linha[i] == 'b')
                    caixas.push_back(sf::Vector2i(i, j));

                else
                    criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }

    arquivoMapa.close();
}

void fases::Floresta::criarEntidades() {
    // Randomiza os Goblins (pelo menos 3)
    if (goblins.size() >= 3) {
        unsigned int quantidadeGoblins = (rand() % (goblins.size() - 2)) + 3;

        for (int i = 0; i < quantidadeGoblins; i++) {
            unsigned int goblinRandom = (rand() % (goblins.size()));
            
            criarEntidade('g', goblins[goblinRandom]);
            
            goblins.erase(goblins.begin() + goblinRandom);
        }
    }

    else {
        for (auto goblin : goblins)
            criarEntidade('g', goblin);
    }
    
    // Randomiza as Aranhas (pelo menos 3)
    if (aranhas.size() >= 3) {
        unsigned int quantidadeAranhas = (rand() % (aranhas.size() - 2)) + 3;

        for (int i = 0; i < quantidadeAranhas; i++) {
            unsigned int aranhaRandom = (rand() % (aranhas.size()));
            
            criarEntidade('a', aranhas[aranhaRandom]);

            aranhas.erase(aranhas.begin() + aranhaRandom);
        }
    }

    else {
        for (auto aranha : aranhas)
            criarEntidade('a', aranha);
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

    // Randomiza as Caixas (pelo menos 3)
    if (caixas.size() >= 3) {
        unsigned int quantidadeCaixas = (rand() % (caixas.size() - 2)) + 3;

        for (int i = 0; i < quantidadeCaixas; i++) {
            unsigned int caixaRandom = (rand() % caixas.size());

            criarEntidade('b', caixas[caixaRandom]);

            caixas.erase(caixas.begin() + caixaRandom);
        }
    }

    else {
        for (auto caixa: caixas)
            criarEntidade('b', caixa);
    }
}

void fases::Floresta::checaObjetivo(){
    if(listaInimigos.getTamanho() <= 0){
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
