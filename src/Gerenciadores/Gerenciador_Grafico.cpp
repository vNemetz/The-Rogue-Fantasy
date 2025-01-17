#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Entidades/Entidade.h"
#include <iostream>
#include <string.h>

namespace ger{
/* Singleton - Padrão de Projeto */
Gerenciador_Grafico* Gerenciador_Grafico::instancia(nullptr);

Gerenciador_Grafico* Gerenciador_Grafico::getInstancia() {
    if(instancia == nullptr){
        instancia = new Gerenciador_Grafico();
    }
    return instancia;
}

Gerenciador_Grafico::Gerenciador_Grafico()
    : pJanela(NULL)
    , clock()
    , mapaTexturas()
    , vista()
{
    setVideoMode();
    setJanela();

    carregarTextura("/assets/images/Backgrounds/Forest.png", "Forest");
    carregarTextura("/assets/images/Tiles/Ground_grass_0001_tile.png", "Grass0001");

    /* Rogue Textures */
    carregarTextura("/assets/images/Rogue/rogue-stand.png", "Rogue-Stand");
    carregarTextura("/assets/images/Rogue/rogue-walk.png", "Rogue-Walk");
    carregarTextura("/assets/images/Rogue/rogue-run.png", "Rogue-Run");
    carregarTextura("/assets/images/Rogue/rogue-jump.png", "Rogue-Jump");
    carregarTextura("/assets/images/Rogue/rogue-attack.png", "Rogue-Attack");
    carregarTextura("/assets/images/Rogue/rogue-hurt.png", "Rogue-Hurt");
    carregarTextura("/assets/images/Rogue/rogue-idle.png", "Rogue-Idle");

    /* Goblin Textures */
    carregarTextura("/assets/images/Goblin/goblin-idle.png", "Goblin-Idle");
    carregarTextura("/assets/images/Goblin/goblin-walk.png", "Goblin-Walk");
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
    std::map<std::string, sf::Texture*>::iterator it = mapaTexturas.begin();
    while(it != mapaTexturas.end()){
        delete it->second;
    }
    delete pJanela;
    pJanela = NULL;
}

// Inicializando DeltaTime
float Gerenciador_Grafico::deltaTime(0);

/* Video Mode (Resolução) */

void Gerenciador_Grafico::setVideoMode() {
    videoMode.getDesktopMode();
}

/* Janela */

void Gerenciador_Grafico::setJanela() {
    pJanela = new sf::RenderWindow(videoMode, "oJogo", sf::Style::Fullscreen);
}

bool Gerenciador_Grafico::getJanelaAberta() const {
    return pJanela->isOpen();
}

sf::RenderWindow* Gerenciador_Grafico::getJanela() const {
    if(pJanela) {return pJanela;}
    return NULL;
}

sf::Vector2u Gerenciador_Grafico::getTamanhoJanela() const {
    return pJanela->getSize();
}

void Gerenciador_Grafico::limpaJanela() {
    pJanela->clear(sf::Color::Black);
}

void Gerenciador_Grafico::fechaJanela(){
    pJanela->close();
}

bool Gerenciador_Grafico::pesquisaEventoJanela(sf::Event& ev) {
    return(pJanela->pollEvent(ev));
}

void Gerenciador_Grafico::display() {
    pJanela->display();
}

/* Vista */

void Gerenciador_Grafico::setVista(float x) {
    if(pJanela) {
        vista.setCenter (x, static_cast<float>(HEIGHT/2.f));
        vista.setSize(sf::Vector2f(WIDTH, HEIGHT));
    }
}

sf::View Gerenciador_Grafico::getVista() const {
    return vista;
}

void Gerenciador_Grafico::setTamanhoVista(sf::Vector2f tam) {
    vista.setSize(tam);
}

void Gerenciador_Grafico::setCentroVista(sf::Vector2f pos) {
    vista.setCenter(pos);
    pJanela->setView(vista);
}

void Gerenciador_Grafico::centralizarVista(ent::Entidade *e) {
    sf::Vector2i tamanho = e->getCorpo().getSize();

    sf::Vector2f posicao;
    posicao.y = getVista().getCenter().y;

    posicao.x = e->getPosition().x;

    if (tamanho.x > 0)
        posicao.x += tamanho.x / 2.f;

    else
        posicao.x -= tamanho.x / 2.f;
    
    vista.setCenter(posicao);
    pJanela->setView(vista);
}

/* Clock */

void Gerenciador_Grafico::updateDeltaTime() {
    deltaTime = clock.restart().asSeconds();
}

float Gerenciador_Grafico::getDeltaTime() {
    return deltaTime;
}

float Gerenciador_Grafico::reiniciarClock() {
    return(clock.restart().asSeconds());
}

/* Texturas */
sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminhoImagem, const char* nomeImagem) {
    std::string caminho = PROJECT_ROOT;
    caminho += caminhoImagem;

    if (mapaTexturas.find(nomeImagem) != mapaTexturas.end()) {
        return mapaTexturas[nomeImagem];
    }
    
    sf::Texture* novaTextura = new sf::Texture();
    if (!novaTextura->loadFromFile(caminho)) {
            std::cerr << "ERRO ao carregar arquivo: " << caminho << "\n";
            exit(1);
    }

    mapaTexturas.insert(std::pair<std::string, sf::Texture*>(nomeImagem, novaTextura));
    return novaTextura;
}

sf::Texture* Gerenciador_Grafico::getTextura(const char* nomeImagem) {
    if (mapaTexturas.find(nomeImagem) != mapaTexturas.end()) {
        return mapaTexturas[nomeImagem];
    }
    
    std::cerr << "ERRO ao achar imagem: " << nomeImagem << '\n';
    exit(1);
}

/* Renderização */
void Gerenciador_Grafico::desenharEntidade(ent::Entidade *pE) const {
    if(pE) {
        pJanela->draw(*pE->getSprite());
    }
}

void Gerenciador_Grafico::desenhar(sf::RectangleShape *corpo) const {
    pJanela->draw(*corpo);
}
}