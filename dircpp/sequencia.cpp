#include "sequencia.h"

namespace trabalho
{
    // CONSTRUTORES:
    // METODOS:
    void Sequencia::imprime_cores(long unsigned n_cores_)
    {
        for (long unsigned i = 0; i < (n_cores_); i++)
            std::cout << i << ". " << cores[i] << "\n";
    }

    long unsigned Sequencia::get_posi_cor(std::string cor)
    {
        for (long unsigned i = 0; i < cores.size(); i++)
            if (cores[i] == cor)
                return i;
        return 20000;
    }

    std::string Sequencia::get_cor(long unsigned posi) const
    {
        return cores[posi];
    }

    std::string Sequencia::get_bolas(long unsigned posi) const
    {
        return bolas[posi];
    }

    void Sequencia::insere_bolas(std::string cor)
    {
        bolas.push_back(cor);
    }

    void Sequencia::tira_bolas()
    {
        for (int i = static_cast<int>(bolas.size()); i > 0; i--)
        {
            bolas.pop_back();
        }
    }

    bool Sequencia::operator==(const Sequencia &seq)
    {
        if (this->bolas.size() != seq.bolas.size())
            return false;
        for (long unsigned i = 0; i < this->bolas.size(); i++)
            if (this->bolas[i] != seq.bolas[i])
                return false;
        return true;
    }
}