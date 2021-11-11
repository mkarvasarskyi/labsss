//
//  main.cpp
//  lab6.2
//
//  Created by Mischa Karvasarskyi on 03.11.21.
//

#include <iostream>
#include <time.h>//;
using namespace std;

int main()
{
    printf("Тест на знание таблици умножения:\n");

    srand(time(NULL));
    
    int user_num, result = 0, nquestion;

    for (nquestion = 1; nquestion <= 5; nquestion++) {

        int randomn1 = rand() % 10 + 1;
        int randomn2 = rand() % 10 + 1;
        int question = randomn1 * randomn2;

        printf("%i): %i * %i\n", nquestion, randomn1, randomn2);
        scanf ("%i", &user_num);

        if(question!=user_num){
            printf("Ошибка. Правильний ответ: %i\n", question);
        } else
            result++;
    }

    printf("Твой общий результат набранных баллов:%i\n", result);

return 0;
}
