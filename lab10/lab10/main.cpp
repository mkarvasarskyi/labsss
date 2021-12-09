//
//  main.cpp
//  lab10
//
//  Created by Mischa Karvasarskyi on 09.12.21.
//

#include <iostream>
using namespace std;
int* ConvertMyArrayToMatrix(int* MyArray) {
    const int M = 3;
    const int N = 3;
    int temp = 0;
    int Matrix[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Matrix[i][j]=MyArray[temp];
            temp++;
            cout << Matrix[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    temp = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp = Matrix[i][N - i - 1];
        Matrix[i][N - i - 1] = Matrix[i][i];
        Matrix[i][i] = tmp;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << Matrix[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MyArray[temp] = Matrix[i][j];
            temp++;
        }
    }
    return MyArray;
}


int main() {
    const int size = 9;
    int MyArray[size]= { 1, 2, 3, 5, 6, 7, 8, 9, 0 };
    for (int i = 0; i < size; i++) {
        cout << MyArray[i] << " ";
    }
    cout << endl << endl;
    ConvertMyArrayToMatrix(MyArray);
    for (int i = 0; i < size; i++) {
        cout << MyArray[i] << " ";
    }
}
