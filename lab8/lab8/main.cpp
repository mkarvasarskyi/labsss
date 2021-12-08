//
//  main.cpp
//  lab8
//
//  Created by Mischa Karvasarskyi on 01.12.21.
//

#include <iostream>
using namespace std;

int main()
{
  const int MyArrayLength = 100;
  int SummOfMyArray = 0;
  int per = 0;
  int MyArray[MyArrayLength];

  cout << "Рандомно сгенерированный массив на " << MyArrayLength << " элементов" << endl;
  for (int i = 0; i < MyArrayLength; i++)
  {
    MyArray[i] = 0 + rand() % 200-100;
    cout << MyArray[i] << "\t";
  }
  cout << endl << endl;
  for (int i = 0; i < MyArrayLength; i++)
  {
    if (MyArray[i] > 0) {
      SummOfMyArray += MyArray[i];
      per++;
    }
  }
  int result = SummOfMyArray / per;
  cout << "Cреднее арифметическое всех положительных элементов массива = " << result <<endl;
  cout << "Все отрицательные элементы массива заменены на среднее арифметическое всех положительных элементов массива:" << endl << endl;
  for (int i = 0; i < MyArrayLength; i++)
  {
    if (MyArray[i] < 0) {
      MyArray[i] = result;
    }
    cout << MyArray[i] << "\t";
  }
}
