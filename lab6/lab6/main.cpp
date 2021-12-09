//
//  main.cpp
//  lab6
//
//  Created by Mischa Karvasarskyi on 01.12.21.
//

#include <iostream>
#include "math.h"
using namespace std;

int main()
{
    double a, n;
    cout << "Введите значение n" << endl;
    cin >> n;
    a = (pow(-1, n) * (1 - ((pow(2, n)/(pow(2,n)+1)))));
    cout << "Результат работы: " << a;
}
