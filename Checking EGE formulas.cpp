#include <iostream>                                             // Для операторов cin и cout
#include <ctime>                                                // Для функции srand() которая помогает делать реальный рандомайзер
#include <cmath>                                                // Для математических операторов
#include <string>
using namespace std;

struct Formula
{
    string formula;
    string answer;
};

int main_menu()                                                 // Функция которая выводит главное меню
{
    int choice_mm;
    cout << "\033[2J\033[1;1H";
    cout << "\"Генератор заданий ЕГЭ: математика\"\n" << endl;
    cout << "Выберите действие:" << endl;
    cout << "1. Сгенерировать формулы по темам" << endl;
    cout << "2. Сгенерировать все формулы" << endl << endl;
    cout << "0. Выход" << endl << endl;
    cout << "Ваш выбор: ";
    cin >> choice_mm;
    return choice_mm;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int count_task[70];              // Создает массив из номеров заданий
    for (int i = 0; i < 70; i++)     // Обнуляет количество заданий в номерах
        count_task[i] = 0;
    int choice = 0;
    string Answers = "";
    do{
        choice = main_menu();
        switch(choice)
        {
            case(1):
            {
                do{
                    cout << "\033[2J\033[1;1H";
                    cout << "Выберите темы:" << endl;
                    cout << "1. Алгебраические выражения (" << count_task[0] + count_task[1] + count_task[2] + count_task[3] + count_task[4] + count_task[5] + count_task[6] + count_task[7] + count_task[8] + count_task[9] << ")" << endl;
                    cout << endl << "69. Сгенерировать" << endl;
                    cout << "0. Выход" << endl;
                    cout << "Ваш выбор: ";
                    cin >> choice;
                    switch(choice)
                    {
                        case 1:
                        do{
                            cout << "\033[2J\033[1;1H";
                            cout << "Выберите темы:" << endl;
                            cout << "1. Разложение на множители и ФСУ   (" << count_task[0] + count_task[1] << ")" << endl;
                            cout << "2. Степени   (" << count_task[2] + count_task[3] << ")" << endl;
                            cout << "3. Корни   (" << count_task[4] + count_task[5] << ")" << endl;
                            cout << "4. Логарифмы   (" << count_task[6] + count_task[7] << ")" << endl;
                            cout << "5. Весь раздел   (" << count_task[8] + count_task[9] << ")" << endl;
                            cout << "0. Выход" << endl;
                            cout << "Ваш выбор: ";
                            cin >> choice;
                            switch(choice)
                            {
                                case 1:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[0] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[1] << ")" << endl;
                                    cout << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[0];
                                            break;

                                        case 2:
                                            count_task[1] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 2:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[2] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[3] << ")" << endl;
                                    cout << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[2];
                                            break;

                                        case 2:
                                            count_task[3] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 3:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[4] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[5] << ")" << endl;
                                    cout << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[4];
                                            break;

                                        case 2:
                                            count_task[5] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 4:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[6] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[7] << ")" << endl;
                                    cout << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[6];
                                            break;

                                        case 2:
                                            count_task[7] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;

                                case 5:
                                do{
                                    cout << "\033[2J\033[1;1H";
                                    cout << "1. Произвольное количество   (" << count_task[8] << ")" << endl;
                                    cout << "2. Все целиком   (" << count_task[9] << ")" << endl;
                                    cout << "0. Выход" << endl;
                                    cout << "Ваш выбор: ";
                                    cin >> choice;
                                    switch(choice)
                                    {
                                        case 1:
                                            cout << "\033[2J\033[1;1H";
                                            cout << "Введите количество формул: ";
                                            cin >> count_task[8];
                                            break;

                                        case 2:
                                            count_task[9] = 1;
                                            break;
                                    }
                                }while(choice != 0);
                                choice = -1;
                                break;
                            }
                        }while(choice != 0);
                        choice = -1;
                        break;
                    }
                }while(choice != 0);
                choice = -1;
                break;
            }
        }
    }while(choice != 0);
    return 0;
}