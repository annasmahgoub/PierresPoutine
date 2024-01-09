#include "Entity.h"

void Entity::setLocation(int x, int y) {
    location.setLocation(x, y);
}

Entity::Entity(char c, int i, const string &name, Location location) 
    : id(c + to_string(i)), name(name), location(location) {
}

Order *Entity::getNextOrder() {
    return orders.popFirst();
}

Order *Entity::peekNextOrder() const {
    return orders.peekFirst();
}

Location Entity::getLocation() const{
    return location;
}

void Entity::addOrder(Order *order) {
    orders.addLast(order);
}

void Entity::print() const {
    cout<<"ID: "<<id<<" | Name: "<<name<<" | Location: ";
    location.print();
    cout<<" | Number of Orders: "<<orders.size()<<endl;
}

bool Entity::equals(const string& id) const {
    if (this->id == id) {return true;}
    return false;
}

int Entity::getNumOrders() const {
    return orders.size();
}