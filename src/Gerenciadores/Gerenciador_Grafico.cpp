#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Ente.h"
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
    : pJanela(nullptr)
    , clock()
    , mapaTexturas()
    , vista()
    , fonteRetroGaming(nullptr)
{
    setVideoMode();
    setJanela();
    setFonte();

    /*Forest Textures*/
    carregarTextura("/assets/images/Backgrounds/Forest.png", "Forest");
    carregarTextura("/assets/images/Tiles/Ground_grass_0001_tile.png", "Grass1");
    carregarTextura("/assets/images/Tiles/Ground_grass_0002_tile.png", "Grass2");
    carregarTextura("/assets/images/Tiles/Ground_grass_0000_tile.png", "Grass0");
    carregarTextura("/assets/images/Tiles/Ground_grass_0003_tile.png", "Grass3");
    carregarTextura("/assets/images/Tiles/Ground_grass_0004_tile.png", "Grass4");
    carregarTextura("/assets/images/Tiles/Ground_grass_0005_tile.png", "Grass5");
    carregarTextura("/assets/images/Tiles/floating-platform.png", "Grass500");

    /*Castle Textures*/
    carregarTextura("/assets/images/Backgrounds/Castle.png", "Castle");
    carregarTextura("/assets/images/Tiles-castle/tile13.png", "Brick1");
    carregarTextura("/assets/images/Tiles-castle/tile8.png", "Brick2");
    carregarTextura("/assets/images/Tiles-castle/tile9.png", "Brick3");
    carregarTextura("/assets/images/Tiles-castle/tile12.png", "Brick4");
    carregarTextura("/assets/images/Tiles-castle/floating-platform.png", "Brick500");

    /* Rogue Textures */
    carregarTextura("/assets/images/Rogue/rogue-stand.png", "Rogue-Stand");
    carregarTextura("/assets/images/Rogue/rogue-walk.png", "Rogue-Walk");
    carregarTextura("/assets/images/Rogue/rogue-run.png", "Rogue-Run");
    carregarTextura("/assets/images/Rogue/rogue-jump.png", "Rogue-Jump");
    carregarTextura("/assets/images/Rogue/rogue-attack.png", "Rogue-Attack");
    carregarTextura("/assets/images/Rogue/rogue-walk-attack.png", "Rogue-Walk-Attack");
    carregarTextura("/assets/images/Rogue/rogue-run-attack.png", "Rogue-Run-Attack");
    carregarTextura("/assets/images/Rogue/rogue-hurt.png", "Rogue-Hurt");
    carregarTextura("/assets/images/Rogue/rogue-death.png", "Rogue-Death");
    carregarTextura("/assets/images/Rogue/rogue-idle.png", "Rogue-Idle");

    /* Rogue 2 Textures */
    carregarTextura("/assets/images/Rogue2/rogue-stand.png", "Rogue-Stand2");
    carregarTextura("/assets/images/Rogue2/rogue-walk.png", "Rogue-Walk2");
    carregarTextura("/assets/images/Rogue2/rogue-run.png", "Rogue-Run2");
    carregarTextura("/assets/images/Rogue2/rogue-jump.png", "Rogue-Jump2");
    carregarTextura("/assets/images/Rogue2/rogue-attack.png", "Rogue-Attack2");
    carregarTextura("/assets/images/Rogue2/rogue-walk-attack.png", "Rogue-Walk-Attack2");
    carregarTextura("/assets/images/Rogue2/rogue-run-attack.png", "Rogue-Run-Attack2");
    carregarTextura("/assets/images/Rogue2/rogue-hurt.png", "Rogue-Hurt2");
    carregarTextura("/assets/images/Rogue2/rogue-death.png", "Rogue-Death2");
    carregarTextura("/assets/images/Rogue2/rogue-idle.png", "Rogue-Idle2");

    /* Goblin Textures */
    carregarTextura("/assets/images/Goblin/goblin-idle.png", "Goblin-Idle");
    carregarTextura("/assets/images/Goblin/goblin-walk.png", "Goblin-Walk");
    carregarTextura("/assets/images/Goblin/goblin-hurt.png", "Goblin-Hurt");
    carregarTextura("/assets/images/Goblin/goblin-death.png", "Goblin-Death");

    /* Spider Textures */
    carregarTextura("/assets/images/Spider/spider-idle.png", "Spider-Idle");
    carregarTextura("/assets/images/Spider/spider-hurt.png", "Spider-Hurt");
    carregarTextura("/assets/images/Spider/spider-attack.png", "Spider-Attack");
    carregarTextura("/assets/images/Spider/spider-walk.png", "Spider-Walk");
    carregarTextura("/assets/images/Spider/spider-death.png", "Spider-Death");

    carregarTextura("/assets/images/General/web.png", "Web");

    /* Knight Textures */
    carregarTextura("/assets/images/Knight/knight-walk.png", "Knight-Walk");
    carregarTextura("/assets/images/Knight/knight-attack.png", "Knight-Attack");
    carregarTextura("/assets/images/Knight/knight-death.png", "Knight-Death");
    carregarTextura("/assets/images/Knight/knight-hurt.png", "Knight-Hurt");
    carregarTextura("/assets/images/Knight/knight-idle.png", "Knight-Idle");

    /*GUI Textures*/
    carregarTextura("/assets/images/User-interface/leaderboard-button.png", "Leaderboard-Button");
    carregarTextura("/assets/images/User-interface/main-menu-bg.png", "Main-Menu-Bg");
    carregarTextura("/assets/images/User-interface/yellow-button.png", "Yellow-Button");
    carregarTextura("/assets/images/User-interface/brown-button.png", "Brown-Button");
    carregarTextura("/assets/images/User-interface/menu_bg.png", "Menu-bg");
    carregarTextura("/assets/images/User-interface/pause.png", "Pause");
    carregarTextura("/assets/images/User-interface/heart.png", "Heart");
    carregarTextura("/assets/images/User-interface/Leaderboard-bg.png", "Leaderboard-Bg");

    /* Door Textures */
    carregarTextura("/assets/images/Door/door-closed.png", "Door-Closed");
    carregarTextura("/assets/images/Door/door-opening.png", "Door-Opening");
    carregarTextura("/assets/images/Door/door-opened.png", "Door-Opened");

    carregarTextura("/assets/images/General/box.png", "Box");
    carregarTextura("/assets/images/General/big_spikes1.png", "Spikes");
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
    std::map<std::string, sf::Texture*>::iterator it = mapaTexturas.begin();
    while(it != mapaTexturas.end()){
        delete it->second;
    }
    delete pJanela;
    pJanela = nullptr;
    delete fonteRetroGaming;
    fonteRetroGaming = nullptr;
}

