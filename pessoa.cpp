#include <iostream>
#include <fstream>
using namespace std;

#include "pessoa.hpp"
#include "data.hpp"

string getNome(string nome)
{
    return nome;
}

Data getidade(int ano)
{
    int idade = 0;

    idade = 2025 - ano;

    return idade;
}

string getCpf(string cpf)
{
    return cpf;
}

void leiaNome(string nome)
{
    cout << "Nome: " << endl;
    cin >> nome;
}

void escrevaNome(string nome)
{
    cout << "Nome:" << nome << endl;
}

void escrevaPessoa(string nome, int ano)
{
    cout << "Nome: " << nome << " | idade: " << (2025 - ano) << " | " << endl;
}

void cadastrarPessoa()
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
    }
    else
    {
        cout << "Erro ao abrir arquivo!";
    }
}

void listarPessoa()
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
