//
//  main.cpp
//  lab 3
//
//  Created by Mischa Karvasarskyi on 20.04.2022.
//

#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
  int summ_of_myArray = 0;
    int myArray[size];
  int counter = 0;
  for (int i = 0; i < size; i++)
  {
    myArray[i] = rand() % 40 - 20;
  }
  cout << "myArray: ";
  for (int i = 0; i < size; i++)
  {
    cout << myArray[i] << '\t';
  }
  cout <<endl<< "summ_of_myArray: ";
  for (int i = 0; i < size; i++)
  {
    if (myArray[i] >= 10|| myArray[i] <= -10)
    {
      summ_of_myArray += myArray[i];
      counter++;
    }
  }
  cout << summ_of_myArray;
  int* myNewArray = new int[counter];
  counter = 0;
  for (int i = 0; i < size; i++)
  {
    if (myArray[i] >= 10 || myArray[i] <= -10)
    {
      myNewArray[counter]= myArray[i];
      counter++;
    }
  }
  cout << endl << "myNewArray: ";
  for (int i = 0; i < counter; i++)
  {
    cout << myNewArray[i] << '\t';
  }
  delete[] myNewArray;
}
