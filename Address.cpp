#include "Address.h"
#include <iostream>

std::string Address::show_full_address() const {
    std::string full_address = "Country: "+ country +"; "+"City: "+city+"; "+"Building: "+building_number;
    return full_address;
}

Address &Address::operator=(const Address &equal) {
    if (this == &equal)
        return *this;
    country=equal.country;
    city=equal.city;
    building_number=equal.building_number;

    return *this;

}

Address::Address()
{
    country = "country";
    city = "city";
    building_number = "1";
}




