#include "Controle/Texto_Input.h"
#include "Gerenciadores/Gerenciador_Input.h"
controle::Texto_Input::Texto_Input():
Observador(textoInput, ger::Gerenciador_Input::getInstancia())
,texto("")
, bufferTime(0.1f)
{
    mapaTeclas.clear();
    limpar();
    criarMapa();
}

controle::Texto_Input::~Texto_Input()
{
    limpar();
    mapaTeclas.clear();
}

void controle::Texto_Input::notificarApertada(sf::Keyboard::Key tecla)
{
    if(clock.getElapsedTime().asSeconds() >= bufferTime){
        if(ativo){
            auto it = mapaTeclas.find(tecla);
        if (it != mapaTeclas.end() && it->second)
            it->second(true);
        }
        clock.restart();
    }
}

void controle::Texto_Input::notificarSoltada(sf::Keyboard::Key tecla)
{
    if(clock.getElapsedTime().asSeconds() >= bufferTime + 0.1f){
        if(ativo){
            auto it = mapaTeclas.find(tecla);
            if (it != mapaTeclas.end() && it->second)
                it->second(false);
        }
        clock.restart();
    }
}

std::string controle::Texto_Input::getTexto() const
{
    return texto;
}

void controle::Texto_Input::criarMapa()
{
for (int i = static_cast<int>(sf::Keyboard::Key::A); i <= static_cast<int>(sf::Keyboard::Key::Z); i++) {
    int teclaAtual = i; // Criar variável local para evitar problemas com referência fora do loop
    incluir_tecla(static_cast<sf::Keyboard::Key>(i), [this, teclaAtual](bool pressionado) {
        if(texto.size() < 23)
            texto += static_cast<char>('a' + (teclaAtual - static_cast<int>(sf::Keyboard::Key::A)));
    });
}


    incluir_tecla(sf::Keyboard::Key::Space, [this](bool pressionado){
        if(texto.size() < 23)
            texto += " ";
    });

    incluir_tecla(sf::Keyboard::BackSpace, [this](bool pressionado){
        if(texto.size() > 0){
            texto.pop_back();
        }
    });
}

void controle::Texto_Input::limpar()
{
    texto = "";
}
