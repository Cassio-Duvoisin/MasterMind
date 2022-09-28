#include "jogo.h"

namespace trabalho
{
    // CONSTRUTORES:
    Jogo::Jogo()
    {
        std::shared_ptr<Tabuleiro> t(new Tabuleiro);
        tab = t;
    }
    // MÉTODOS PRIVADOS:
    void Jogo::personalizado(int jogadores)
    {
        using namespace std;
        int a = -1;
        long unsigned temp, temp2;
        if (jogadores == 1)
            tab->made_by();
        for (;;)
        {
            cout << "\nPersonalize seu nivel de dificuldade: \n"
                 << "Numero de Palpites Maximo (4-10):";
            cin >> temp;
            tab->set_palpites(temp);
            cout << "É permitido cores repetidas? (1 para sim - 0 para nao):";
            cin >> a;
            cout << "Numero de cores maxima para a sequencia (4-10):";
            cin >> temp;
            tab->set_n_cores(temp);
            cout << "Tamanho da Sequencia (4-6):";
            cin >> temp2;
            tab->set_tam(temp2);
            if (a == 0 && temp < temp2)
                cout << "\nO numero de cores nao pode ser menor que o tamanho caso nao seja permitido cores repitidas!\n";
            else if (tab->get_palpites() < 4 || tab->get_palpites() > 10 || a > 1 || a < 0 || tab->get_n_cores() < 4 || tab->get_n_cores() > 10 || tab->get_tam() < 4 || tab->get_tam() > 6)
                cout << "\nAte isso voce erra! Faça de novo: \n";
            else
            {
                tab->set_cores_rep(a);
                break;
            }
        }
        if (jogadores == 1)
            tab->inicia_dif(tab->get_n_cores(), tab->get_tam(), tab->get_palpites(), a);
    }

    void Jogo::cria_senha_manual()
    {
        using namespace std;
        long unsigned posi_cores[tab->get_tam()];
        int a;
        for (long unsigned i = 0; i < tab->get_tam(); i++)
        {
            cin >> a;
            if (a < 0 || a > static_cast<int>(tab->get_n_cores()))
            {
                cout << "Voce e burro e nao escolheu uma cor possivel, escolha de novo.";
                i--;
            }
            posi_cores[i] = static_cast<long unsigned>(a);
        }
        tab->insere_bolas_no_mestre(posi_cores);
    }

    void Jogo::reset_jogo()
    {
        std::shared_ptr<Tabuleiro> tab_novo(new Tabuleiro);
        tab = tab_novo;
    }

    // MÉTODOS PÚBLICOS:
    void Jogo::menu_inicial()
    {
        using namespace std;
        long unsigned n_jog;
        tab->made_by();
        cout << "Bem Vindo ao MaterMind, escolha o numero de jogadores (1 ou 2): ";
        cin >> n_jog;
        while (n_jog > 2 || n_jog < 1)
        {
            cout << "Numero de Jogadores inválido (1 ou 2):" << endl;
            cout << "Escolha o numero de jogadores de novo(1 ou 2):";
            cin >> n_jog;
        }
        if (n_jog == 1)
        {
            long unsigned dif = 0;
            tab->made_by();
            while (dif < 1 || dif > 5)
            {
                cout << "Agora insira o nivel de dificuldade desejado: \n"
                     << "1 - Facil\n"
                     << "2 - Medio\n"
                     << "3 - Dificil\n"
                     << "4 - Impossivel\n"
                     << "5 - Personalizado\n";
                cin >> dif;
                if (dif < 1 || dif > 5)
                    cout << "\nDificuldade nao aceita! \n\n";
            }
            start_game_solo(dif);
        }
        if (n_jog == 2)
        {
            start_game_multiplayer();
        }
        tab->made_by();
        roda_jogo();
    }

    void Jogo::start_game_solo(long unsigned dif)
    {
        using namespace std;
        tab->set_turno(0);
        tab->set_dificuldade(dif);
        switch (dif)
        {
        case 1:
            tab->inicia_dif(4, 4, 10, false);
            break;
        case 2:
            tab->inicia_dif(6, 5, 8, false);
            break;
        case 3:
            tab->inicia_dif(8, 6, 6, true);
            break;
        case 4:
            tab->inicia_dif(10, 6, 4, true);
            break;
        case 5:
        {
            personalizado(1);
            break;
        }
        default:
            cout << "escolheu errado seu burro";
            break;
        }
    }

    void Jogo::start_game_multiplayer()
    {
        using namespace std;
        tab->set_turno(0);
        long unsigned a;
        tab->made_by();
        cout << "Bem vindos ao modo multiplayer!";
        personalizado(2);
        cout << "\nCodemaker, coloque a sequencia desejada e certifique-se de que o codebreaker nao espie!\n";
        tab->imprime_cores_tab();
        cout << "Por favor insira " << tab->get_tam() << " cores desejadas:\n";
        cria_senha_manual();
        if (tab->get_cores_rep() == 0)
        {
            while (tab->repetiu() == true)
            {
                cout << "A sua sequencia possui cores repetidos, por favor insira uma nova sequencia!\n";
                tab->reseta_mestre();
                cria_senha_manual();
            }
        }
        tab->made_by();
        cout << "Codebreaker, Agora e sua vez!!!\n";
    }

    void Jogo::roda_jogo()
    {
        int p;
        while (tab->get_turno() < (tab->get_palpites()))
        {
            if (tab->rodada() == true)
            {
                std::cout << "Fim de jogo, Voce Ganhou!\nGostaria de jogar novamente? (1 para sim - 0 para nao)";
                do
                {
                    std::cin >> p;
                    if (p > 1 || p < 0)
                        std::cout << "Nao entendi, insira de novo!";
                } while (p > 1 || p < 0);
                if (p == 1)
                {
                    reset_jogo();
                    menu_inicial();
                }
                else
                    std::cout << "Obrigado por jogar, ate a proxima!\n";
                return;
            }
            tab->made_by();
        }

        std::cout << "Fim de jogo, Voce Perdeu!\nGostaria de jogar novamente? (1 para sim - 0 para nao)";
        do
        {
            std::cin >> p;
            if (p > 1 || p < 0)
                std::cout << "Nao entendi, insira de novo!";
        } while (p > 1 || p < 0);
        if (p == 1)
        {
            reset_jogo();
            menu_inicial();
        }
        else
            std::cout << "Obrigado por jogar, ate a proxima!\n";
        return;
    }
}