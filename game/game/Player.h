//
//  Player.h
//  game
//
//  Created by Mischa Karvasarskyi on 02.06.2022.
//

#pragma once
#include <string>

using namespace std;


//Класс Игрок
class Player
{
    string name; //Имя
    bool symbol; //Символ(0 - нолик, 1 - крестик)

public:

    //Конструктор по умолчанию(без параметров)
    Player()
    {
        name = "";
        symbol = 0;
    }
    //Конструктор с параметрами
    Player(string name, bool symbol)
    {
        this->name = name;
        this->symbol = symbol;
    }

    //Методы "Гетеры" для получения значений приватных полей класса
    string GetName()
    {
        return name;
    }
    string GetSymbol()
    {
        return (symbol == 0) ? "O" : "X";
    }

    //Методы "Сетеры" для присваивания значений приватным полям класса
    void SetName(string name)
    {
        if (name != "")
            this->name = name;
    }
    void SetSymbol(bool symbol)
    {
        this->symbol = symbol;
    }
};
