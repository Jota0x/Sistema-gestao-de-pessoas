#include <iostream>
#include "data.hpp"
#include "pessoa.hpp"
using namespace std;

extern const int MAX; // Constante global: tamanho físico do arranjo de pessoas
extern int TAM;


int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}

bool Data::ehBissexto(int ano)
{
    if (ano % 4 == 0 && ano % 100 != 0 || (ano % 400 == 0))
    {
        return true;
    }
    return false;
}

bool Data::dataValida(int dia, int mes, int ano)
{
    if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0)
    {
        if (mes == 2)
        {
            if (ehBissexto(ano))
                dia <= 29;
            else
                dia <= 28;
        }
        return true;
    }
    return false;
}

string Data::mesExtenso(int mes)
{
    string mesExtenso[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    if (mes >= 1 && mes <= 12)
    {
        return mesExtenso[mes - 1];
    }
    return "Mes invalido";
}

int Data::diaMes(int dia, int mes, int ano)
{
    int diaMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && ehBissexto(ano) == true)
    {
        return 29;
    }

    return diaMes[dia - 1];
}

void Data::lerData()
{
    int d, m, a;
    cout << "Dia: " << endl;
    cin >> d;
    cout << "Mes: " << endl;
    cin >> m;
    cout << "Ano: " << endl;
    cin >> a;

    if (!dataValida(d, m, a))
    {
        cout << "Data invalida !" << endl;
    }
}

void Data::escreveData(int dia, int mes,int ano)
{
    cout << dia << "/" << mes << "/" << ano;
}