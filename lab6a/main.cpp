//
//  main.cpp
//  lab6.1
//
//  Created by Mischa Karvasarskyi on 03.11.21.
//

#include <iostream>
#include <time.h>////;
using namespace std;


int main()
{
    srand(time(NULL));
    
    int botnum = rand() % 100 + 1;
    int usernum, attempts=0;
    
    printf("Угадай число\n");

    do {
            attempts++;
            scanf("%i", &usernum);
        if (usernum > botnum) {
            printf("Число больше.\n");
            printf("Попробуй еще раз.\n");
        }
        else if (usernum < botnum) {
            printf("Число меньше.\n");
            printf("Попробуй еще раз.\n");
        }
        else {
            printf("Ты угадал");
            printf(" Это было %i \n\n", botnum);
        }
    } while(usernum!=botnum);

       printf("Количество попыток:%i\n\n\n", attempts);

return 0;
}
