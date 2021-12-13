//
//  main.cpp
//  lab9
//
//  Created by Mischa Karvasarskyi on 02.12.21.
//

#include <iostream>
using namespace std;


bool print = 1;
int cycle = 0;

void printLeftAndRightArrays(int* leftArray, int* rightArray, int arrSize, int num, int l_index, int r_index)
{
    if (arrSize < 0)
    {
        if (print)
        {
            print = 0;
            printLeftAndRightArrays(leftArray, rightArray, 0, num - 2, l_index, r_index);
        }
        else
        {
            return;
        }
    }
    if (cycle == 3)
        return;

    int gap = 0;
    for (int i = 0; i < num; ++i)
    {
        cout << leftArray[l_index] << '\t';
        ++l_index;

        if (print)
        {
            arrSize -= 2;

            if (i % 2 == 0 && i != 0)
                gap += 1;

            if (i == 3)
                gap += 2;
        }
        else
        {
            arrSize += 2;

            if (i % 2 != 0 && i != 1)
                gap += 1;

            if (cycle == 2)
                gap += 1;
        }
    }

    for (int i = 0; i < arrSize / 2 + gap; ++i)
        cout << '\t';

    for (int i = 0; i < num; ++i)
    {
        cout << rightArray[r_index] << '\t';
        ++r_index;
    }
      
    cout << endl;

    if (print)
        printLeftAndRightArrays(leftArray, rightArray, arrSize, num + 1, l_index, r_index);
    else
    {
        ++cycle;
        printLeftAndRightArrays(leftArray, rightArray, arrSize, num - 1, l_index, r_index);
    }
}


int main()
{
    const int MyArraySize = 9;
    const int SecondSize = 16;
    int MyArray[MyArraySize][MyArraySize];
    int MyRightArray[SecondSize];
    int MyLeftArray[SecondSize];
    int arrCounter = 0;
    int r = 0, l = 0;
    setlocale(LC_ALL, "ru");
    cout << "Рандомно сгенерированная матрица размером: " << MyArraySize << endl;
    for (int i = 0; i < MyArraySize; i++)
    {
        for (int j = 0; j < MyArraySize; j++)
        {
            MyArray[i][j] = 0 + rand() % 200 - 100;
            cout << MyArray[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < MyArraySize; i++)
    {
        for (int j = 0; j < MyArraySize; j++)
        {
            if (i < j && (i + j) >(MyArraySize - 1)) {
                MyRightArray[r] = MyArray[i][j];
                r++;
                ++arrCounter;
            }
            if (i > j && (i + j) < (MyArraySize - 1)) {
                MyLeftArray[l] = MyArray[i][j];
                l++;
                ++arrCounter;
            }
        }
    }

    cout << endl << endl;

    printLeftAndRightArrays(MyLeftArray, MyRightArray, arrCounter / 2, 1, 0, 0);
}
