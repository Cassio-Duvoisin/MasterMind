#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "resposta.h"
#include <random>
#include <memory>

namespace trabalho
{
    class Tabuleiro
    {
        // VARIÁVEIS PRIVADAS:
        Sequencia mestre;
        std::vector<Sequencia> chutes;
        std::vector<Resposta> resultados;
        long unsigned n_cores;
        long unsigned tam;
        long unsigned palpites;
        long unsigned turno;
        bool cores_rep;
        long unsigned dificuldade;

        // MÉTODOS PRIVADOS:
        long unsigned numero_rand(long unsigned ncores);
        void gera_senha_rand();
        void inicia_rod();
        void compara();

    public:
        // MÉTODOS PÚBLICOS:
        void made_by();
        long unsigned get_palpites() const;
        bool get_cores_rep() const;
        long unsigned get_turno() const;
        long unsigned get_tam() const;
        long unsigned get_n_cores() const;
        void set_palpites(long unsigned palpites_);
        void set_cores_rep(bool cores_rep_);
        void set_tam(long unsigned tam_);
        void set_n_cores(long unsigned n_cores_);
        void set_turno(long unsigned turno_);
        void set_dificuldade(long unsigned dif);
        void imprime_tab();
        void imprime_cores_tab();
        void insere_bolas_no_mestre(long unsigned posi[]);
        void reseta_mestre();
        void inicia_dif(long unsigned n_cores_, long unsigned tam_, long unsigned palpites_, bool cores_rep_);
        bool rodada();
        bool repetiu() const;
    };
}

#endif