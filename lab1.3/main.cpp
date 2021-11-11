//
//  main.cpp
//  lab1.3
//
//  Created by Mischa Karvasarskyi on 13.10.21.
//

#include <iostream>

int main() {
    int x=1, y=2, z=0;
    z=x;
    x=y;
    y=z;
    z=0;
    int a=1, b=2;
    a = a+b;
    b = a-b;
    a = a-b;
    return 0;
}
