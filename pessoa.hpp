#include <iostream>
using namespace std;

#include "data.hpp"

class Pessoa
{
private:
    string nome;
    Data nascimento;
    string cpf;

public:
    // construtor com nenhum parâmetro
    Pessoa()
    {
        setPessoa(NULL, NULL, NULL);
    }
    // cosntrutor com 4 parâmetros
    Pessoa(string nome, int dia, int mes, int ano)
    {
        Data nascimento(dia, mes, ano);
        setPessoa(nome, nascimento, ""); // "" foi colocado para manter a quantidade de parametros necessarios para a função
    }
    // cosntrutor com um único parametro
    Pessoa(string nome)
    {
        setPessoa(nome, NULL, "");
    }

    void setPessoa(string nome, Data nascimento, string cpf)
    {
        this->nome = nome;
        this->nascimento = nascimento;
        this->cpf = cpf;
    }

    void getNome(string nome);
    Data getIdade(Data nascimento);
    string getCpf(string cpf);
    void leiaPessoa();
    void escreverPessoa(string nome, Data nascimento,int cpf);
    void cadastrarPessoa();
    void listarPessoa();

    
};