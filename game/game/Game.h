//
//  Game.h
//  game
//
//  Created by Mischa Karvasarskyi on 02.06.2022.
//

//Класс Игра
#pragma once
#include "Player.h"
#include "GameField.h"


//Класс Игра
class Game
{
    Player* player1; //Игрок 1
    Player* player2; //Игрок 2
    GameField* gameField; //Игровое поле

public:

    //Конструктор по умолчанию
    Game()
    {
        //Выделяем динамическую память под поля-переменные класса
        player1 = new Player;
        player2 = new Player;
        gameField = new GameField;
    }
    //Деструктор
    ~Game()
    {
        //Если указатели на поля класса не нулевые, высвобождаем память
        if (player1)
            delete player1;

        if (player2)
            delete player2;

        if (gameField)
            delete gameField;
    }

    //Метод начала игры
    void Start()
    {
        //Вводим символ игрока 1
        string symbol;
        cout << "Символ Player1(0 - нолик, 1 - крестик): ";
        cin >> symbol;

        //Если пользователь ввел некоректный символ, выводим сообщение об ошибке и снова вызываем метод Start()
        if (symbol != "0" && symbol != "1")
        {
            cout << "\nОшибка: некорректный символ!\n\n";
            system("pause"); //Ставим программу на паузу
            system("cls"); //Очищаем консоль

            Start();
        }
        //Иначе(если все ок)
        else
        {
            //Присваиваем символ(крестик и нолик игрокам)
            player1->SetSymbol((symbol == "0") ? 0 : 1);
            player2->SetSymbol((symbol == "0") ? 1 : 0);

            string name;

            //Вводим имена игроков
            cout << "\nИмя Player1: ";
            cin >> name;
            player1->SetName(name);

            cout << "\nИмя Player2: ";
            cin >> name;
            player2->SetName(name);
        }
    }

    //Метод "Ход игрока"
    void Turn(Player* player)
    {
        int row, column;

        //Вводим номера строки и столбца клетки, в которую мы хотим поставить символ
        cout << endl << player->GetName() << ", выберите клетку(строка, столбец): ";
        cin >> row;
        cin >> column;

        //Если пользователь ввел допустимые номера строки и столбца
        if ((row > 0 && row <= 3) && (column > 0 && column <= 3))
        {
            //Если клетка, номер которой указал пользователь, пустая, то устанавливаем в ней крестик или нолик
            if (gameField->GetField()[row - 1][column - 1] == " ")
            {
                gameField->SetSymbol(player->GetSymbol(), row - 1, column - 1);
            }
            //Иначе(если пользователь ввел номер клетки, в которой уже установлен символ), выводим сообщение об ошибке и снова вызываем метод Turn(player);
            else
            {
                cout << "\nОшибка: в данной клетке уже установлен символ!\n";
                Turn(player);
            }
        }
        //Иначе(если пользователь ввел некорректные номера строки или столбца)
        else
        {
            cout << "\nОшибка: некорректная строка или столбец!\n";
            Turn(player);
        }
    }

    //Метод проверки победы игрока
    bool Win(Player* player)
    {
        for (int i = 0; i < 3; ++i)
        {
            //Если все элементы i-ой строки являются символом игрока(крестик или нолик), возвращаем true, что означает победу данного игрока
            if (gameField->GetField()[i][0] == player->GetSymbol() &&
                gameField->GetField()[i][1] == player->GetSymbol() &&
                gameField->GetField()[i][2] == player->GetSymbol())
            {
                return true;
            }
            //Иначе, если все элементы i-го столбца являются символом игрока(крестик или нолик), возвращаем true, что означает победу данного игрока
            else if (gameField->GetField()[0][i] == player->GetSymbol() &&
                gameField->GetField()[1][i] == player->GetSymbol() &&
                gameField->GetField()[2][i] == player->GetSymbol())
            {
                return true;
            }
        }

        //Проверка на одинаковые символы по диагонали с левого верхнего угла в правый нижний угол
        if (gameField->GetField()[0][0] == player->GetSymbol() &&
            gameField->GetField()[1][1] == player->GetSymbol() &&
            gameField->GetField()[2][2] == player->GetSymbol())
        {
            return true;
        }
        //Проверка на одинаковые символы по диагонали с правого верхнего угла в левый нижний угол
        else if (gameField->GetField()[0][2] == player->GetSymbol() &&
            gameField->GetField()[1][1] == player->GetSymbol() &&
            gameField->GetField()[2][0] == player->GetSymbol())
        {
            return true;
        }

        //Если дошли до этого момента, значит игрок не выиграл, поэтому возвращаем false
        return false;
    }

    void Play()
    {
        Start();

        const int maxTurnNumber = 9; //Максимальное количество ходов = 9
        Player* currentPlayer;

        for (int i = 0; i <= maxTurnNumber; ++i)
        {
            /* Если уже совершено максимальное количество ходов, значит результат игры - Ничья,
            выводим сообщение об этом и выходим из метода(то есть, завершаем программу) */
            if (i == maxTurnNumber)
            {
                gameField->Print();
                gameField->WriteToFile(player1, player2);
                cout << "\nНичья!\n\n";
                system("pause");
                system("cls");
                return;
            }

            //Если сейчас четный номер хода, значит сейчас ход игрока 1
            if (i % 2 == 0)
            {
                currentPlayer = player1;
            }
            //Иначе, сейчас ход игрока 2
            else
            {
                currentPlayer = player2;
            }

            gameField->Print(); //Выводим игровое поле
            gameField->WriteToFile(player1, player2); //Записываем игровое поле в файл

            Turn(currentPlayer); //Текущий игрок совершает ход

            //Если текущий игрок выиграл, выводим сообщение об этом и выходим из метода(то есть, завершаем программу)
            if (Win(currentPlayer))
            {
                gameField->Print();
                gameField->WriteToFile(player1, player2);
                cout << "\nПоздравляем, " << currentPlayer->GetName() << "! Вы победили!\n\n";
                system("pause");
                system("cls");
                return;
            }
        }
    }
};
