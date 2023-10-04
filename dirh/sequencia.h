#ifndef SEQUENCIA_H
#define SEQUENCIA_H

#include <iostream>
#include <vector>

namespace trabalho
{
    class Sequencia
    {
        // VARIAVEIS:
    protected:
        std::vector<std::string> cores = {"vermelho", "  azul  ", " verde  ", "amarelo ", "  roxo  ", "laranja ", "  rosa  ", " ciano  ", " marrom ", " bordo  "};
        std::vector<std::string> bolas;

    public:
        // METODOS:
        virtual void imprime_cores(long unsigned n_cores);
        virtual long unsigned get_posi_cor(std::string cor);
        virtual std::string get_cor(long unsigned posi) const;
        std::string get_bolas(long unsigned posi) const;
        void insere_bolas(std::string cor);
        void tira_bolas();
        bool operator==(const Sequencia &seq);
    };
}

#endif