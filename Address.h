#pragma once
#include <iostream>


class Address {
    friend class Supplier;
private:
    std::string country;
    std::string city;
    std::string building_number;

public:

    Address();
    std::string show_full_address() const;
    Address& operator = (const Address &equal);

};


