#include "Jogo.h"
#include "Ente.h"
#include "Entidades/Entidade.h"
#include "Entidades/Goblin.h"
#include "Entidades/Plataforma.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Input.h"
#include "Entidades/Jogador.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo()
    : gerGrafico(ger::Gerenciador_Grafico::getInstancia())
    , gerEventos(ger::Gerenciador_Eventos::getInstancia())
    , gerColisoes(ger::Gerenciador_Colisoes::getInstancia())
    , listaEntidades()
{
    srand(time(NULL));
    Ente::setPGG(gerGrafico);

    inicializaEntidades();

    executar();
}

Jogo::~Jogo() {
    listaEntidades.limpar();
    
    jogador = nullptr;
    gerGrafico = nullptr;
    gerEventos = nullptr;
    gerColisoes = nullptr;
}

void Jogo::inicializaEntidades() {
    jogador = new ent::pers::Jogador (sf::Vector2f(WIDTH/2.0, HEIGHT/2.0),sf::Vector2f(1.7f, 1.7f));
    jogador->setTextura("Rogue-Jump");
    jogador->setVelocidade(sf::Vector2f(600.f, 600.f));

    /* Inclui jogador nos gerenciadores */
    gerEventos->setJogador(jogador);
    gerColisoes->setJogador(jogador);
    ger::Gerenciador_Input::getInstancia()->setJogador(jogador);

    /* Criação do Goblin */
    ent::pers::Goblin* goblin = new ent::pers::Goblin(sf::Vector2f(WIDTH/2.0+100.f, HEIGHT/2.0),sf::Vector2f(1.7f, 1.7f), jogador);
    goblin->setTextura("Goblin");
    goblin->setVelocidade(sf::Vector2f (350.f, 350.f));

    /* Criação da Plataforma */
    ent::obs::Plataforma* obstaculo = new ent::obs::Plataforma(sf::Vector2f(WIDTH/2.0, HEIGHT/2.0+250.f), sf::Vector2f(1.7f, 1.7f), false, 50);
    obstaculo->setTextura("Grass0001");

    ent::obs::Plataforma* obstaculo2 = new ent::obs::Plataforma(sf::Vector2f(WIDTH/2.0+obstaculo->getTamanho().x, HEIGHT/2.0+250.f), sf::Vector2f(1.7f, 1.7f), false, 50);
    obstaculo2->setTextura("Grass0001");

    /* Inclui as entidades no Ger. Colisões e na Lista de Entidades*/
    gerColisoes->incluirInimigo(static_cast<ent::pers::Inimigo*>(goblin));
    gerColisoes->incluirObstaculo(static_cast<ent::obs::Obstaculo*>(obstaculo));
    gerColisoes->incluirObstaculo(static_cast<ent::obs::Obstaculo*>(obstaculo2));

    listaEntidades.incluir(static_cast<ent::Entidade*>(obstaculo));
    listaEntidades.incluir(static_cast<ent::Entidade*>(obstaculo2));
    listaEntidades.incluir(static_cast<ent::Entidade*>(jogador));
    listaEntidades.incluir(static_cast<ent::Entidade*>(goblin));
}

void Jogo::atualizaEntidades() {
    listaEntidades.percorrer();
}

void Jogo::executar() {
    sf::Texture* backgroundTexture;
    backgroundTexture = gerGrafico->getTextura("Forest");
    
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(*backgroundTexture);

    sf::Vector2u textureSize = backgroundTexture->getSize();
    sf::Vector2u windowSize = gerGrafico->getJanela()->getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );

    while (gerGrafico->getJanelaAberta()) {
        gerEventos->gerenciar(); // Gerencia os eventos

        gerGrafico->limpaJanela(); // Limpa a janela

        gerGrafico->getJanela()->setView(gerGrafico->getJanela()->getDefaultView());
        gerGrafico->getJanela()->draw(backgroundSprite);
        
        gerGrafico->getJanela()->setView(gerGrafico->getVista());
        atualizaEntidades(); // Atualiza e Desenha as Entidades

        gerColisoes->executar(); // Detecta as colisões

        gerGrafico->centralizarVista(jogador); // Centraliza o campo de visão no jogador
        gerGrafico->updateDeltaTime();

        gerGrafico->display(); // Exibe a janela
    }
}
