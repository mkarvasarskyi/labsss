//
//  main.cpp
//  lab8a
//
//  Created by Mischa Karvasarskyi on 17.11.21.
//

#include <iostream>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    int const SIZE = 5;
    int smoking_space[SIZE] = { 1, 2, 3, 4, 5 };
    int no_smoking_space[SIZE] = { 6, 7, 8, 9, 10 };


    cout << "Welcome to booking service UkraineAirLines. " << endl;
    cout << "We have two sitings areas \"smoking space\" and no \"smoking space\". You need to chose one." << endl;


    string answer;
    string smoke("yes");
    string no_smoke("no");

    int book_break = 0;
    int i = 0, j = 0; // arrays` index
    while ( book_break < SIZE*2) {

        cout << "Are you smoking? <yes/no>  ";
        cin >> answer;

        if (cin.fail()){
            cin.clear();
            //cin.ignore(10000, '\n');
            continue;
        }

        if (answer == smoke) {
            if (i < 5) {
                cout << " Place " << smoking_space[i] << " is booked in the smoking space!" << endl;
                i++;
                book_break++;
            }
            else {
                cout << "We are sorry. All sits int smoking area has been reserved." << endl;
            }
        }

        else if (answer == no_smoke) {
            if ( j < 5) {
                cout << " Place " << no_smoking_space[j] << " is booked! in the no smoking space" << endl;
                j++;
                book_break++;
            }
            else {
                cout << "We are sorry. All sits in the no smoking area has been reserved." << endl;
            }
        }
    }

    cout << endl;
    cout << " All sits has been reserved. Please wait or chek for another flight." << endl;
    cout << " Fare you well!" << endl;
    cout << endl << " Sold out!" << endl;
  return 0;
}
