#ifndef STRATEGY_H
#define STRATEGY_H

#include "Driver.h"
#include <vector>

class SelectionStrategy {
public:
    virtual Driver* selectDriver(std::vector<Driver*>& drivers) = 0;
    virtual ~SelectionStrategy() {}
};

class NearestDriverStrategy : public SelectionStrategy {
public:
    Driver* selectDriver(std::vector<Driver*>& drivers) override {
        for (Driver* driver : drivers) {
            if (driver->isAvailable()) {
                return driver;
            }
        }
        return nullptr;
    }
};

#endif