#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Order {
    private:
        string name;
        int menuItem;
        Location location;
    public:
        // constructor
        Order(const string& name, int menuItem, const Location& location);

        // getter
        Location getLocation() const;

        // print
        void print();
};

#endif