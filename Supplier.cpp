#include "Supplier.h"
#include "StreamTable.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

int CheckDay();
int CheckYear();
int CheckType();
double CheckSaldo();
std::string CheckMonth();
std::string CheckName();
std::string CheckCountry();
std::string CheckCity();
std::string CheckBuilding();

Supplier& Supplier::operator=(const Supplier &equal) {
    if (this == &equal)
        return *this;

    name = equal.name;
    type_of_supplier = equal.type_of_supplier;
    saldo = equal.saldo;

    address_class=equal.address_class;
    date_class=equal.date_class;

    return *this;
}

std::istream& operator>> (std::istream &in, Supplier* Obj){

    in >> Obj->name;
    return in;
}

void Supplier::setData(int some_case)
{

/////////~for Supplier~/////////

    this->name=CheckName(); //вот так надо
    this->saldo=CheckSaldo();
    int current_type = CheckType();
    this->type_of_supplier = (current_type == 1 ? Supplier::RAW_MATERIAL_SUPPLIER : Supplier::EQUIPMENT_SUPPLIER);

/////////~for Address~/////////
    this->address_class.country = CheckCountry();
    this->address_class.city = CheckCity();
    this->address_class.building_number=CheckBuilding();

/////////~for Date~/////////

    this->date_class.day = CheckDay();
    this->date_class.month = CheckMonth();
    this->date_class.year = CheckYear();


    if (some_case==1){Array.push_front(*this);}//добавление в начало
    else if (some_case==2){Array.push_back(*this);}//добавление в конец
    else
    {
        int position;
        std::cout<<"На какое место поставить этот объект?"<<std::endl;
        std::cout<<"Доступные позиции: [1,"<< Array.size()+1 <<"]"<<std::endl;
        position = Special_check();

        //кароче: я ставлю итератор на начало списка
        auto it = Array.begin();
        //а потом передвигю на позицию ПЕРЕД нужной
        advance(it, position-1);
        //а тут кладу на нужную позицию кладу все как надо
        Array.insert(it,*this);
    }

    if ((this->address_class.show_full_address()).length()>Supplier::the_longest_Address){Supplier::the_longest_Address = (this->address_class.show_full_address()).length();}
    if ((this->name).length()>Supplier::the_longest_Name){Supplier::the_longest_Name = (this->name).length();}
}

Supplier::Supplier()
{
    name = "Adidas";
    type_of_supplier = Supplier::EQUIPMENT_SUPPLIER;
    saldo = -193.2;
    address_class.country = "Russia";
    address_class.city = "Moscow";
    address_class.building_number = "1243b";
    date_class.year = 2022;
    date_class.month = "May";
    date_class.day = 13;
}
int Supplier::Special_check() const {
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Число: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a>Array.size()+1)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

////////оп оп оп////////


void Supplier::showData() const
{

    StreamTable st(std::cout);
    st.AddCol(the_longest_Name+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(10);
    st.AddCol(10);
    st.AddCol(30);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "NAME" << "ADDRESS" << "TYPE" << "SALDO"<<"DATE";
    for(auto & i : Array){
        st<<i.name<< i.address_class.show_full_address()<< i.type_of_supplier << i.saldo <<i.date_class.show_pretty_date() ;
    }


}

void Supplier::searchByName() const {


    std::string wanted_name = CheckName();

    StreamTable st(std::cout);
    st.AddCol(Supplier::the_longest_Name+2);
    st.AddCol(Supplier::the_longest_Address+2);
    st.AddCol(10);
    st.AddCol(10);
    st.AddCol(30);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "NAME" << "ADDRESS" << "TYPE" << "SALDO" << "DATE";

    bool no_any = true;
    for (auto & j : Array)
    {
        if (j.name == wanted_name)
        {
            st << j.name << j.address_class.show_full_address() << j.type_of_supplier << j.saldo << j.date_class.show_pretty_date() ;
            no_any=false;
        }
    }
    if (no_any)
    {
        st << "name"  << "address" << "0" << "0" << "dd.mm.yyyy";
        std::cout<<"В базе нет такого"<<std::endl;
    }
}

#include "Compare_down.h"
void Supplier::sort() const {
//// сортировка пузырьком МОЯ ЛЮБИМАЯ АООАО
    std::vector<Supplier>tmp;

    for (auto & i : Array){tmp.push_back(i);} //типа заполняю вектор

    std::sort(tmp.begin(),tmp.end(),Compare_down()); //сортирую вектор

    //вывожу вектор
    StreamTable st(std::cout);
    st.AddCol(the_longest_Name+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(10);
    st.AddCol(10);
    st.AddCol(30);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    st << "NAME" << "ADDRESS" << "TYPE" << "SALDO"<<"DATE";
    for(auto & i : tmp){
        st<<i.name<< i.address_class.show_full_address()<< i.type_of_supplier << i.saldo <<i.date_class.show_pretty_date() ;
    }

}


std::ofstream record; //поток для записи в файл
void Supplier::saveDataOnDisk() const
{
    record.open("file.txt"); //открываю файл для ЗАПИСИ
    record<<Array.size()<<std::endl; //сначала записываю количество данных в первую строку

    for (auto & i : Array)
    {

        record << i.name<<" "<< i.address_class.country<<" "<<i.address_class.city<<" "
               <<i.address_class.building_number<<" "<<i.date_class.year<<" "
               <<i.date_class.month<<" "<<i.date_class.day<<" "<<i.type_of_supplier<<" "
               <<i.saldo<<std::endl;

    } //ну вот, записали

    record.close(); //закрываю файл окончательно, типа знаю хороший тон АХАХА

}

std::ifstream read; //поток для чтения из файла
void Supplier::readDataFromDisk()
{
    if (std::filesystem::is_empty("file.txt")){std::cout<<"Ранее добавленных объектов не найдено"<<std::endl;}
    else
    {
        read.open("file.txt"); //открываю файл для ЧТЕНИЯ
        int current_count;

        read>>current_count; //сначала записываю количество данных из первой строки в память
        Supplier::count=current_count;
        std::cout<<"Считано объектов: "<<Supplier::count <<std::endl;

        for (int i = 0; i<Supplier::count; i++)
        {
            std::string Name, Address_country, Address_city, Address_building, Date_month;
            int saldo, Date_day, Date_year, type;

            read >> Name >> Address_country >> Address_city >>Address_building >> Date_year>>Date_month>>Date_day>>type>>saldo;
/////////~for Supplier~/////////

            this->name=Name; //вот так надо
            this->saldo=saldo;
            int current_type = type;
            this->type_of_supplier = (current_type == 1 ? Supplier::RAW_MATERIAL_SUPPLIER : Supplier::EQUIPMENT_SUPPLIER);

/////////~for Address~/////////
            this->address_class.country = Address_country;
            this->address_class.city = Address_city;
            this->address_class.building_number=Address_building;

/////////~for Date~/////////

            this->date_class.day = Date_day;
            this->date_class.month = Date_month;
            this->date_class.year = Date_year;

            Array.push_back(*this);

        }
    }
    read.close(); //ну чтоб красиво да

    for (auto & i : Array)
    {
        if ((i.address_class.show_full_address()).length()>Supplier::the_longest_Address){Supplier::the_longest_Address = (i.address_class.show_full_address()).length();}
        if ((i.name).length()>Supplier::the_longest_Name){Supplier::the_longest_Name = (i.name).length();}

    }

}

void Supplier::deleteElement(int choice)
{
    auto it1 = Array.begin();
    advance (it1,choice-1);
    Array.erase (it1);

}

int Supplier::Special_check2() {
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Удалить позицию №  ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a>Array.size()+1)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}


