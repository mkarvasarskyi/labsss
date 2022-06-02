#include <iostream>

using namespace std;

void minmax(int& a, int& b, int& c)
{
    int buf;
    if (a< c & c < b | a>c & c>b) //если с не макс и не мин
    {
        buf = a;
        a = b;
        b = buf;
        return;
    }
    if (a < b & b < c | a>b & b>c ) // b не макс и не мин
    {
        buf = a;
        a = c;
        c = buf;
        return;
    }
   //в остальних случаях лишним будет а
      buf = c;
      c = b;
      b = buf;
}

void minmax(int* a, int* b, int* c)
{
    int buf;
    if (a< c & c < b | a>c & c>b)
    {
        buf = *a;
        *a = *b;
        *b = buf;
        return;
    }
    if (a < b & b < c | a>b & b>c)
    {
        buf = *a;
        *a = *c;
        *c = buf;
        return;
    }

    buf = *c;
    *c = *b;
    *b = buf;
}

int main()
{
    int a = 3;
    int b = 2;
    int c = 1;
    minmax(&a, &b, &c);  // передача адреса
    cout << a << endl;
    cout << b << endl;
    cout << c << endl<<endl;

    minmax(a, b, c); // передача ссылки
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
