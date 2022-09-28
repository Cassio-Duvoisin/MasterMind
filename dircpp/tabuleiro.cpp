#include "tabuleiro.h"

namespace trabalho
{
    // MÉTODOS PRIVADOS:
    long unsigned Tabuleiro::numero_rand(long unsigned ncores)
    {
        std::random_device r;
        std::uniform_int_distribution<long unsigned> uniform_dist(0, ncores - 1);
        return uniform_dist(r);
    }

    void Tabuleiro::gera_senha_rand()
    {
        long unsigned posi_cores[tam], i = 0;

        if (!cores_rep)
        {
            long unsigned count = 0;
            while (i < tam)
            {
                posi_cores[i] = numero_rand(n_cores);
                for (long unsigned j = 0; j < i; j++)
                    if (posi_cores[i] == posi_cores[j])
                        count++;
                if (!count)
                {
                    i++;
                }
                count = 0;
            }
        }
        else
        {
            while (i < tam)
            {
                posi_cores[i] = numero_rand(n_cores);
                i++;
            }
        }
        mestre.tira_bolas();
        for (long unsigned j = 0; j < tam; j++)
        {
            mestre.insere_bolas(mestre.get_cor(posi_cores[j]));
        }
    }

    void Tabuleiro::inicia_rod()
    {
        turno++;
        if (turno >= 2)
            imprime_tab();
        std::cout << "\nTurno: " << turno << "\n";
        mestre.imprime_cores(n_cores);

        long unsigned posi_cores[tam];
        Sequencia chute_atual;
        std::cout << "Escolha " << tam << " cores do chute na sequencia desejada:\n";
        for (long unsigned i = 0; i < tam; i++)
        {
            std::cin >> posi_cores[i];
            chute_atual.insere_bolas(chute_atual.get_cor(posi_cores[i]));
        }
        chutes.push_back(chute_atual);
    }
    void Tabuleiro::compara()
    {
        long unsigned rep[n_cores];
        for (long unsigned i = 0; i < n_cores; i++)
        {
            rep[i] = 0;
            for (long unsigned j = 0; j < tam; j++)
                if (mestre.get_cor(i) == mestre.get_bolas(j))
                    rep[i]++;
        }
        Resposta resposta_atual;
        resultados.push_back(resposta_atual);
        // preenche de cinza//
        resultados[turno - 1].preenche_cinza(tam);
        // coloca as pretas//
        for (long unsigned i = 0; i < tam; i++)
        {
            if (chutes[turno - 1].get_bolas(i) == mestre.get_bolas(i))
            {
                resultados[turno - 1].troca_bola(i, 2);
                rep[mestre.get_posi_cor(mestre.get_bolas(i))]--;
            }
        }
        // coloca as brancas//
        for (long unsigned i = 0; i < tam; i++)
        {
            for (long unsigned j = 0; j < tam; j++)
            {
                if (chutes[turno - 1].get_bolas(i) == mestre.get_bolas(j) && chutes[turno - 1].get_bolas(i) != mestre.get_bolas(i))
                {
                    if (rep[chutes[turno - 1].get_posi_cor(chutes[turno - 1].get_bolas(i))] > 0)
                        resultados[turno - 1].troca_bola(i, 1);
                }
            }
        }
    }

    // MÉTODOS PÚBLICOS:
    void Tabuleiro::made_by()
    {
        std::system("clear");
        std::cout << "Made by Cassio and Guilherme" << std::endl
                  << std::endl
                  << std::endl;
    }

    long unsigned Tabuleiro::get_palpites() const
    {
        return palpites;
    }
    bool Tabuleiro::get_cores_rep() const
    {
        return cores_rep;
    }

    long unsigned Tabuleiro::get_turno() const
    {
        return turno;
    }

    long unsigned Tabuleiro::get_tam() const
    {
        return tam;
    }

    long unsigned Tabuleiro::get_n_cores() const
    {
        return n_cores;
    }

    void Tabuleiro::set_palpites(long unsigned palpites_)
    {
        palpites = palpites_;
    }

    void Tabuleiro::set_cores_rep(bool cores_rep_)
    {
        cores_rep = cores_rep_;
    }

    void Tabuleiro::set_tam(long unsigned tam_)
    {
        tam = tam_;
    }

    void Tabuleiro::set_n_cores(long unsigned n_cores_)
    {
        n_cores = n_cores_;
    }

    void Tabuleiro::set_turno(long unsigned turno_)
    {
        turno = turno_;
    }

    void Tabuleiro::set_dificuldade(long unsigned dif)
    {
        dificuldade = dif;
    }

    void Tabuleiro::imprime_tab()
    {
        using namespace std;
        if (tam == 4)
            cout << "                 Palpites                                 Respostas\n";
        else if (tam == 5)
            cout << "                     Palpites                                          Respostas\n";
        else if (tam == 6)
            cout << "                         Palpites                                                    Respostas\n";
        for (long unsigned i = 0; i < turno - 1; i++)
        {
            cout << i + 1 << ")  ";
            for (long unsigned j = 0; j < tam; j++)
            {
                cout << chutes[i].get_bolas(j) << " ";
            }
            cout << "      ";
            for (long unsigned j = 0; j < tam; j++)
            {
                cout << resultados[i].get_bolas(j) << "   ";
            }
            cout << "\n";
        }
    }

    void Tabuleiro::imprime_cores_tab()
    {
        mestre.imprime_cores(n_cores);
    }

    void Tabuleiro::insere_bolas_no_mestre(long unsigned posi[])
    {
        for (long unsigned j = 0; j < tam; j++)
        {
            mestre.insere_bolas(mestre.get_cor(posi[j]));
        }
    }

    void Tabuleiro::reseta_mestre()
    {
        mestre.tira_bolas();
    }

    void Tabuleiro::inicia_dif(long unsigned n_cores_, long unsigned tam_, long unsigned palpites_, bool cores_rep_)
    {
        palpites = palpites_;
        cores_rep = cores_rep_;
        n_cores = n_cores_;
        tam = tam_;
        gera_senha_rand();
    }

    bool Tabuleiro::rodada()
    {
        inicia_rod();
        compara();
        if (chutes[turno - 1] == mestre)
            return true;
        else
            return false;
    }

    bool Tabuleiro::repetiu() const
    {
        for (long unsigned i = 0; i < tam; i++)
        {
            for (long unsigned j = 0; j < tam; j++)
            {
                if (i != j && mestre.get_bolas(i) == mestre.get_bolas(j))
                {
                    return true;
                }
            }
        }
        return false;
    }
}
