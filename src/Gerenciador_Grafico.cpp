#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include <string.h>
namespace ger{

Gerenciador_Grafico* Gerenciador_Grafico::instancia(NULL);

Gerenciador_Grafico* Gerenciador_Grafico::getInstancia() {
    if(instancia == NULL){
        instancia = new Gerenciador_Grafico();
    }
    return instancia;
}

Gerenciador_Grafico::Gerenciador_Grafico() : pJanela(NULL), clock(), mapaTexturas(), vista(){
    setVideoMode();
    setJanela();
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
    std::map<const char*, sf::Texture*>::iterator it = mapaTexturas.begin();
    while(it != mapaTexturas.end()){
        delete it->second;
    }
    delete pJanela;
    pJanela = NULL;
}
//Inicializando DeltaTime
float Gerenciador_Grafico::deltaTime(0);

//VideoMode (Resolução)
void Gerenciador_Grafico::setVideoMode(){
    videoMode.height = HEIGHT;
    videoMode.width = WIDTH;
}

//Janela
void Gerenciador_Grafico::setJanela(){
    pJanela = new sf::RenderWindow(videoMode, "oJogo", sf::Style::Resize | sf::Style::Default);
}

sf::RenderWindow *Gerenciador_Grafico::getJanela() const{
    if(pJanela){return pJanela;}
    return NULL;
}

sf::Vector2u Gerenciador_Grafico::getTamanhoJanela() const{
    return pJanela->getSize();
}

void Gerenciador_Grafico::limpaJanela(){
    pJanela->clear(sf::Color::Yellow);
}

void Gerenciador_Grafico::fechaJanela(){
    pJanela->close();
}

bool Gerenciador_Grafico::pesquisaEventoJanela(sf::Event& ev){
    return(pJanela->pollEvent(ev));
}

//Vista
void Gerenciador_Grafico::setVista(float x){
    if(pJanela){
        vista.setCenter (x, static_cast<float>(HEIGHT/2));
        vista.setSize(sf::Vector2f(WIDTH, HEIGHT));
    }
}

void Gerenciador_Grafico::setTamanhoVista(sf::Vector2f tam){
    vista.setSize(tam);
}

void Gerenciador_Grafico::setCentroVista(sf::Vector2f pos){
    vista.setCenter(pos);
    pJanela->setView(vista);
}

sf::View Gerenciador_Grafico::getVista() const {
    return vista;
}

bool Gerenciador_Grafico::getJanelaAberta() const{
    return pJanela->isOpen();
}

void Gerenciador_Grafico::centralizarVista(Ente *e){
    vista.setCenter(e->getPosition().x, getVista().getCenter().y);
    pJanela->setView(vista);
}

void Gerenciador_Grafico::updateDeltaTime(){
    deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
}

//Texturas
sf::Texture*  Gerenciador_Grafico::carregarTextura( const char* caminho){
    std::map<const char*, sf::Texture*>::iterator it = mapaTexturas.begin();
    while(it != mapaTexturas.end()){
        if(!strcmp(it->first, caminho))
            return it->second;
        it++;

    }
    sf::Texture* novaTextura = new sf::Texture();
    if (!novaTextura->loadFromFile(caminho)) {
            std::cerr << "ERRO ao carregar arquivo" << caminho << "\n";
            exit(1);
    }
    mapaTexturas.insert(std::pair<const char*, sf::Texture*>(caminho, novaTextura));
    return novaTextura;
}

//Renderização
void Gerenciador_Grafico::desenharEnte(Ente *pE) const{
    if(pE){pE->desenhar();}
}
void Gerenciador_Grafico::desenhar(sf::RectangleShape *corpo) const{
    pJanela->draw(*corpo);
}
}