#ifndef RESPOSTA_H
#define RESPOSTA_H

#include "sequencia.h"

namespace trabalho
{
    class Resposta : public Sequencia
    {
        std::vector<std::string> cores_resposta = {"cinza ", "branco", "preto "};

    public:
        // METODO:
        void preenche_cinza(long unsigned tam_);
        void troca_bola(long unsigned posi_, long unsigned posi_cores_resp);
        // METODOS REDEFINIDOS:
        void imprime_cores(long unsigned n_cores);
        std::string get_cor(long unsigned posi) const;
        long unsigned get_posi_cor(std::string cor);
    };
}
#endif