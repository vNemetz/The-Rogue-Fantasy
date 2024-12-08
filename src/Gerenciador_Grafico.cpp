#include "Gerenciador_Grafico.h"
#include "Ente.h"

ger::Gerenciador_Grafico::Gerenciador_Grafico() : pJanela(NULL){
    setVideoMode();
    setJanela();
    setVista();
}

ger::Gerenciador_Grafico::~Gerenciador_Grafico(){
    delete pJanela;
    pJanela = NULL;
}

void ger::Gerenciador_Grafico::setVista(){
    if(pJanela){vista = pJanela->getView();}
}

void ger::Gerenciador_Grafico::setTamanhoVista(float largura, float altura){
    vista.setSize(largura, altura);
}

void ger::Gerenciador_Grafico::setCentroVista(float largura, float altura){
    vista.setCenter(largura, altura);
}

sf::View ger::Gerenciador_Grafico::getVista(){
    return vista;
}

void ger::Gerenciador_Grafico::setVideoMode(){
    videoMode.height = 600;
    videoMode.width = 810;
}

void ger::Gerenciador_Grafico::setJanela(){
    pJanela = new sf::RenderWindow(videoMode, "oJogo", sf::Style::Resize | sf::Style::Default);
}

sf::RenderWindow *ger::Gerenciador_Grafico::getJanela() const{
    return pJanela;
}

void ger::Gerenciador_Grafico::desenharEnte(Ente *pE){
    if(pE){pE->desenhar();}
}
/*void ger::Gerenciador_Grafico::carregarTextura(const char* caminho){
    std::string caminhoTextura = PROJECT_ROOT;
    caminhoTextura += caminho;
    //...
}*/