#ifndef PESSOA_HPP
#define PESSOA_HPP
class Data;

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
        setPessoa("", Data(), "");
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
        setPessoa(nome,Data(),"");
    }

    void setPessoa(string nome, Data nascimento, string cpf)
    {
        this->nome = nome;
        this->nascimento = nascimento;
        this->cpf = cpf;
    }

    string  getNome(string nome);
    Data getIdade(int ano);
    string getCpf(string cpf);
    void leiaPessoa(string nome);
    void escreverPessoa(string nome, Data nascimento, string cpf);
    void cadastrarPessoa();
    void listarPessoa();
    void nomePesquisa(string nomePesquisa);
    void cpfPesquisa(string cpfPesquisa);
    void excluirPessoa(string cpfPesquisa);

};

class Aluno : public Pessoa
{
};

class Professor : public Pessoa
{
};

#endif