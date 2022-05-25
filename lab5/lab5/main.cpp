//
//  main.cpp
//  lab5
//
//  Created by Mischa Karvasarskyi on 20.04.2022.
//

#include <iostream>
#include <cstdlib>

#define one //one|two  вибор функции
using namespace std;
 
#ifdef one
void fill(int* A, int s) {
    int* C;      /* текущий указатель в массиве */
    int l, r;  /* строка и столбец */
    int k = 1;     /* текущий член ЛП */
    for (l = 0, C = A; l < s; l++)     /* перебор строк */
        for (r = 0; r < s; r++, C++)  /* перебор столбцов */
          /* условие нулевого значения */
            if ((r >= max(l, s - l - 1)) || (r <= min(l, s - l - 1))) *C = 0;
            else *C = k++;
    /* конец перебора строк */
  /* конец перебора столбцов */
}
#endif
#ifdef two
void fill(int ** A, int s) {
    int l, r; /* строка и столбец */
    int k = 1;  /* текущий член ЛП */
    for (l = 0; l < s; l++)    /* перебор строк */
        for (r = 0; r < s; r++)  /* перебор столбцов */
        { /* условие нулевого значения */
            if ((r >= max(l, s - l - 1)) || (r <= min(l, s - l - 1)))
                A[l][r] = 0;
            else A[l][r] = k++;
        }
    /* конец перебору строк */
  /* конец перебору столбцов */
}
#endif
int main()
{
    int m = 6;
    int** mas1;
    int* mas2;

#ifdef one
    mas2 = new int [m*m];
    
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < m;j++)
        {
            mas2[i*m+j] = rand() % 76 + 12;
            cout << mas2[i * m + j] << " ";
        }
        cout << endl;
    }
    fill(mas2, m);
    cout << endl;
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cout << mas2[i * m + j] << " ";
        }
        cout << endl;
    }
#endif

#ifdef two
    mas1 = new int* [m];
    for (int i = 0; i < m;i++)
        mas1[i] = new int[m];

    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < m;j++)
        {
            mas1[i][j] = rand() % 76 + 12;
            cout << mas1[i][j] << " ";
        }
        cout << endl;
    }
    fill(mas1, m);
    cout << endl;
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cout << mas1[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}
