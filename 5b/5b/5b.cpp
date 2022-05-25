
#include <iostream>
#include <cstdlib> 
using namespace std;
int f1(int* mas);
int f2(int* mas);

int main()
{
	int m = 10;
	int* mas = new int[m];
	int(*f)(int* mas);

	for (int i = 0; i < m;i++)
	{
			mas[i] = rand() % 5 -3;
			cout << mas[i]<< " ";
	}
	cout << endl;
	f = f1;
	cout << f(mas)<<endl; //сума
	f = f2;
	cout << f(mas) << endl;//произведение
	return 0;
}

int f1(int* mas)
{
	int r = 0;
	for (int i = 0; i < 10;i++)
	{
		if (mas[i] > 0)
			r += mas[i];
	}
	return r;
}

int f2(int* mas)
{
	int r = 1;
	for (int i = 0; i < 10;i++)
	{
		if (mas[i] < 0)
			r *= mas[i];
	}
	return r;
}