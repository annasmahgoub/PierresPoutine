#include "Pierres.h"

Pierres::Pierres() {
}

Pierres::~Pierres() {
    for (int i = 0; i < franchises.size(); i++) {
        int size = franchises[i]->getNumOrders();
        for (int j = 0; j < size; j++) {
            franchises[i]->getNextOrder();
        }
        delete franchises[i];
    }

    for (int i = 0; i < drivers.size(); i++) {
        int size = drivers[i]->getNumOrders();
        for (int j = 0; j < size; j++) {
            drivers[i]->getNextOrder();
        }
        delete drivers[i];
    }
}

void Pierres::addDriver(const string &name, Location location) {
    Driver* driver = new Driver(name, location);
    drivers.push_back(driver); // add driver to the back
}

void Pierres::addFranchise(const string &name, Location location) {
    Franchise* franch = new Franchise(name, location);
    franchises.push_back(franch); // add franchise to the back
}

void Pierres::takeOrder(const string &customerName, int menuItem, Location location) {
    Order* order = new Order(customerName, menuItem, location);// make new order

    int distance = 0; // distance of the closest franchise
    int index = 0;
    for (int i = 0; i < franchises.size(); i++) {
        if (distance == 0 || distance > franchises[i]->getLocation().getDistance(location)) {
            distance = franchises[i]->getLocation().getDistance(location);
            index = i;
        }
    }

    franchises[index]->addOrder(order); // add order to closest franchise
}

Franchise* Pierres::getFranchise(const string &id) const {
    for (int i = 0; i < franchises.size(); i++) {
        if (franchises[i]->equals(id)) {return franchises[i];}
    }
    return nullptr;
}

Driver *Pierres::getDriver(const string &id) const {
    for (int i = 0; i < drivers.size(); i++) {
        if (drivers[i]->equals(id)) {return drivers[i];}
    }
    return nullptr;
}

void Pierres::driverPickup(const string &franshideId, int numOrders) {
    if (getFranchise(franshideId) != nullptr) {
        Franchise* franch = getFranchise(franshideId);

        int distance = 0; // distance of the closest franchise
        int index = 0;
        for (int i = 0; i < drivers.size(); i++) {
            if (drivers[i]->isFree()) { // Driver with id available for pickup
                if (distance == 0 || distance > drivers[i]->getLocation().getDistance(franch->getLocation())) { // Closest available driver
                    distance = drivers[i]->getLocation().getDistance(franch->getLocation());
                    index = i;
                }
            }
        }

        drivers[index]->setLocation(franch->getLocation().getX(), franch->getLocation().getY()); // change driver's location to match the franchise

        if (numOrders > franch->getNumOrders()) { // transfer all orders if numOrders is larger than the number of Orders at the franchise
            numOrders = franch->getNumOrders();
        }

        for (int i = 0; i < numOrders; i++) {
            drivers[index]->addOrder(franch->getNextOrder()); // transfer numOrders Orders from the Franchise to the Driver
        }
    }else {
        cout<<"Error: No Franchise found with given id "<<franshideId<<endl; // error message for no franchise with given id
    }
}

void Pierres::driverDeliver(const string &driverId, int numOrders) {
    Driver* driver = getDriver(driverId);
    if (driver != nullptr) {
        if (driver->getNumOrders() < numOrders) {
            numOrders = driver->getNumOrders(); // if the driver has less orders than numOrders
        }
        for (int i = 0; i < numOrders; i++) {
            Order* order = driver->peekNextOrder(); // get first order that needs to be delivered
            Location orderLocation = order->getLocation(); 
            driver->setLocation(orderLocation.getX(), orderLocation.getY()); // Driver change their Location to the Location of that Order
            cout<<"Delivering: "<<endl;
            order->print(); // print out the order being delivered
            delete driver->getNextOrder(); // delete order
        }
    } else {
        cout<<"Error: No Driver found with given id "<<driverId<<endl; // error message for no Driver with given id
    }
}

void Pierres::printFranchises() const {
    for (int i = 0; i < franchises.size(); i++) {
        franchises[i]->print();
    }
}

void Pierres::printDrivers() const {
    for (int i = 0; i < drivers.size(); i++) {
        drivers[i]->print();
    }
}
