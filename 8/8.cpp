#include <iostream>
#include <stdio.h>
#include <cstdlib> 
#include <iomanip>
#include<io.h>
#include <fcntl.h>
#include <time.h>
#include "List.h"

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "");

	int x = 1;
	list* l = NULL;
	

	while (true)
	{
		cout << "1 - Создание списка" << endl;
		cout << "2 - Печать списка" << endl;
		cout << "3 - Поиск по критерию" << endl;
		cout << "4 - Добавить элемент " << endl;
		cout << "5 - Удалить элемент" << endl;
		cout << "6 - Сортировка" << endl;
		cout << "7 - Запись списка в файл" << endl;
		cout << "8 - Чтение списка из файла" << endl;
		cout << "9 - Выход" << endl;
		cin >> x;
		switch (x)
		{
		case 1: l = new list();

			break;
		case 2:print(l);
			break;
		case 3:search(l);
			break;
		case 4:add(l);
			break;
		case 5: cout << "Введите номер записи - ";
			cin >> x;
			dell(x,l);
			break;
		case 6:Sort(l);
			break;
		case 7: print_f(l);
			break;
		case 8: scan_f(l);
			break;
		case 9:exit(0);
			break;
		default:;
			break;
		}
	}
	
	return 0;
}

