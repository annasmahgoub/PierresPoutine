#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "defs.h"

using namespace std;

class Franchise: public Entity {
    private:
        static const char code;
        static int nextId;
        static const string menu[MENU_ITEMS];
    public:
        // Member Functions
        Franchise(const string& name); // default constructor
        Franchise(const string& name, const Location& location);
        void print() const;

        // Class Functions
        static void printMenu();
        static string getMenu(int index);
};

#endif