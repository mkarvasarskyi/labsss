#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;


class Projects
{
private:
    int year;
    char *leader;
    double diameter;
    int frequency;
public:

    void set(int a, char* b, double c, int d);
    void get(int* a, char* b, double* c, int* d);
    void show();
};

void Projects::set(int a,char *b,double c,int d)
{
    year = a;
    leader = new char[strlen(b)];
    strcpy(leader, b);
    diameter = c;
    frequency = d;
}
void Projects::get(int* a, char *b, double* c, int* d)
{
    *b = *leader;
    *a = year;
    *c = diameter;
    *d = frequency;
}
void Projects::show()
{
    cout << year << " ";
    cout << leader << " ";
    cout << diameter << " ";
    cout << frequency <<endl;
}
int main()
{
    setlocale(LC_ALL, "");

    Projects p[3];
    int y;
    char *l = new char [10];
    double d;
    int f;

    //Работа функции SET
    for (int i = 0; i < 3;i++)
    {
        cout << "Год, Научный руководитель,Диаметр антены (м), Рабочая частота(МГц):\n";
        cin >> y;
        cin >> l;
        cin >> d;
        cin >> f;
        p[i].set(y, l, d, f);
    }
    //Работа функции  SHOW
    cout << "Год, Научный руководитель,Диаметр антены (м), Рабочая частота(МГц):\n";
    for (int i = 0; i < 3;i++)
    { 
        p[i].show();
    }
    cout << "\nГод, Научный руководитель,Диаметр антены (м), Рабочая частота(МГц)\n";
    //Работа функции GET and SHOW
    for (int i = 0; i < 3;i++)
    { 
        p[i].get(&y, l, &d, &f);
        cout << y << " ";
        cout << l << " ";
        cout << d << " ";
        cout << f << endl;
        
    }
}



