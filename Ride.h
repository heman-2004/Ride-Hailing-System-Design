#ifndef RIDE_H
#define RIDE_H

#include "Passenger.h"
#include "Driver.h"
#include <string>

class Ride {
    Passenger passenger;
    Driver* driver;
    std::string vehicleType;

public:
    Ride(Passenger passenger, Driver* driver, const std::string& vehicleType)
        : passenger(passenger), driver(driver), vehicleType(vehicleType) {}

    void startRide() {
        if (driver)
            driver->assignRide();
    }

    void completeRide() {
        if (driver)
            driver->completeRide();
    }

    std::string getInfo() const {
        return "Ride for " + passenger.getName() + " with Driver " + driver->getName() + " in " + vehicleType;
    }
};

#endif