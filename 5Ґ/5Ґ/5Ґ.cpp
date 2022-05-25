
#include <iostream>
#include <cstdlib> 
using namespace std;


void bubbleSort(int *a, const int n);
void nsertion_Sort(int* a, const int n);
void sort(int *a,int flag,int n);
int main()
{
	int m = 10;
	int* mas = new int[m];
	void(*f)(int* a, const int n);

	for (int i = 0; i < m;i++)
	{
		mas[i] = rand() % 5 - 3;
		cout << mas[i] << " ";
	}

	sort(mas, 1, m);
	cout<< "\nsort"<<endl;
	for (int i = 0; i < m;i++)
	{
		cout << mas[i] << " ";
	}

	return 0;
}
void bubbleSort(int *a, const int n)
{
	int buff = 0; // для временного хранения значения, при перезаписи

	for (int i = 0; i < n - 1; i++) // 
	{
		// вложенный цикл проходит от предпоследнего элемента 
		// до первого, находит с помощью if самое "легкое" значение,
		// сравнивая соседние пары элементов,
		// и поднимает его в нулевую ячейку массива
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] <a[j - 1])
			{
				buff = a[j - 1];
				a[j - 1] = a[j];
				a[j] = buff;
			}
		}
		// далее значение i увеличивается на 1
		// и внутренний цикл будет перебирать элементы 
		// от предпоследнего до второго. Таким образом поднимет самое
		// "легкое" значение из оставшихся  в первую ячейку и т.д.
	}
}
void nsertion_Sort(int *a, const int N)
{
	int j;
	int buff = 0;
	for (int i = 1; i < N; i++)
	{
		buff = a[i]; // запомним обрабатываемый элемент
		// и начнем перемещение элементов слева от него
		// пока запомненный не окажется меньше чем перемещаемый
		for ( j = i - 1; j >= 0 && a[j] > buff; j--)
			a[j + 1] = a[j];

		a[j + 1] = buff; // и поставим запомненный на его новое место 
	}
}
void sort(int* a, int flag,int n)
{
	void(*f)(int* a, const int n);
	if (flag == 0)
	{
		f = bubbleSort;
	}
	else
		f = nsertion_Sort;

	f(a,n);
}