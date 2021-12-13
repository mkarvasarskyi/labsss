//
//  main.cpp
//  lab6
//
//  Created by Mischa Karvasarskyi on 01.12.21.
//

#include <iostream>
#include "math.h"
using namespace std;

int main(void) {
 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    long n;
    double dbln;
    double sum = 0;
    double term;
    const double eps = 0.000001;
    long k2 = 1;
    short k1 = 1;
 
    for (n = 0; ; n++, k2 *= 2, k1 = -k1) {
 
        dbln = n;
 
        term = k1 * (1 * -(pow(2, n) / (pow(2, n) + 1)));
 
        if (fabs(term) >= eps)
 
            sum += term;
 
        else break;
 
        if (n == 9)
            printf("Сумма 10 членов ряда = %6.3lf\n", sum);
    }
    printf("Полная сумма ряда = %10.7lf\n", sum);
    return 0;
}
