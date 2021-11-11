//
//  main.cpp
//  lab3
//
//  Created by Mischa Karvasarskyi on 20.10.21.
//

#include <stdio.h>
#include <math.h>
int main(void) {

    double x;
    double a = 2, b = 3;
    double t1, t2;
    double ax;

    printf("Введите x = ");
    scanf("%lf", &x);

    t1 = ((1 /  pow(a, 4)) * ( pow(x, 3) / 3) - (3 * b * x) + (3 * pow (b, 2)) * (log(x) + (pow(b, 3) / x)));
    ax = a * x * 3.14 / 180;
    t2 = ((1/(1-sin(ax)) + 1/a * (tan(ax/2))));

    printf("t1 = %lg\n", t1);
    printf("t2 = %lg\n", t2);
    return 0;
}
