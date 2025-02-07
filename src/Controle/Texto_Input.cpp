#include "Controle/Texto_Input.h"

controle::Texto_Input::Texto_Input()
{
    mapaTeclas.clear();
    limpar();
}

controle::Texto_Input::~Texto_Input()
{
    limpar();
    mapaTeclas.clear();
}

void controle::Texto_Input::notificarApertada(sf::Keyboard::Key tecla)
{
    if(ativo){
        auto it = mapaTeclas.find(tecla);
        
        // Procura a tecla no mapa, se achar executa a função como verdadeira
        if (it != mapaTeclas.end())
            it->second(true);
    }
}

void controle::Texto_Input::notificarSoltada(sf::Keyboard::Key tecla)
{
    if(ativo){
        auto it = mapaTeclas.find(tecla);
        
        // Procura a tecla no mapa, se achar executa a função como falsa
        if (it != mapaTeclas.end())
            it->second(false);
    }
}

std::string controle::Texto_Input::getTexto() const
{
    return texto;
}

void controle::Texto_Input::criarMapa()
{
    for(int i = static_cast<int>(sf::Keyboard::Key::A); i < static_cast<int>(sf::Keyboard::Key::Z); i++){
        incluir_tecla(static_cast<sf::Keyboard::Key> (i), [this, i](bool pressionado){
            texto += static_cast<char>('a' + (i - static_cast<int>(sf::Keyboard::Key::A)));
        });
    }
    
    incluir_tecla(sf::Keyboard::Key::Space, [this](bool pressionado){
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
