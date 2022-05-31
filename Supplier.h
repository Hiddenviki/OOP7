#pragma once
#include <string>
#include <list>

#include "Address.h"
#include "Date.h"

class Supplier{
friend class Compare_down;
private:
    std::string name; //ЭТО НАЗВАНИЕ ФИРМЫ
    enum Type{ RAW_MATERIAL_SUPPLIER = 1 , EQUIPMENT_SUPPLIER = 2 };
    double saldo;
    Type type_of_supplier;

public:
    Address address_class;
    Date date_class;

    static int the_longest_Address; //для таблицы
    static int the_longest_Name; //для таблицы
    static int count;

    Supplier();

    Supplier& operator = (const Supplier &equal);
    friend std::istream& operator>> (std::istream &in, Supplier* Obj);

    std::list<Supplier> Array;


    int Special_check() const;
    int Special_check2();

    void setData(int some_case);
    void showData() const;
    void deleteElement(int choice);
    void sort() const;
    void searchByName() const;
    void saveDataOnDisk() const;
    void readDataFromDisk();


};


