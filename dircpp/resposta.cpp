#include "resposta.h"

namespace trabalho
{
    // MÉTODOS:
    void Resposta::preenche_cinza(long unsigned tam_)
    {
        for (long unsigned i = 0; i < tam_; i++)
            bolas.push_back(cores_resposta[0]);
    }

    void Resposta::troca_bola(long unsigned posi_, long unsigned posi_cores_resp)
    {
        std::vector<std::string>::iterator it = bolas.begin() + static_cast<long>(posi_);
        bolas.erase(it);
        bolas.insert(it, cores_resposta[posi_cores_resp]);
    }

    void Resposta::imprime_cores(long unsigned n_cores)
    {
        for (long unsigned i = 0; i < 3; i++)
            std::cout << i << ". " << cores_resposta[i] << "\n";
    }

    std::string Resposta::get_cor(long unsigned posi) const
    {
        return cores_resposta[posi];
    }

    long unsigned Resposta::get_posi_cor(std::string cor)
    {
        for (long unsigned i = 0; i < cores_resposta.size(); i++)
            if (cores_resposta[i] == cor)
                return i;
        return 20000;
    }
}