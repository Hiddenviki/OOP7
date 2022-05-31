//
// Created by Виктория Веселкова on 01.06.2022.
//

#pragma once
#include "Supplier.h" //?

class Compare_down: public Supplier {
friend class Supplier;
public:
    bool operator()(Supplier &p1, Supplier &p2)
    {
        if (p1.saldo > p2.saldo) return 1;
        else return 0;
    }
};