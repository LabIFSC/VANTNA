#include "Arduino.h"

#define MENU_OPCOES_N 6

class Menu
{  
    Option opcoes[MENU_OPCOES_N];
};

class Option
{
    String nome;
    void* acao;
};

// void enviar_coords() { ... };

// Option enviar_coordenadas = { "Enviar coordenadas", enviar_coords }

// Options m_principal_opts[6] = { enviar_coordenadas };
// Menu principal = { opcoes = m_principal_opts };

// principal.opcoes[0] -> enviar_coords

// Opcoes do menu principal
    // 1 - Executar missão
    // 2 - Missão
        // - Exibir dados da missão
        // - Adicionar coordenadas (latitude, longitude)
        // - Voltar
        // Melhoria: Mudar a ordem das coordenadas
    // 3 - Configurar