#include <iostream>
#include "Supplier.h"

int Check_choice();
///----------------------+В этой серии+----------------------///

///1)                Использование итераторов
///2)              Удаление n-го элемента
///3)     Добавление элементов в начало/конец/на n-нную позицию
///4)     Использовать STL list для хранения и обработки данных


int showMenu()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {

        std::cout<<std::endl;
        std::cout << "____________________МЕНЮ____________________" << std::endl;
        std::cout << " 1.      Вывести бАзУ" << std::endl;
        std::cout << " 2.      Добавить новое что-то" << std::endl;
        std::cout << " 3.      Удалить объект" << std::endl;
        std::cout << " 4.      Найти информацию по названию фирмы" << std::endl;
        std::cout << " 5.      Рассортировать это по уменьшению sAldO" << std::endl;
        std::cout << " 6.      Сохранить все новые поля на диск и выйти из программы" << std::endl;
        std::cout<<std::endl;
        std::cout << "Введите число [1 , 6]" << std::endl;
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <= 0) or (a>5)) // если предыдущее извлечение оказалось неудачным
        {
            std::cout<<"НЕПРАВИЛЬНЫЙ ВВОД В МЕНЮ"<<std::endl;
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a

            return a;
    }
}

int Supplier::count = 0; //для чтения из файла
int Supplier::the_longest_Address = 10; //для таблицы
int Supplier::the_longest_Name = 10; //для таблицы

int main() {
    setlocale(LC_ALL,"rus");
    Supplier element ;
    element.readDataFromDisk();

    int a;
    do {

        a = showMenu();

        switch (a)
        {
            case 1: //вывести то что написали щас
                element.showData();
                break;

            case 2: //добавить новый товар
                element.setData(Check_choice());
                element.showData();
                break;

            case 3:
                element.deleteElement(element.Special_check2());
                element.showData();
                break;

            case 4: //Найти товар по названию
                element.searchByName();
                break;

            case 5: //Рассортировать это по уменьшению sAldO
                element.sort();
                break;

            case 6: //Сохранить всё и завершить работу
                element.saveDataOnDisk();
                break;

            default:
                std::cout<<"Неверно введен номер действия"<<std::endl;
                break;

        }

    } while (a != 6);

    return 0;
}