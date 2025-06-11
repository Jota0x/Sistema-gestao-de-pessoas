#include <iostream>
#include <fstream>
#include "pessoa.hpp"
#include "data.hpp"
using namespace std;


extern const int MAX; // Constante global: tamanho físico do arranjo de pessoas
extern int TAM;





string Pessoa::getNome(string nome)
{
    return nome;
}

Data Pessoa::getIdade(int ano)
{
    int idade = 0;

    idade = 2025 - ano;

    return idade;
}

string Pessoa::getCpf(string cpf)
{
    return cpf;
}

void Pessoa::leiaPessoa(string nome)
{
    cout << "Nome: " << endl;
    cin >> nome;
}

void Pessoa::escreverPessoa(string nome, Data nascimento, string cpf)
{
    cout << "Nome: " << nome << " | Data nascimento: " << "|";
    nascimento.escreveData(nascimento.getDia(), nascimento.getMes(), nascimento.getAno());
    cout << " | CPF: " << cpf << endl;
}

void Pessoa::cadastrarPessoa()
{
    string nome, cpf;
    int dia, mes, ano;

    cout << "Digite Nome:";
    getline(cin, nome);

    cout << "Digite o CPF";
    getline(cin, cpf);

    cout << "Digite a data de nascimento (dd/mm/aaaa): ";
    string data;
    getline(cin, data);

    // "quebrar" a string em três números, usando o formato dd/mm/aaaa
    sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);

    ofstream file("pessoas.dat", ios::app);
    if (file.is_open())
    {
        file << nome << ";" << cpf << ";" << data << endl;
        file.close();
        cout << "Cadastro salvo com sucesso!" << endl;
        TAM++;
    }
    else if(TAM >= MAX)
    {
        cout << "Numero máximo de pessoas atingido";
    }
    else
    {
        cout << "Erro ao abrir arquivo!";
    }
}

void Pessoa::listarPessoa()
{
    ifstream file("pessoas.dat");
    string linha;
    if (file.is_open())
    {
        cout << "Lista de pessoas cadastradas:" << endl;
        while (getline(file, linha)) // le cada linha
        {
            // Encontra a posição dos ';'
            size_t pos1 = linha.find(';');
            size_t pos2 = linha.find(';', pos1 + 1);

            // Separa os campos usando as posições dos ';'
            string nome = linha.substr(0, pos1);                  // Do início até o primeiro ';'
            string cpf = linha.substr(pos1 + 1, pos2 - pos1 - 1); // Entre os dois ';'
            string data = linha.substr(pos2 + 1);                 // Do segundo ';' até o fim

            // imprime o modelo formatado na tela
            cout << "Nome: " << nome << " | CPF: " << cpf << " | Data de nascimento: " << data << endl;
        }
        file.close();
    }
    else
    {
        cout << "Erro ao abrir arquivo!";
    }
}

void Pessoa::nomePesquisa(string nomePesquisa)
{
    ifstream file("pessoas.dat");
    string linha;
    if (file.is_open())
    {
        cout << "Pesquisa nome:" << endl;
        getline(cin, nomePesquisa);

        while (getline(file, linha)) // le cada linha
        {
            // Encontra a posição dos ';'
            size_t pos1 = linha.find(';');
            size_t pos2 = linha.find(';', pos1 + 1);

            // Separa os campos usando as posições dos ';'
            string nome = linha.substr(0, pos1);                  // Do início até o primeiro ';'
            string cpf = linha.substr(pos1 + 1, pos2 - pos1 - 1); // Entre os dois ';'
            string data = linha.substr(pos2 + 1);                 // Do segundo ';' até o fim

            if (nome == nomePesquisa)
            {
                cout << "Nome: " << nome << " | CPF: " << cpf << " | Data de nascimento: " << data << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Erro ao abiri arquivo" << endl;
    }
}

void Pessoa::cpfPesquisa(string cpfPesquisa)
{
    ifstream file("pessoas.dat");
    string linha;
    if (file.is_open())
    {
        while (getline(file, linha)) // le cada linha
        {
            // Encontra a posição dos ';'
            size_t pos1 = linha.find(';');
            size_t pos2 = linha.find(';', pos1 + 1);

            // Separa os campos usando as posições dos ';'
            string nome = linha.substr(0, pos1);                  // Do início até o primeiro ';'
            string cpf = linha.substr(pos1 + 1, pos2 - pos1 - 1); // Entre os dois ';'
            string data = linha.substr(pos2 + 1);                 // Do segundo ';' até o fim

            if (cpf == cpfPesquisa)
            {
                cout << "Nome: " << nome << " | CPF: " << cpf << " | Data de nascimento: " << data << endl;
            }
            if (cpf != cpfPesquisa)
            {
                cout << "Pessoa não cadastrada";
            }
        }
        file.close();
    }
    else
    {
        cout << "Erro ao abiri arquivo" << endl;
    }
}

void Pessoa::excluirPessoa(string cpfPesquisa)
{
    ifstream file("pessoas.dat");
    ofstream fileNovo("pessoasNovo.dat");
    bool achou = false;
    string linha;

    if (file.is_open() && fileNovo.is_open())
    {
        while (getline(file, linha))
        {
            size_t pos1 = linha.find(';');
            size_t pos2 = linha.find(';', pos1 + 1);
            string cpf = linha.substr(pos1 + 1, pos2 - pos1 - 1);

            if (cpf != cpfPesquisa)
            {
                fileNovo << linha << endl; // Copia quem NÃO é o CPF buscado
            }
            else achou = true;
        }
        file.close();
        fileNovo.close();
        remove("pessoas.dat");
        rename("pessoasNovo.dat", "pessoas.dat");
        if (achou)
        {
            cout << "Pessoa excluida com sucesso!";
            TAM--;
        }
        else
        {
            cout << "Pessoa não encontrada";
        }
    }
    else
    {
        cout << "Erro ao abrir arquivo!" << endl;
    }
}
