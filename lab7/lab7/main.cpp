//
//  main.cpp
//  lab7
//
//  Created by Mischa Karvasarskyi on 17.11.21.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    
    short n;        /* параметр внешнего цикла */
    double x, y = 0.0;    /* абсцисса и ордината графика */
    short h;        /* позиция точки на экране */
                    /* внешний цикл - для 5 периодов */
    for (n = 0; n < 5; n++) {
        
        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");
        for (x = 0; x < 4; x += 0.25) {
            if (x <= 2) y = 0 + sqrt(1 - (x - 1) * (x - 1));
            else if (x >= 2) y = 0 -sqrt( - (x - 2) * (x - 4));
            printf("| %5.2lf | %10.7lf |", x + n * 4, y);
            h = (y + 1.1) * 10;
            if (y - 1 - h * 10 > 1) h++;
            for (; h > 0; h--) printf(" ");
            printf("*\n");
            
        }
        
        printf("Нажмите клавишу Enter...");
        getchar();
    }
    
    return 0;
    
}
