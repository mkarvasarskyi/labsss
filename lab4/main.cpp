//
//  main.cpp
//  lab4
//
//  Created by Mischa Karvasarskyi on 20.10.21.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
  setlocale(LC_ALL, "RUS");
  int S;// секундны /2
  int M;// минуты
  int H;//часы
  unsigned int REZ;
  printf("Введите секунды от (0 до 31)\n");
  scanf("%d", &S);
  printf("Введите минуты от (0 до 63)\n");
  scanf("%d", &M);
  printf("Введите часы от (0 до 31)\n");
  scanf("%d", &H);
  REZ = ((unsigned int)S & 0x1F) << 11;
  REZ |= ((unsigned int)M & 0x3F) << 9;
  REZ |= (unsigned int)H & 0xF;
  printf("\nФормат представления текущего времени в некоторых системных структурах имеет вид %04x\n\n", REZ);
  printf("Введите 16-ричное число \n");
  scanf("%d", &REZ);
  //Выделение составных частей
  REZ = ((unsigned int)S >> 11) & 0x1F;
  REZ = ((unsigned int)M >> 9) & 0x3F;
  REZ = H & 0xF;
  //Вывод резульатов
  putchar('\n');
  printf(" секунды = %hd\n", S);
  printf(" минуты = %hd\n", M);
  printf(" часы =% hd\n", H);
  system("pause");
  system("cls");
  return 0;
}
