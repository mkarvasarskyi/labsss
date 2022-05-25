
#include <iostream>
#include <cstdlib> 
using namespace std;
int f(int* a);
int main()
{
	const int c = 10;
	int mas[c];
	int sum = 0;

	for (int i = 0; i < c; i++)
	{
		mas[i] = rand()%5-3; 
		cout << mas[i]<<" ";
	}
	///
	for (int i = 0; i < c; i++)
	{
		if (mas[i] < 0)
			sum += mas[i];
	}
	cout <<"\nSuma = "<<sum<<endl;
	sum = 0;

	for (int i = 0; i < c; i++)
	{
		if (*(mas+i) < 0)
			sum += *(mas + i);
	}
	cout << "\nSuma = " << sum << endl;
	sum = 0;

	for (int* ptr = mas; ptr <= &mas[c-1]; ptr++)
	{
		if (*ptr < 0)
			sum +=*ptr;
	}
	cout << "\nSuma = " << sum << endl;
	sum = 0;

	int* masp[c];
	for (int i = 0; i < c;i++)
		masp[i] = &mas[i];
	for (int i = 0; i < c; i++)
	{
		if (*masp[i] < 0)
			sum += *masp[i];
	}
	cout << "\nSuma = " << sum << endl;
	sum = 0;

	int * y= mas;
	for (int i = 0; i < c; i++)
	{
		if (*(y+i)< 0)
			sum += *(y + i);
	}
	cout << "\nSuma = " << sum << endl;

	sum = f(mas);
	cout << "\nSuma = " << sum << endl;

	return 0;
}
int f(int* a)
{
	int suma = 0;
	for (int i = 0; i < 10; i++)
	{
		if (*(a + i) < 0)
			suma += *(a + i);
	}
	return suma;
}