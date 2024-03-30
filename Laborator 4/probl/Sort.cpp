#include <iostream>
#include <cstdarg>
#include "Sort.h"
#include <cstring>
#include <cstdlib>

using namespace std;

Sort::Sort(int nrElemente, int min, int max)
{
    this->nrElemente=nrElemente;
    elemente = new int[nrElemente];
    for (int i = 0; i < nrElemente; i++)
       elemente[i] = min + rand() % (max - min + 1);
}

Sort::Sort(int nrElemente, char s) : elemente(new int[nrElemente] {68, 29, 39, 23, 71, 22, 26, 11, 79, 70})
{
    this->nrElemente = nrElemente;
}


Sort::Sort(int v[100], int nrElemente)
{
    this->nrElemente = nrElemente;
    this->elemente = new int[nrElemente];
    for (int i = 0; i < nrElemente; i++)
        this->elemente[i] = v[i];
}

Sort :: Sort(int nrElemente, ...)
{
    this->nrElemente = nrElemente;
    this->elemente = new int[nrElemente];
    va_list args;
    va_start(args, nrElemente);
    for (int i = 0; i < nrElemente; i++)
        this->elemente[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort(char s[])
{
    this->elemente=new int[nrElemente];
    int m=strlen(s);
    int i=0;
    for(int j=0;j<m;j++)
    {
        if(s[j]==',')
        {j++;i++;}
        else
            elemente[i]=elemente[i]*10+s[j]-'0';
    }
}

Sort::~Sort()
{
    delete[] this->elemente;
}

void Sort::InsertSort(bool ascendent)
{
    int nr;
    if (ascendent == false) nr = 1;
    else nr = -1;
    for (int i = 0; i < this->nrElemente; i++)
    {
        int aux = this->elemente[i];
        int j = i - 1;
        while (j >= 0 && nr * this->elemente[j] < nr * aux)
        {
            this->elemente[j + 1] = this->elemente[j];
            j--;
        }
        elemente[j + 1] = aux;
    }
}

void QS(int *elemente,int nrElemente,bool ascendent)
{
    int aux, nr;
    if (ascendent == false) nr = 1;
    else nr = -1;

    if (nrElemente <= 1) return;
    // la pozitia n-1 se afla pivotul
    int p1 = 0;
    int p2 = nrElemente-1;

    while (p1 <= p2)
    {   // p1==p2 p1==p2+1
        while (nr*elemente[p1] < nr*elemente[nrElemente - 1] && p1 < nrElemente) p1++;
        while (nr*elemente[p2] >= nr*elemente[nrElemente - 1] && p2 >= 0) p2--;
        if (p1 < p2)
        {
            int aux = elemente[p1];
            elemente[p1] = elemente[p2];
            elemente[p2] = aux;
        }
    }
    aux = elemente[p1];
    elemente[p1] = elemente[nrElemente - 1];
    elemente[nrElemente - 1] = aux;
    QS(elemente, p1,ascendent);
    QS(elemente + p1 + 1, nrElemente - p1 - 1,ascendent);
}

void Sort::QuickSort(bool ascendent)
{
    QS(this->elemente, this->nrElemente,ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int nr;
    if (ascendent == false) nr = 1;
    else nr = -1;
    bool ok = 0;
    int aux;
    while (ok == 0)
    {
        ok = 1;
        for (int i = 0; i < this->nrElemente - 1; i++)
            if (nr * elemente[i] < nr * elemente[i + 1])
            {
                ok = 0;
                aux = elemente[i];
                elemente[i] = elemente[i + 1];
                elemente[i + 1] = aux;
            }
    }
}

void Sort::Print()
{
    for (int i = 0; i < this->nrElemente; ++i)
        cout << elemente[i] << " ";
    cout << endl;
}

int Sort::GetElementsCount()
{
    return this->nrElemente;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < this->nrElemente)
        return elemente[index];
    else return -1;
}
