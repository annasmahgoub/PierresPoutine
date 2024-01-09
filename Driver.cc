#include "Driver.h"

const char Driver::code = 'D';
int Driver::nextId = 0;

Driver::Driver(const string& name) 
    : Entity(code, nextId++, name, Location(1, 1)){
}

Driver::Driver(const string &name, const Location& location)
    : Entity(code, nextId++, name, location){
}

bool Driver::isFree() const {
    if (orders.empty()) {return true;}
    return false;
}

void Driver::print() const {
    cout<<"Driver's:"<<endl;
    Entity::print();
}
