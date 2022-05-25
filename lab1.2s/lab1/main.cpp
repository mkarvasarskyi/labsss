//
//  main.cpp
//  lab1
//
//  Created by Mischa Karvasarskyi on 13.02.2022.
#include <iostream>
#include <stdlib.h>
#include <string>
 
using namespace std;
 
#define amount_of_elements 3
struct Details {

    
    string year;
    char type;
    int diametr;
    float chastota;
 
 
}det[4];
 
void in_put(Details det[]) {
 
    
    for (int i = 0; i < amount_of_elements; ++i) {
 
        cout << i + 1 << "Введите: год , руководителя , диаметр , частоту: ";
        cin >> det[i].year >> det[i].type >> det[i].diametr >> det[i].chastota;
 
    }
 
}
 
void random(Details det[]) {
 
    char letters[3] = { 'D', 'T', 'H' };
    static string name_rand[] = { "1960", "1970", "1978" };
     
    for (int i = 0; i < amount_of_elements; i++) {
 
        det[i].year = name_rand[rand() % 3];
        det[i].type = letters[rand() % 3];
        det[i].diametr = rand() %300 ;
        det[i].chastota = rand() %2000 * 67;
 
    }
}
 
void sort(Details det[]) {
 
 
    if (det[0].diametr > det[1].diametr) {
        swap(det[0], det[1]);
 
    }
 
    if (det[0].diametr > det[2].diametr) {
        swap(det[0], det[2]);
 
    }
 
    if (det[1].diametr > det[2].diametr) {
        swap(det[1], det[2]);
 
    }
 
}
 
void print(Details det[]) {
       /* Вывод таблицы */
       printf("-----------------------------------------------------------------\n");
       printf("|Проекты поиска внеземных сигналов                               |\n");
       printf("|----------------------------------------------------------------|\n");
       printf("|     Год    |  Научный      |  Диаметр антены | Рабочая частота |\n");
       printf("|            |  Руководитель |        (м)      |       (МГц)     |\n");
       printf("|------------|---------------|-----------------|-----------------|\n");
       /* вывод строк фактических данных */
        for (int i = 0; i < amount_of_elements; i++){
             cout << "|";
             cout.width(12);
             cout << det[i].year;
             printf("|   %c           |  %-9.1d      | %14lg  |\n",
                     det[i].type, det[i].diametr, det[i].chastota);
         }
        printf("|----------------------------------------------------------------|\n");
        printf("| Примечание: наблюдались объекты от 2 звезд                     |\n");
        printf("|             до нескольких галактик                             |\n");
        printf("| D - Дрейк, T - Троицкий, H - Хоровиц                           | \n");
        printf("------------------------------------------------------------------\n");
        cout << "\n\n\n\n";

    }

 
int main() {
 
    srand(time(NULL));

 
    int action = 0;
    while (true) {
 
        for (int i = 0; i < 1; i++) {
 
            cout << "1 – случайным, 2 - ввод с экран, 3 – сортировка, 4 – печать, 5 - завершить роботу ";
            cin >> action;
 
            if (action == 1) {
                random(det);
            }
            else if (action == 2) {
                in_put(det);
            }
            else if (action == 3) {
                sort(det);
            }
            else if (action == 4) {
                print(det);
            }
            else if (action == 5) {
                exit(0);
            }
        }
 
    }
 
    return 0;
}

