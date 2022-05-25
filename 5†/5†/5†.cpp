
#include <iostream>
#include <cstdlib> 
using namespace std;
int* f1(int** mas, int* masmin, int *masmax, int*sum, int *dob);
int main()
{
	int m = 3;
	int** mas;
	int* mas2;
	int* masmin = new int[m];// масив минимальних в столбах
	int* masmax = new int[m]; // максимальние в строках
	int* sum = NULL; // сума
	int* dob = NULL; // произведение

	mas = new int* [m];
	for (int i = 0; i < m;i++)
		mas[i] = new int [m];
	
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < m;j++)
		{
			mas[i][j] = rand() % 76 + 12;
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	mas2 = f1(mas, masmin, masmax, sum, dob);

	
	cout << "\nmasmin"<<endl;
	for (int i = 0; i < m;i++)
	{
		cout << masmin[i] << " ";
	}
	cout << "\nmasmax" << endl;
	for (int i = 0; i < m;i++)
	{
		cout << masmax[i] << " ";
	}
	cout << endl<<"sum   dob\n";
	cout << mas2[0] << "   " << mas2[1];


	return 0;
}
int* f1(int** mas, int* masmin, int* masmax, int* sum, int* dob)
{
	int min,max;
	int summ = 0, dobb= 1;
	int* mas2 = new int[2];
	for (int i = 0; i <3;i++)
	{
		min = mas[0][i];
		max = mas[i][0];
		for (int j = 0; j < 3;j++)
		{
			if (min > mas[j][i]) //ищем минимальний в столбе
				min = mas[j][i];
			if (max < mas[i][j]) // и максимальний в строке
				max = mas[i][j];
		}
		masmin[i] = min;
		masmax[i] = max;

	}
	for (int i = 0; i < 3;i++)
	{
		summ += mas[i][i]; // сума по главной диагонали
		dobb *= mas[i][3 - 1 - i]; //произвидение по побочной
	}
	sum = &summ; // записали адреса суми и произведения
	dob = &dobb;
	mas2[0] = summ; // записали в масив суму и произведения
	mas2[1] = dobb;
		
	return mas2;
}