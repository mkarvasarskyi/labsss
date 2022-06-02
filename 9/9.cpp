#include <iostream>
#include <stdio.h>
#include <cstdlib> 
#include <iomanip>
#include<io.h>
#include <fcntl.h>
#include <time.h>
#include "List.h"




int main()
{
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "");

	int x = 1;
	list* l = NULL;

	while (true)
	{
		cout << "1 - Создание списка" << endl;
		cout << "2 - Печать списка с начала" << endl;
		cout << "3 - Печать списка с конца" << endl;
		cout << "4 - Поиск по критерию с начала" << endl;
		cout << "5 - Поиск по критерию с конца" << endl;
		cout << "6 - Добавить элемент " << endl;
		cout << "7 - Удалить элемент" << endl;
		cout << "8 - Сортировка" << endl;
		cout << "9 - Запись списка в файл" << endl;
		cout << "10 - Чтение списка из файла" << endl;
		cout << "11 - Выход" << endl;
		cin >> x;
		switch (x)
		{
		case 1: l = new list();
			break;
		case 2:print(l);
			break;
		case 3:print_end(l);
			break;
		case 4:search(l);
			break;
		case 5:search_end(l);
			break;
		case 6: add(l);
			break;
		case 7:cout << "Введите номер записи - ";
			cin >> x;
			dell(x,l);;
			break;
		case 8: Sort(l);
			break;
		case 9: print_f(l);
			break;
		case 10: scan_f(l);
			break;
		case 11:exit(0);
			break;
		default:;
			break;
		}
	}

	return 0;
}

