//
//  main.cpp
//  lab6
//
//  Created by Mischa Karvasarskyi on 21.04.2022.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int substr(char*, char*, int, int);

int main(void) {

    char *s1, *s2;
    s1 = new char[80];
    s2 = new char[80];
    int n, l, r;
    for (;;) {
        printf("Введите строку >");
        cin >> s1;
        if (!strcmp(s1, "***")) break;
        /* ввод остальных параметров */
        do
        {
            printf("Введите pos>");
            cin >> n;
            if(n < 0)
             cout << "Позиция не может быть отрецательная" << endl;
            else if(strlen(s1) < n)
                cout << "позиция начала больше длины источника" << endl;
        }while (n < 0 || strlen(s1) < n);
        
        do
        {
            printf("Введите len>");
            cin >> l;
            if (l < 0)
                cout << "Длинна не может быть отрицательная" << endl;
        } while (l < 0 );
        
       
        r = substr(s1, s2, n, l);
        printf("pos=%d, len=%d\n", n, l);
        printf("s1=>>%s<<\n", s1);
        printf("s2=>>%s<<\n", s2);
        printf("R=%d\n\n", r);
    }
}
int substr(char* src, char* dest, int pos, int len) {
    int ret;
    for (; pos && *src; pos--, src++);
    if (pos || (len < 0)) ret = -1;
    else {
        for (;len && *src; *dest++ = *src++, len--);
        ret = len ? 1 : 0;
    }
    *dest = 0;
    return ret;
}
