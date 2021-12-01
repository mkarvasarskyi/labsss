//
//  main.cpp
//  lab8
//
//  Created by Mischa Karvasarskyi on 01.12.21.
//

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <locale.h>
int Ar[100];   // массив, который обрабатывается

int main(void) {
    setlocale(LC_ALL, "Rus");
    int i, j;    // индексы в массиве
    int av;      // среднее значение
    int nn; // количество элементов в последовательности
    int ib;      // индекс начала последовательности

    rand();
    for (i = 0; i < 100; Ar[i++] = rand() - 100);
    printf("Начальный массив:\n");
    for (i = 0; i < 100; printf("%3d  ", Ar[i++]));
    putchar('\n');
    putchar('\n');
    for (nn = i = 0; i < 100; i++) {
        if (Ar[i] < 0)
            if (!nn) {
                ib = i; av = Ar[i]; nn = 1;
            }
            else {
                av += Ar[i]; nn++;
            }
        else
            if (nn) {
                
                av /= nn;
                for (j = ib; j < i; j++)
                    if (Ar[j] > av) Ar[j] = av;
                nn = 0;
            }
    }
    if (nn)
        for (av /= nn, j = ib; j < i; j++)
            if (Ar[j] > av) Ar[j] = av;
    printf("Массив-результат:\n");
    for (i = 0; i < 100; printf("%3d  ", Ar[i++]));
    putchar('\n');
    return 0;
}
