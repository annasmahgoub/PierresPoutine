#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Location.h"
#include "Order.h"
#include "Queue.h"

using namespace std;

class Entity {
    protected:
        string id;
        string name;
        Location location;
        Queue orders;
    public:
        void setLocation(int x, int y);

        // constructor
        Entity(char c, int i, const string& name, Location location);

        Order* getNextOrder();
        Order* peekNextOrder() const;
        Location getLocation() const;
        void addOrder(Order* order);
        void print() const;
        bool equals(const string& id) const;
        int getNumOrders() const;
};

#endif