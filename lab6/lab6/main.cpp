//
//  main.cpp
//  lab6
//
//  Created by Mischa Karvasarskyi on 01.12.21.
//

#include <stdio.h>
#include <math.h>
#include <iostream>


int main()
{
    int n = 0;
    int a = 0;
    double Sum = 0,  sum_of_10 = 0, eps = 0.000001;
    while (fabs(a) > eps)
    {
        a = pow(-1, n) * (1 - (double)pow(2, n) / (pow(2, n) + 1));
        Sum += a;//Сложение, совмещённое с присваиванием
        if (n == 10)//вывод суммы
        {
            sum_of_10 =Sum;//сумма 10 чисел
        }
        n++;//инкремент
    }
    printf("Сумма 10 членов ряда: %.8f\nПолная сумма ряда: %.8f\n", Sum, sum_of_10);
    
    system("pause");
    return 0;
}
