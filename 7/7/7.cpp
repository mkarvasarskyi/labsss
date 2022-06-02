#include <iostream>
#include <stdio.h>
#include <cstdlib> 
#include <iomanip>
#include<io.h>
#include <fcntl.h>
#include <time.h>
using namespace std;
static int file;
struct Str
{
	char name[20];
	char shool;
	unsigned short cnt;
	float sq;
};
void sfile_set() // перезаписиваем все записи на шаг вперед
{
	Str str;
	int count = _filelength(file) / sizeof(str);

	count--;
	_lseek(file, (count)* sizeof(str), SEEK_SET);
	count--;
	while (count>=-1)
	{
		_read(file, &str, sizeof(str));
		_write(file, &str, sizeof(str));
		_lseek(file, count* sizeof(str), SEEK_SET);
		count--;
	}
	

}
void sfile(Str str)
{
	_lseek(file, 0, SEEK_END);

	_write(file, &str, sizeof(str));

}
void in(bool rnd)
{
	Str str;


	if (rnd)
	{
		str.cnt = rand() % 5 + 17; ///случайно заполняем все поля
		str.shool = char(rand() % 26 + 0x61);
		str.sq = (float)(rand()) / RAND_MAX * (1.24 - 0.62) + 0.62;

		for (int i = 0; i < 19;i++)
		{
			str.name[i] = char(rand() % 27 + 0x60);
		}
		str.name[19] = '\0';
	}
	else
	{
		cout << "1. Введите: название, школу, количество, площадь >\n";
		cin >> str.name;
		cin >> str.shool;
		cin >> str.cnt;
		cin >> str.sq;
	}
	_write(file, &str, sizeof(str));

}
void inputs(bool start)
{
	Str str;
	if (start)
	{
		sfile_set();
	}

	cout << "1. Введите: название, школу, количество, площадь >\n";
	cin >> str.name;
	cin >> str.shool;
	cin >> str.cnt;
	cin >> str.sq;
	
	if (start)
	{
		_lseek(file, 0, SEEK_SET);
		_write(file, &str, sizeof(str));
	}	
	else
	{
		sfile(str);
	}
}
void prints(int x)
{
	cout << endl;
	long t;
	Str str;
	t = x - 1; t *= sizeof(str);
	_lseek(file, t, SEEK_SET);
	_read(file, &str, sizeof(str));
	//вивод одной записи
	cout << setw(20) << left << str.name << " |  ";
	cout << setw(3) << left << str.shool << " |";
	cout << setw(3) << right << str.cnt << " | ";
	cout << setw(5) << setprecision(1) << str.sq << " |" << endl;

}
void printsall()
{
	cout << endl;
	Str str;
	_lseek(file, 0, SEEK_SET);
	while (_read(file, &str, sizeof(str))) // вивод всех записей
	{
		cout << setw(20) << left << str.name << " |  ";
		cout << setw(3) << left << str.shool << " |";
		cout << setw(3) << right << str.cnt << " | ";
		cout << setw(5) << setprecision(1) << str.sq << " |" << endl;
	}

}
int main()
{
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "");

	int x=1;

	if (_access("f.bin", 0) < 0) // несуществующий файл - создать 
		file = _creat("f.bin", S_IREAD | S_IWRITE);	
	else // существующий файл - открыть 
		file = _open("f.bin", O_RDWR | O_BINARY);

	while (x != 7)
	{
		cout << "1 - Ввод с экрана и запись в файл" << endl;
		cout << "2 - Ввод случайным образом и запись в файл" << endl;
		cout << "3 - Добавить запись в начало файла" << endl;
		cout << "4 - Добавить запись в конец файла" << endl;
		cout << "5 - Печать одной записи из файла по номеру" << endl;
		cout << "6 - Чтение всех структур последовательно из файла и печать" << endl;
		cout << "7 - Выход из программы" << endl;
		cin >> x;
		switch (x)
		{
		case 1: in(false);
			break;
		case 2:in(true);
			break;
		case 3:inputs(true);
			break;
		case 4:inputs(false);
			break;
		case 5: cout<<"Введите номер записи - ";
			cin >> x;
			prints(x);
			break;
		case 6:printsall();
			break;
		case 7:break;
			break;
		default:;
			break;
		}
	}
	_close(file);
	return 0;
}

