#include <iostream>
using namespace std;
#include "Math.h"

int Math::Add(int x1, int x2)
{
    return x1+x2;
}
int Math::Add(int x1, int x2, int x3)
{
    x1+=x2;
    return x1+x3;
}
int Math::Add(double x1, double x2)
{
    return x1+x2;
}
int Math::Add(double x1, double x2, double x3)
{
    x1+=x2;
    return x1+x3;
}
int Math::Mul(int x1, int x2)
{
    return x1*x2;
}
int Math::Mul(int x1, int x2, int x3)
{
    x1*=x2;
    return x1*x3;
}
int Math::Mul(double x1, double x2)
{
    return x1*x2;
}
int Math::Mul(double x1, double x2, double x3)
{
    x1*=x2;
    return x1*x3;
}
