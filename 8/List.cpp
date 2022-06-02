#include "List.h"
#include <iomanip>
#include <iostream>
using namespace std;

void print(list *l) { // печать списка

	Str* p = l->first; // берем начальний елемент
	while (p) { // и виводим все пока не дойдем до NULL
		cout << setw(20) << left << p->name << " |  ";
		cout << setw(3) << left << p->shool << " |";
		cout << setw(3) << right << p->cnt << " | ";
		cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
		p = p->n; // переход на следущий
	}
	cout << endl;

}
void search(list *l) //поиск по критерию
{
	int x;
	Str* p = l->first;
	cout << "1 - Поиск по названию" << endl; // вибор критерия
	cout << "2 - Поиск по школе" << endl;
	cout << "3 - Поиск по количеству монахов" << endl;
	cout << "4 - Поиск по площади" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		char n[20];
		cout << "Введите название - ";
		cin >> n;
		while (p != NULL) {
			if (strcmp(n, p->name) == 0) //если значение совпадает то виводим запись
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
			}
			p = p->n;
		}
		break;
	case 2:
		char с;
		cout << "Введите школу - ";
		cin >> с;
		while (p) {
			if (с == p->shool)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
			}
			p = p->n;
		}
		break;
	case 3:
		unsigned short i;
		cout << "Введите количество монахов - ";
		cin >> i;
		while (p) {
			if (i == p->cnt)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
			}
			p = p->n;
		}
		break;
	case 4:

		float f;
		cout << "Введите площадь - ";
		cin >> f;
		while (p) {
			if (f == p->sq)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;

			}
			p = p->n;
		}
		break;
	default:;
		break;
	}
}
void add(list *l)
{
	Str* str = new Str();
	cout << "1. Введите: название, школу, количество, площадь >\n"; // ввод
	cin >> str->name;
	cin >> str->shool;
	cin >> str->cnt;
	cin >> str->sq;
	if (l->first == NULL) { //если список пустой
		l->first = str; //записали как первий и последний одновременно
		l->last = str;
		return;
	}
	l->last->n = str; // иначе в ссилку на следущий елемент добавили новий
	l->last = str; // новий стал последним
}
void dell(int i, list *l)
{
	Str* p = l->first;
	Str* pl = p;
	int x = 1;
	while (p) { // ведем счет в цикле с начала
		if (x == i) // когда дошли до елемента с нужним номером
		{
			if (p == l->first) // проверяем первий ли он в списке
			{
				if (l->first == l->last) // проверяем если он единственний
				{
					delete l->first; // то просто удаляем список
					delete l;
					return;
				}
				Str* q = l->first; // если не единственний но первий 
				l->first = q->n; // то укаатель на первий елмент переводим на следующий
				delete q;
				return;
			}
			if (p == l->last) // если последний
			{
				pl->n = NULL; //то предпоследний будет конечний
				l->last = pl; // предпоследний стал последним
				delete p; //удалили 
				return;
			}
			pl->n = p->n; // если он в середнине то соеденяем предпоследний и следующий
			delete p;
			return;

		}
		pl = p; //сохранили предидущий
		p = p->n; // переход на следнующий елемент
		x++;
	}

}
void Sort(list *l) //сортировка списка пузирьком
{
	Str* t, * m, * a, * b;
	if (l == NULL)
		return;

	for (bool go = true; go; ) {
		go = false;
		a = t = l->first; // берем певий 
		b = l->first->n; // и второй елемент

		while (b != NULL) {
			if (a->cnt > b->cnt) { //сотрировка по умешьнению количества монахов
				if (t == a)
					l->first = b;
				else
					t->n = b;

				a->n = b->n;
				b->n = a;

				m = a; //обмен записей местами
				a = b;
				b = m;
				go = true;
			}
			t = a;
			a = a->n;
			b = b->n;
		}
	}

}
void print_f(list *l)
{
	FILE* fp = fopen("f.bin", "a+b");
	Str* p = l->first;
	while (p) //запись в файл в цикле
	{
		fwrite(p, sizeof(Str), 1, fp);
		p = p->n;
	}
	fclose(fp);

}
void scan_f(list *l)
{

	Str* p = new Str();

	FILE* fp = fopen("f.bin", "rb");
	l = new list();

	while (fread(p, sizeof(Str), 1, fp) == 1) //читаем с файла пока считивается 
	{
		if (l->first == NULL) //процес добавления елементов в список
		{
			l->first = p;
			l->last = p;
		}
		else
		{
			l->last->n = p;
			l->last = p;
		}
		p->n = NULL;
		p = new Str();
	}
	fclose(fp);
}