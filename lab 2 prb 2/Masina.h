#include <iostream>

using namespace std;
class Masina
{
    char* firma=0;
    float litricombustibil, consum=10, kilometraj;
    int kildatinapoi=0;
public:
    char* Getfirma();
    float Getlitricomb();
    float Getconsum();
    float Getkilometraj();

    void Setfirma(char *s);
    bool Setlitricomb(float newlitricombustibil);
    bool Setconsum(float newconsum);
    bool Setkilometraj(float newkilometraj);

    bool Bijnitz();
    void cursa(float distanta);
};
