//
//  main.cpp
//  lab5.0
//
//  Created by Mischa Karvasarskyi on 26.10.21.
//
#include <math.h>
#include <iostream>

int main()
{
    double a, b, c, x, x1, x2, D;
    while (1) {

        printf("Введите a = ");
        scanf("%lf", &a);
        printf("Введите b = ");
        scanf("%lf", &b);
        printf("Введите c = ");
        scanf("%lf", &c);

        D = (pow(b, 2) - (4 * a * c));
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        x = -b / (2 * a);

        if (D > 0)
            printf("x1 = %-5.3lf \n", x1) && printf("x2 = %-5.3lf \n", x2);
        else
            if (D == 0)
                printf("x = %-5.3lf \n", x);
            else
                if (D < 0)
                    printf("Нет решений \n");
    }
    return 0;
    
    }
