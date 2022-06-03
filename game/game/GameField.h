//
//  GameField.h
//  game
//
//  Created by Mischa Karvasarskyi on 02.06.2022.
//
#pragma once
#include <iostream>
#include <fstream>

using namespace std;


//Класс Игровое поле
class GameField
{
    string** field; //Указатель на указатель на строку field(для последующего создания двумерного массива размером 3x3 в динамической памяти)

public:

    //Конструктор без параметров
    GameField()
    {
        //Создаем в динамической памяти двумерный массив размером 3х3
        field = new string * [3];
        for (int i = 0; i < 3; ++i)
            field[i] = new string[3];

        //Заполняем только что созданный двумерный массив символом пробела
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                field[i][j] = " ";
    }
    //Деструктор
    ~GameField()
    {
        //Если указатель на field не нулевой
        if (field)
        {
            //Циклом высвобождаем динамическую память, ранее выделенную под field(по анологии с выделением памяти)
            for (int i = 0; i < 3; ++i)
                //Если указатель на field[i] не нулевой
                if (field[i])
                    delete[] field[i];

            delete[] field;
        }
    }

    //Метод вывода в консоль игрового поля
    void Print()
    {
        system("cls"); //Очищаем консоль

        //Циклом выводим игровое поле
        cout << "\n      1   2   3\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << "    -------------\n  " << i + 1 << " | ";
            for (int j = 0; j < 3; ++j)
            {
                //В каждую клетку поля выводим значение соответствующей клетки(O или Х или " ")
                cout << field[i][j] << " | ";
            }
            cout << endl;
        }
        cout << "    -------------\n";
    }
    
    //Метод записи хода игры в файл
    void WriteToFile(Player* p1, Player* p2)
    {
        //Создаем и открываем файл tic-tac-toe.txt в папке программы
        ofstream ofs("tic-tac-toe.txt");

        //Записываем в файл данные о игроках(имя, символ)
        ofs << "Player1: Имя - " << p1->GetName() << ", Символ - " << p1->GetSymbol();
        ofs << "\nPlayer2: Имя - " << p2->GetName() << ", Символ - " << p2->GetSymbol();

        //Циклом записываем игровое поле в файл
        ofs << "\n\n      1   2   3\n";
        for (int i = 0; i < 3; ++i)
        {
            ofs << "    -------------\n  " << i + 1 << " | ";
            for (int j = 0; j < 3; ++j)
            {
                //В каждую клетку поля записываем значение соответствующей клетки(O или Х или " ")
                ofs << field[i][j] << " | ";
            }
            ofs << endl;
        }
        ofs << "    -------------\n";
    }

    //Метод "Гетер" для получения значения field
    string** GetField()
    {
        return field;
    }

    //Метод "Сетер" для присваивания значения клетке поля, которая находится в строке row и столбце column
    void SetSymbol(string symbol, int row, int column)
    {
        field[row][column] = symbol;
    }
};
