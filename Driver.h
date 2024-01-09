#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class Driver: public Entity {
    private:
        static const char code;
        static int nextId;
    public:
        Driver(const string& name); // default constructor
        Driver(const string& name, const Location& location);

        bool isFree() const;
        void print() const;
};

#endif