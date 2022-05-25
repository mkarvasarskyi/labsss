
#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
	const int a = 10;
	int b = 0, c = 0, d = 0; // количество елементов в масивах B C D

	int masa[a];
	int* masb = NULL, *masc = NULL, *masd = NULL; // указатели на 3 масива
	

	cout << "mas A\n";
	for (int i = 0; i < a; i++)
	{
		masa[i] = rand() % 5 - 3;
		cout << masa[i] << " ";
		if (masa[i] > 0) // если больше нуля
		{
			c++;
			masc = (int*) realloc(masc, c * 4); // виделили память под число
			masc[c - 1] = masa[i];  //записали в масив
		}
			
		else if (masa[i] < 0)
		{
			b++;
			masb = (int*)realloc(masb, b * 4);
			masb[b - 1] = masa[i];
		}
		else 
		{
			d++;
			masd = (int*)realloc(masd, c * 4);
			masd[d - 1] = masa[i];
		}
	}
	cout << "\nmas B\n";
	for(int i = 0; i < b;i++)
		cout << masb[i] << " ";

	cout << "\nmas C\n";
	for (int i = 0; i < c;i++)
		cout << masc[i] << " ";

	cout << "\nmas D\n";
	for (int i = 0; i < d;i++)
		cout << masd[i] << " ";

	
	for (int i = 0; i < a; i++) // перезапись масива А
	{
		if (i < d)
		{
			masa[i] = masd[i]; // сначала D
		}
			
		else if ((i - d) < b)
		{
			masa[i] = masb[i - d]; // потом B
		}	
		else
		{
			masa[i] = masc[(i - d) - b]; // C в конце
		}
			

	}

	cout << "\nmas A\n";
	for (int i = 0; i < a; i++)
	{
		cout << masa[i] << " ";
	}


	return 0;
}
