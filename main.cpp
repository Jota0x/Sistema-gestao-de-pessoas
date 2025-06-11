#include <iostream>
#include "data.hpp"
#include "pessoa.hpp"
using namespace std;



const int MAX = 100; // Constante global: tamanho físico do arranjo de pessoas
int TAM = 0;

int main()
{
    int opcao;

    Pessoa pessoa;

    do
    {
        printf("\n   --- Escolha uma opcao ---\n");
        printf("\n 0 --- Sair do programa ---\n");
        printf("\n 1 --- Cadastrar pessoa ---\n");
        printf("\n 2 --- Listar pessoa ---\n");
        printf("\n 3 --- Pesquisar por nome ---\n");
        printf("\n 4 --- Pesquisar por cpf ---\n");
        printf("\n 5 --- Excluir pessoa ---\n");
        printf("\n 6 --- Apagar todas as pessoas cadastradas ---\n");

        switch (opcao)
        {
        case 1:
            pessoa.cadastrarPessoa();

            break;

        case 2:
            pessoa.listarPessoa();

            break;

        case 3:
        {

            string nomePesquisa;
            cout << "Digite nome para pesquisar: ";
            getline(cin, nomePesquisa);
            pessoa.nomePesquisa(nomePesquisa);

            break;
        }
        case 4:
        {

            string cpfPesquisa;
            cout << "Digite CPF para pesquisa:";
            getline(cin, cpfPesquisa);
            pessoa.cpfPesquisa(cpfPesquisa);

            break;
        }
        case 5:{
            string cpfPesquisa;
            cout << "Digite CPF para pesquisa [Excluir]:";
            getline(cin, cpfPesquisa);
            pessoa.excluirPessoa(cpfPesquisa);

            break;
        }
            
        case 6:

            break;
        case 0:

            break;

        default:
            break;
        }

    } while (opcao != 0);

    return 0;

} // Fim main