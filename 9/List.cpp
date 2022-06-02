#include "List.h"
#include <string.h>
#include <iomanip>
#include <iostream>

void print(list* l) { // печать с начала списка

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
void print_end(list* l) { // печать с начала списка

	Str* p = l->last; // берем начальний елемент
	while (p) { // и виводим все пока не дойдем до NULL
		cout << setw(20) << left << p->name << " |  ";
		cout << setw(3) << left << p->shool << " |";
		cout << setw(3) << right << p->cnt << " | ";
		cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
		p = p->p; // переход на следущий
	}
	cout << endl;

}
void search(list* l)
{
	int x;
	Str* p = l->first;
	cout << "1 - ѕоиск по названию" << endl;
	cout << "2 - ѕоиск по школе" << endl;
	cout << "3 - ѕоиск по количеству монахов" << endl;
	cout << "4 - ѕоиск по площади" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		char n[20];
		cout << "¬ведите название - ";
		cin >> n;
		while (p != NULL) {
			if (strcmp(n, p->name) == 0)
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
		cout << "¬ведите школу - ";
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
		cout << "¬ведите количество монахов - ";
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
		cout << "¬ведите площадь - ";
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
void search_end(list* l)
{
	int x;
	Str* p = l->last;
	cout << "1 - ѕоиск по названию" << endl;
	cout << "2 - ѕоиск по школе" << endl;
	cout << "3 - ѕоиск по количеству монахов" << endl;
	cout << "4 - ѕоиск по площади" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		char n[20];
		cout << "¬ведите название - ";
		cin >> n;
		while (p != NULL) {
			if (strcmp(n, p->name) == 0)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
			}
			p = p->p;
		}
		break;
	case 2:
		char с;
		cout << "¬ведите школу - ";
		cin >> с;
		while (p) {
			if (с == p->shool)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
			}
			p = p->p;
		}
		break;
	case 3:
		unsigned short i;
		cout << "¬ведите количество монахов - ";
		cin >> i;
		while (p) {
			if (i == p->cnt)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;
			}
			p = p->p;
		}
		break;
	case 4:

		float f;
		cout << "¬ведите площадь - ";
		cin >> f;
		while (p) {
			if (f == p->sq)
			{
				cout << setw(20) << left << p->name << " |  ";
				cout << setw(3) << left << p->shool << " |";
				cout << setw(3) << right << p->cnt << " | ";
				cout << setw(5) << setprecision(1) << p->sq << " |" << endl;

			}
			p = p->p;
		}
		break;
	default:;
		break;
	}
}
void add(list* l)
{
	Str* str = new Str();
	cout << "1. ¬ведите: название, школу, количество, площадь >\n";
	cin >> str->name;
	cin >> str->shool;
	cin >> str->cnt;
	cin >> str->sq;
	if (l->first == NULL) {
		l->first = str;
		l->last = str;
		return;
	}
	str->p = l->last;
	l->last->n = str;
	l->last = str;
}
void dell(int i, list* l)
{
	Str* p = l->first;
	Str* pl = p;
	int x = 1;
	while (p) {
		if (x == i)
		{
			if (p == l->first)
			{
				if (l->first == l->last)
				{
					delete l->first;
					delete l;
					return;
				}
				
				l->first = p->n;
				l->first->p = NULL;
				delete p;
				return;
			}
			if (p == l->last)
			{
				pl->n = NULL;
				l->last = pl; 
				delete p; 
				return;
			}
			pl->n = p->n;
			delete p;
			return;

		}
		pl = p;
		p = p->n;
		x++;
	}

}
void Sort(list* l) //сортировка списка пузирьком
{
	Str* t, * m, * a, * b;
	if (l == NULL)
		return;

	for (bool go = true; go; ) {
		go = false;
		a = t = l->first;
		b = l->first->n;

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
void print_f(list* l)
{
	FILE* fp = fopen("f.bin", "a+b");
	Str* p = l->first;
	while (p)
	{
		fwrite(p, sizeof(Str), 1, fp);
		p = p->n;
	}
	fclose(fp);

}
void scan_f(list* l)
{

	Str* p = new Str();

	FILE* fp = fopen("f.bin", "rb");
	l = new list();

	while (fread(p, sizeof(Str), 1, fp) == 1)
	{
		if (l->first == NULL)
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
