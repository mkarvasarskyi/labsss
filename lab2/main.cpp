//
//  main.cpp
//  lab2
//
//  Created by Mischa Karvasarskyi on 20.10.21.
//

#include <iostream>
using namespace std;
int main()
{

    /*char year1[6], year2[6], year3[6];
    char name1[11], name2[11], name3[11];
    int cnt1, cnt2, cnt3;
    float wei1, wei2, wei3;*/

    char year1[6] = "1960", year2[6] = "1970", year3[6] = "1978";
    char name1[11] = "Drake", name2[11] = "Troickyi", name3[11] = "Chorovic"; //strcpy(name1, "Тодайдзи");
    int cnt1 = 26, cnt2 = 14, cnt3 = 30;
    int wei1 = 1420, wei2 = 1875, wei3 = 1665;

     
    //printf("1. Введите: Год, Руководителя, Диаметр (м), Частоту (МГц)  >"); // фланець З 3 450
    //scanf("%s %c %d %f", year1, &name1, &cnt1, &wei1);

    //printf("2. Введите: Год, Руководителя, Диаметр (м), Частоту (МГц) > "); // перехідник П 8 74
    //scanf("%s %c %d %f", year2, &name2, &cnt2, &wei2);

    //printf("3. Введите: Год, Руководителя, Диаметр (м), Частоту (МГц) >"); // станина О 1 117050
    //scanf("%s %c %d %f", year3, &name3, &cnt3, &wei3);



    printf("-----------------------------------------------------------------\n");
    printf("|Проекты поиска внеземных сигналов                               |\n");
    printf("|----------------------------------------------------------------|\n");
    printf("|     Год    |  Научный      |  Диаметр антены | Рабочая частота |\n");
    printf("|            |  Руководитель |        (м)      |       (МГц)     |\n");
    printf("|------------|---------------|-----------------|-----------------|\n");
    
    printf("| %10s | %13s | %15d | %15d |\n", year1, name1, cnt1, wei1);
    printf("| %10s | %13s | %15d | %15d |\n", year2, name2, cnt2, wei2);
    printf("| %10s | %13s | %15d | %15d |\n", year3, name3, cnt3, wei3);

    printf("|----------------------------------------------------------------|\n");
    printf("| Примечание: наблюдались объекты от 2 звезд                     |\n");
    printf("|             до нескольких галактик                             |\n");
    printf("------------------------------------------------------------------\n");

    return 0;
}