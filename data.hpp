#ifndef DATA_HPP
#define DATA_HPP


#include <iostream>
using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    // construtor sem parametros
    Data()
    {
        setData(0, 0, 0);
    }
    // cosntrutor com tres parametros
    Data(int dia, int mes, int ano)
    {
        setData(dia, mes, ano);
    }
    // construtor com
    Data(int ano)
    {
        setData(0, 0, ano);
    }

    void setData(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    int getDia();
    int getMes();
    int getAno();
    bool dataValida(int dia,int mes,int ano);
    string mesExtenso(int mes);
    bool ehBissexto(int ano);
    int diaMes(int dia,int mes,int ano);
    void lerData();
    void escreveData(int dia,int mes,int ano);
};

#endif