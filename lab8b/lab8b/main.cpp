//
//  main.cpp
//  lab8b
//
//  Created by Mischa Karvasarskyi on 17.11.21.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

    int arr_size;
    cout << "Введите количество элементов массива: ";
    cin >> arr_size;
    

    int *arr = new int[arr_size];

    int k; // num of elemnts that we add or del
    int i; // index of first array
    int j; // index of second array

    // random created array
    cout << "Ваш массив:" << endl;
    for ( i = 0; i < arr_size; i++) {
        arr[i] = rand() % 10 + 1;
        cout << arr[i] << setw(4);
    }
    cout << endl;

    // to do qu
    string answer;
    string del_new("удалить");
    string add_new("добавить");
    while (true) {

        cout << "Вы хотите удалить или добавить элементы? <удалить/добавить> ";
        cin >> answer;
        //cin >> answer;

        // add k elements
        if (answer == add_new) {
            // input
            int pos;
            cout << "Сколько элементов вы хотите добавить? ";
            cin >> k;
            cout << "Выберите позицию, с которой вы хотите добавть данное количество элементов: " << k << endl;
            cin >> pos;
    

            // add loops
            
            int *add_new_arr = new int[arr_size + k];

            for (i = 0; i < pos; i++) {
                add_new_arr[i] = arr[i];
            }

            int *add_elements = new int[k];

            cout << "Новые элементы: ";
            for ( j = 0; j < k; j++) {
                add_elements[j] = rand() % 10 + 1;
                cout << add_elements[j] << setw(4);
            }
            cout << endl;

            for ( j = 0, i = pos; i < arr_size + k; i++, j++) {
                add_new_arr[i] = add_elements[j];
            }

            for ( j = pos + k, i = pos; j < arr_size + k; j++, i++) {
                add_new_arr[i + k] = arr[i];
            }

                // new array
            cout << "Ваш новый массив:" << endl;
            for (i = 0; i < arr_size + k; i++) {
                cout << add_new_arr[i] << setw(4);
            }
            cout << endl;
            
        }
        // del k elements
        else if (answer == del_new) {

            // input
            cout << "Сколько элементов вы хотите удалить? ";
            cin >> k;
            

            cout << "Выберите позицию, с которой вы хотите удалить данное количество элементов: " << k << endl;
            cin >> i;
            

            if (arr_size == k and i == 0) {
                cout << "Массив удалён!" << endl;
            }

            else {

                for (; i < arr_size - k; i++) {
                    arr[i] = arr[i + k];
                }

                // new array
                cout << "Ваш новый массив:" << endl;
                for (i = 0; i < arr_size - k; i++) {
                    cout << arr[i] << setw(4);
                }
                cout << endl;
            }
        }
    }
    return 0;
}
