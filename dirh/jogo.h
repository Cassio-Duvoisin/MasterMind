#ifndef JOGO_H
#define JOGO_H

#include "tabuleiro.h"
#include <memory>

namespace trabalho
{
    class Jogo
    {
        // MÉTODOS PRIVADOS:
        std::shared_ptr<Tabuleiro> tab;
        void personalizado(int multi);
        void cria_senha_manual();
        void reset_jogo();

    public:
        // CONSTRUTORES:
        Jogo();

        // MÉTODOS PÚBLICOS:
        void menu_inicial();
        void start_game_solo(long unsigned dif);
        void start_game_multiplayer();
        void roda_jogo();
    };

}

#endif