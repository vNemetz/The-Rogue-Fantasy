#include "../include/Gerenciador_Grafico.h"
#include "../include/Ente.h"

ger::Gerenciador_Grafico::Gerenciador_Grafico() : pJanela(NULL){
    setVideoMode();
    setJanela();
}

ger::Gerenciador_Grafico::~Gerenciador_Grafico(){
    delete pJanela;
    pJanela = NULL;    
}

void ger::Gerenciador_Grafico::setVideoMode(){
    videoMode.height = 600;
    videoMode.width = 810;
}

void ger::Gerenciador_Grafico::setJanela(){
    pJanela = new sf::RenderWindow(videoMode, "oJogo", sf::Style::Default);
}

sf::RenderWindow *ger::Gerenciador_Grafico::getJanela() const{
    return pJanela;
}

void ger::Gerenciador_Grafico::desenharEnte(Ente *pE){
    if(pE){pE->desenhar();}
}
