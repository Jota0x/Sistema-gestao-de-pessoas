#include <iostream>
using namespace std;

#include "data.hpp"

int getDia(int dia)
{
    return dia;
}

int getMes(int mes)
{
    return mes;
}

int getAno(int ano)
{
    return ano;
}

bool dataValida(int dia, int mes, int ano)
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

bool ehBissexto(int ano)
{
    if (ano % 4 == 0 && ano % 100 != 0 || (ano % 400 == 0))
    {
        return true;
    }
    return false;
}

string mesExtenso(int mes)
{
    string mesExtenso[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    if (mes >= 1 && mes <= 12)
    {
        return mesExtenso[mes - 1];
    }
    return "Mes invalido";
}

int diaMes(int dia, int mes, int ano)
{
    int diaMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && ehBissexto(ano) == true)
    {
        return 29;
    }

    return diaMes[dia - 1];
}

void lerData()
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

void escreveData(int dia, int mes,int ano)
{
    cout << dia << "/" << mes << "/" << ano;
}