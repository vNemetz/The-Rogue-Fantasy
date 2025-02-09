#include "Gerenciadores/Gerenciador_Estados.h"
#include "Gerenciadores/Gerenciador_Input.h"

#include "Estados/Fases/Floresta.h"
#include "Estados/Fases/Castelo.h"
#include "Estados/Menus/Placar.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include <fstream>


namespace ger{
Gerenciador_Estados* Gerenciador_Estados::instancia(nullptr);

Gerenciador_Estados::Gerenciador_Estados():
pEstadoAtual(nullptr)
, mapaEstados()
, multijogador(false)
{
    mapaEstados.clear();

    menus::Menu_Principal* menuPrincipal = new menus::Menu_Principal(this);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(menu, static_cast<Estado*>(menuPrincipal)));
    pEstadoAtual = mapaEstados[menu];
}

Gerenciador_Estados::~Gerenciador_Estados(){
    pEstadoAtual = nullptr;
    for(auto& par : mapaEstados){ 
        delete par.second;
        par.second = nullptr;
    }
}


Gerenciador_Estados* Gerenciador_Estados::getInstancia(){
    if(instancia == nullptr){
        instancia = new Gerenciador_Estados();
    }
    return instancia;
}

void Gerenciador_Estados::inicializarEstados()
{
    fases::Floresta* faseFloresta = new fases::Floresta(false);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseFloresta) ) );

    menus::Menu_Pausa* menuPausa = new menus::Menu_Pausa(this);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(pausa, static_cast<Estado*>(menuPausa) ) );

    menus::Placar* pPlacar = new menus::Placar(this);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>( placar, static_cast<Estado*>(pPlacar) ) );

    menus::Menu_Fim* pMenu_Fim = new menus::Menu_Fim(this);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>( fim, static_cast<Estado*>(pMenu_Fim) ) );

    ger::Gerenciador_Input::getInstancia()->iniciarListaObservadores();


}

void Gerenciador_Estados::requererEstado() 
{
    if(pEstadoAtual){
        pEstadoAtual->executar();
    }

}

void Gerenciador_Estados::setEstadoAtual(tipoEstado tipo){
    int pontos = 0;
    std::string caminho = PROJECT_ROOT;
    caminho += "/data/savedGame.json";
    switch (tipo){
        case menu:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[menu]);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(menu);
            break;
        case fase:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[fase]);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(fase);
            break;
        case pausa:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[pausa]);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(pausa);
            break;
        case placar:
            pEstadoAtual = static_cast<Estado*>(mapaEstados[placar]);
            dynamic_cast<menus::Placar*>(pEstadoAtual)->construirPlacar();
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(pausa);
            break;
        case fim:
            pontos = dynamic_cast<fases::Fase*>(pEstadoAtual)->getPontuacao();
            pEstadoAtual = static_cast<Estado*>(mapaEstados[fim]);
            dynamic_cast<menus::Menu_Fim*>(pEstadoAtual)->setPontosParaIncrementar(pontos);
            ger::Gerenciador_Input::getInstancia()->criarInputMapEstado(fim);
            break;
        case salvar:
            dynamic_cast<fases::Fase*>(mapaEstados[fase])->salvarJogo(caminho);
            setEstadoAtual(pausa);
            break;
        case carregar:
            gerenciarCarregamento();
            break;
        default:
            break;
    }
    
}
 void Gerenciador_Estados::setMultijogador(bool multi)
{
    multijogador = multi;
}

Estado *Gerenciador_Estados::getEstadoAtual(){
    if(pEstadoAtual){
        return pEstadoAtual;
    }else{return nullptr;}
}
}

Estado *ger::Gerenciador_Estados::getEstado(tipoEstado tipo)
{
        return mapaEstados[tipo];
}

void ger::Gerenciador_Estados::proximaFase(int numFase, int pontos)
{
    if(numFase == 1){
            if(mapaEstados[fase]){
            delete mapaEstados[fase];
            mapaEstados.erase(fase);
        }
        ger::Gerenciador_Colisoes::getInstancia()->limparListas();
        fases::Castelo* faseCastelo = new fases::Castelo(pontos, false);
        pEstadoAtual = faseCastelo;

        mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseCastelo) ) );
        faseCastelo->setPGG(ger::Gerenciador_Grafico::getInstancia());

    }
}

void ger::Gerenciador_Estados::reiniciarJogo(int nFase)
{
    ger::Gerenciador_Colisoes::getInstancia()->limparListas();
    if(mapaEstados[fase]){
        delete mapaEstados[fase];
        mapaEstados.erase(fase);
    }
    if( nFase == 0){
        fases::Floresta* faseFloresta = new fases::Floresta(false);
        mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseFloresta) ) );
        faseFloresta->setPGG(ger::Gerenciador_Grafico::getInstancia());
    }
    else if(nFase == 1){
    fases::Castelo* faseCastelo = new fases::Castelo(0, false);
    mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<Estado*>(faseCastelo) ) );
    faseCastelo->setPGG(ger::Gerenciador_Grafico::getInstancia());
    }
}

void ger::Gerenciador_Estados::setFaseSelecionada(int n)
{
    if(n == 0){
        reiniciarJogo(0);
    }
    if(n == 1){
        reiniciarJogo(1);
    }
}

void ger::Gerenciador_Estados::gerenciarCarregamento(){
    std::string caminho = PROJECT_ROOT;
    caminho += "/data/savedGame.json";
    std::ifstream arquivo(caminho);

    if(!arquivo.is_open()){
        std::cerr<< "ERRO ao carregar jogo\n";
        return;
    }
    json j;

    try{
        arquivo >> j;
    }
    catch (const std::exception& e){
        std::cerr << "Erro ao processar JSON: " << e.what() <<"\n";
        return;
    }
    if(j.contains("infosFase")){
        int nFase = j["infosFase"]["numeroFase"];
        if(nFase == 0){
            if(mapaEstados[fase]){
                delete mapaEstados[fase];
                mapaEstados.erase(fase);
            }
            ger::Gerenciador_Colisoes::getInstancia()->limparListas();
            fases::Floresta* floresta = new fases::Floresta(true);
            mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<fases::Fase*>(floresta)));
            floresta->setPGG(ger::Gerenciador_Grafico::getInstancia());
        }
        else if(nFase == 1){
            if(mapaEstados[fase]){
                delete mapaEstados[fase];
                mapaEstados.erase(fase);
            }
            ger::Gerenciador_Colisoes::getInstancia()->limparListas();
            fases::Castelo* castelo = new fases::Castelo(0 ,true);
            mapaEstados.insert(std::pair<tipoEstado, Estado*>(fase, static_cast<fases::Fase*>(castelo)));
            castelo ->setPGG(ger::Gerenciador_Grafico::getInstancia());
        }
        setEstadoAtual(fase);
    }
}
