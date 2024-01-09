#include "Franchise.h"

const char Franchise::code = 'F';
int Franchise::nextId = 0;
const string Franchise::menu[MENU_ITEMS] = {
    "1. Large Poutine", 
    "2. Medium Poutine", 
    "3. Small Poutine"
};

// Member Functions
Franchise::Franchise(const string& name) 
    : Entity(code, nextId++, name, Location(1,2)) {
}

Franchise::Franchise(const string &name, const Location& location) 
    : Entity(code, nextId++, name, location){
}

void Franchise::print() const {
    cout<<"Franchise's:"<<endl;
    Entity::print();
}

// Class Functions
void Franchise::printMenu() {
    int i = 0;
    while(i < MENU_ITEMS) {
        cout<<menu[i++]<<endl;
    }
}

string Franchise::getMenu(int index) {
    if (index >= MENU_ITEMS || index < 0) {return "unknown menu item";} // if index is invalid
    return menu[index];
}