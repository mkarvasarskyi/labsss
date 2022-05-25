
#include <iostream>


using namespace std;

void f1(int* p,int c);
int * f2(int* p, int c);
int main()
{
	const int a = 10;
	int* mas  = new int[a];
	int* mass;

	f1(mas, a);
	cout << "mas A\n";
	for (int i = 0; i < a; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	mass = f2(mas, a);

	return 0;
}
