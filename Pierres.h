#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include <vector>
#include "defs.h"
#include "Franchise.h"
#include "Driver.h"

using namespace std;

class Pierres {
    private:
        vector<Driver*> drivers;
        vector<Franchise*> franchises;
    public:
        Pierres();
        ~Pierres();
        void addDriver(const string& name, Location location);
        void addFranchise(const string& name, Location Location);
        Franchise* getFranchise(const string& id) const;
        Driver* getDriver(const string& id) const;
        void takeOrder(const string& customerName, int menuItem, Location location);
        void driverPickup(const string& franshideId, int numOrders);
        void driverDeliver(const string&  driverId, int numOrders);

        // print
        void printFranchises() const;
        void printDrivers() const;
};

#endif