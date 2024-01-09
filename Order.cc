#include "Order.h"

Order::Order(const string &name, int menuItem, const Location &location) 
    : name(name), menuItem(menuItem), location(location) {
}

Location Order::getLocation() const {
    return location;
}

void Order::print() {
    cout<<"Name: "<<name<<" | Menu Item: ";

    switch (menuItem) {
    case 1:
        cout<<"Large Poutine"<<endl;
        break;
    case 2:
        cout<<"Medium Poutine"<<endl;
        break;
    case 3:
        cout<<"Small Poutine"<<endl;
        break;
    default:
        break;
    }
}