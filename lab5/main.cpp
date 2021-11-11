//
//  main.cpp
//  lab5
//
//  Created by Mischa Karvasarskyi on 20.10.21.
//

#include <iostream>
using namespace std;

int main()
{
    double x, y;
while (true) {

    printf ("\nВведіть координату х > ");
        scanf ("%lf", &x);
    printf ("Введіть координату y > ");
        scanf ("%lf", &y);

    printf("x =%6.3lf;  y =%6.3lf\n",x,y);

    if ( ((x*x+y*y<=1) && (x<=0 && y<=0)) || ( (x*x+y*y<=1 && y>=0)) )
     printf("Точка належить площині\n");
  else
     printf("Точка не належить площині\n");
}
  return 0;
}

