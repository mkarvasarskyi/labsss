#include <cstddef>
#ifndef __LIST_H__
#define __LIST_H__

using namespace std;

struct Str
{
	char name[20];
	char shool;
	unsigned short cnt;
	float sq;
	Str* n; //следущий элемент
	Str* p; //предидущий
	Str() : p(NULL), n(NULL) {}
};
struct list {
	Str* first; //голова списка
	Str* last; // хвост списка

	list() : first(NULL), last(NULL) {}
};

void print(list* l);
void print_end(list* l);
void search(list* l);
void search_end(list* l);
void add(list* l);
void dell(int i, list* l);
void Sort(list* l); 
void print_f(list* l);
void scan_f(list* l);

#endif 
