//
//  main.cpp
//  lab5.1
//
//  Created by Mischa Karvasarskyi on 27.10.21.
//

#include <math.h>
#include <iostream>
 
int main()
{
    while (true) {

        double count;
        printf("Сколько у тебя грибов? ");
        scanf("%lg", &count);
        int int_count = count;

        if ((count - int_count != 0 && count > 0) || count < 0) {
            printf("Ты не ешь грибы!\n\n\n", count);
        }
        else if (int_count % 100 >= 5 && int_count % 100 <= 20 ) {
            printf("У меня %lg грибов!\n\n\n", count);
        }
        else if (int_count %10 == 1) {
                printf("У меня %lg гриб!\n\n\n", count);
        }
        else if (int_count % 10 >= 2 && int_count % 10 <= 4) {
                printf("У меня %lg грибa!\n\n\n", count);
        } else if (int_count == 0) {
            printf("У меня нет грибов!\n\n\n", count);
    }
     
        else
            printf("У меня %lg грибов!\n\n\n", count);

}
  return 0;
}
