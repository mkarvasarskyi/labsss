#include <cstdlib> 
#include <iostream>

void f1(int* p,int c)
{
	
	for (int i = 0; i < c; i++)
	{
		p[i] = rand() % 11+ 5;
		
	}
}
int* f2(int* p, int c)
{
	int* mas = NULL; // пустой укзатель
	int s = 0;
	
	for(int i = 0; i < c;i++)
		if (p[i] > 9 && p[i] << 100) // если меньше 100 и больше 9
		{
			s++;
			mas = (int*)realloc(mas, s * 4); // добавляем память на еще одно число
			mas[s - 1] = p[i];
			std::cout << p[i] << " ";
		}
	return mas; // возврат нового масива

}