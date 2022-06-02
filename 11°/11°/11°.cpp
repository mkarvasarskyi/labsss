#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>

using namespace std;


class Figure
{
private:
    int a, b, c, r;
    const double pi = 3.141592;
public:

    Figure(int q, int w, int e = 5, int t = 1) //для е и t аргументи по умолчанию 
    {
        a = q;
        b = w;
        c = e;
        r = t;
    }
    void sq_tr()
    {
        int p = (a+b+c)/2;
        int sq = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "площадь треугольника = " << sq<<endl;
    }

    void sq_cir()
    {
        double radius = r;
        double sq = pi * radius * radius;
        cout << "площадь круга = " << sq<<endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Figure f(3, 4);

    f.sq_cir();
    f.sq_tr();
}