// Inicializando DeltaTime
float Gerenciador_Grafico::deltaTime(0);

/* Video Mode (Resolução) */

void Gerenciador_Grafico::setVideoMode() {
    videoMode.height = HEIGHT;
    videoMode.width = WIDTH;
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

void Gerenciador_Grafico::centralizarVista(ent::Entidade *e, float tamanhoFase) {
    vista.setSize((sf::Vector2f(static_cast<float>(WIDTH), static_cast<float>(HEIGHT))));
    sf::Vector2i tamanho = e->getCorpo().getSize();

    sf::Vector2f posicao;
    posicao.y = HEIGHT/2.f - 300.f;

    posicao.x = e->getPosition().x;

    if (tamanho.x > 0)
        posicao.x += tamanho.x / 2.f;

    else
        posicao.x -= tamanho.x / 2.f;

    float limiteEsquerdo = 12.f + getVista().getSize().x / 2.f;
    float limiteDireito = tamanhoFase - getVista().getSize().x / 2.f;

    if (posicao.x < limiteEsquerdo)
        posicao.x = limiteEsquerdo;

    if (posicao.x > limiteDireito)
        posicao.x = limiteDireito;
    
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
sf::Texture* Gerenciador_Grafico::carregarTextura(std::string caminhoImagem, std::string nomeImagem) {
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

sf::Texture* Gerenciador_Grafico::getTextura(std::string nomeImagem) {
    if (mapaTexturas.find(nomeImagem) != mapaTexturas.end()) {
        return mapaTexturas[nomeImagem];
        std::cout<<"potato\n";
    }

    std::cerr << "ERRO ao achar imagem: " << nomeImagem << '\n';
    return nullptr;
    exit(1);
}

void Gerenciador_Grafico::setFonte()
{
    fonteRetroGaming = new sf::Font();
    std::string caminho = PROJECT_ROOT;
    caminho += "/assets/fonts/Retro Gaming.ttf";
    if (!fonteRetroGaming->loadFromFile(caminho)) {
        std::cerr << "Erro ao carregar a fonte!\n";
    }
}
sf::Font* Gerenciador_Grafico::getFonte() const
{
    if(fonteRetroGaming){
        return (fonteRetroGaming);
    }else{std::cerr << "Fonte nao alocada corretamente\n";
        return nullptr;
     }
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

void ger::Gerenciador_Grafico::desenharSprite(sf::Sprite *pS) const
{
    if(pS){
        pJanela->draw(*pS);
    }
}

void ger::Gerenciador_Grafico::desenharTexto(sf::Text* text) const
{
    pJanela->draw(*text);
}
