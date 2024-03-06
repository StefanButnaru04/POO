#include <iostream>
#include <cstring>
#include "Masina.h"
using namespace std;


char* Masina::Getfirma()
{
    return this->firma;
}
float Masina::Getlitricomb()
{
    return this->litricombustibil;
}
float Masina::Getconsum()
{
    return this->consum;
}
float Masina::Getkilometraj()
{
    return this->kilometraj;
}
void Masina::Setfirma(char *s)
{
    if (this->firma == 0)
        this->firma = new char[100];
    int sz = strlen(s);
    for (int i= 0; i < sz; i++)
    {
        this->firma[i] = s[i];
    }
}
bool Masina::Setlitricomb(float newlitricombustibil)
{
    if(newlitricombustibil<0)
        return false;
    this->litricombustibil=newlitricombustibil;
    return true;
}
bool Masina::Setconsum(float newconsum)
{
    if(newconsum<0)
        return false;
    this->consum=newconsum;
    return true;
}
bool Masina::Setkilometraj(float newkilometraj)
{
    if(newkilometraj<0)
        return false;
      kilometraj=kilometraj+1000;
    if(newkilometraj<kilometraj)
        this->kildatinapoi=1;
    this->kilometraj=newkilometraj;
    return true;
}
bool Masina::Bijnitz()
{
    if(this->kildatinapoi==1)
        return true;
    return false;
}
void Masina::cursa(float distanta)
{
    this->kilometraj+=distanta;
    double x;
    x=distanta+ this->consum/100;
    this->litricombustibil -=x;
}
