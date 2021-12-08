//
//  main.cpp
//  lab9
//
//  Created by Mischa Karvasarskyi on 02.12.21.
//

#include <iostream>
using namespace std;

int main() {
    const int MyArraySize = 9;;
    int MyArray[MyArraySize][MyArraySize];
    cout << "Рандомно сгенерированная матрица размером: "<< MyArraySize << endl;
    for (int i = 0; i < MyArraySize; i++)
    {
        for (int j = 0; j < MyArraySize; j++)
        {
            MyArray[i][j] = 0 + rand() % 200 - 100;
            cout << MyArray[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Элементы матрицы которые находятся справа (над главной диагональю и под побочной диагональю)." << endl;
    for (int i = 0; i < MyArraySize; i++)
    {
        for (int j = 0; j < MyArraySize; j++)
        {
            if (i < j && (i + j) >(MyArraySize - 1)) {
                cout << MyArray[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout <<"Элементы матрицы которые находятся слева (под главной диагональю и над побочной диагональю)." << endl;
    for (int i = 0; i < MyArraySize; i++)
    {
        for (int j = 0; j < MyArraySize; j++)
        {
            if (i > j&& (i + j) < (MyArraySize -1)) {
                cout << MyArray[i][j] << "\t";
            }
        }
        cout << endl;
    }
}
