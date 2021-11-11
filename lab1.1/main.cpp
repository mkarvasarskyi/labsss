//
//  main.cpp
//  lab1.1
//
//  Created by Mischa Karvasarskyi on 13.10.21.
//

#include <iostream>
#include <math.h>
int main() {
    int a=3, b=4, c=5, p, s;
    p = (a+b+c)/2;
    s = p*(p-a)*(p-b)*(p-c);
    s = sqrt(s);
    return 0;
}
