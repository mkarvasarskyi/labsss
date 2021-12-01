//
//  main.cpp
//  lab4.0
//
//  Created by Mischa Karvasarskyi on 01.12.21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
int main(void)
{
    setlocale(LC_ALL, "Ru");
    int u, r, w, e, x;
    unsigned int UnitStateWord;//тип переменных 0-4м
    printf("Введите идентификатор пользователя (0 - 255) >");
    scanf("%d", &u);//управляющая строка амперсант оператор взятия адреса переменной
    printf("Право читать  (0 / 1) >");
    scanf("%d", &r);
    printf("Право писать (0 / 1) >");
    scanf("%d", &w);
    printf("Право выполнять программный код (0 - 1) >");
    scanf("%d", &e);
    printf("Явный запрет пользователя (0 - 1) >");
    scanf("%d", &x);
    UnitStateWord = ((unsigned int)u & 0xFF) <<8;
    UnitStateWord |= ((unsigned int)r & 1) <<7;
    UnitStateWord |= ((unsigned int)w & 1) <<6;
    UnitStateWord |= ((unsigned int)e & 1) <<5;
    UnitStateWord |= x & 1;
    printf("\nСлово состояния устройства = %04x\n", UnitStateWord);
        printf("Введите cлово состояния устройства \n");
        printf("(16-ричное число от 0 до 0xFF) >");
        scanf("%x", &UnitStateWord);
        u = (UnitStateWord >> 8) & 0xFF;

r = (UnitStateWord >> 7) & 1;
        w = (UnitStateWord >> 6) & 1;
        e = (UnitStateWord >> 5) & 1;
        x = UnitStateWord & 1;
        putchar('\n'); //записывает символ в текущей позиции в стандартный поток вывода
        printf("Идентификатор пользователя=%d\n", u);
        printf("Право читать=%d\n", r);//Десятичное число целого типа
        printf("Право писать=%d\n", w);
        printf("Право выполнять программный код=%d\n", e);
        printf("Явный запрет доступа=%d\n", x);
        return 0;
}
