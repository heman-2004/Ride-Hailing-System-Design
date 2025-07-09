#ifndef RIDE_MANAGER_H
#define RIDE_MANAGER_H

#include "Passenger.h"
#include "Driver.h"
#include "Ride.h"
#include "VehicleFactory.h"
#include "Strategy.h"
#include "Logger.h"

#include <vector>
#include <mutex>

class RideManager {
    static RideManager* instance;
    std::vector<Driver*> drivers;
    SelectionStrategy* strategy;
    std::mutex mtx;

    RideManager() {
        strategy = new NearestDriverStrategy();
    }

public:
    static RideManager* getInstance() {
        static RideManager instance;
        return &instance;
    }

    void addDriver(Driver* driver) {
        std::lock_guard<std::mutex> lock(mtx);
        drivers.push_back(driver);
    }

    void requestRide(Passenger passenger, const std::string& vehicleType) {
        std::lock_guard<std::mutex> lock(mtx);
        Logger::getInstance()->log(passenger.getName() + " requested a ride.");

        Driver* driver = strategy->selectDriver(drivers);
        if (!driver) {
            Logger::getInstance()->log("No drivers available for " + passenger.getName());
            return;
        }

        Vehicle* vehicle = VehicleFactory::createVehicle(vehicleType);
        if (!vehicle) {
            Logger::getInstance()->log("Invalid vehicle type.");
            return;
        }

        Ride ride(passenger, driver, vehicle->getType());
        ride.startRide();
        Logger::getInstance()->log(ride.getInfo());

        ride.completeRide();
        Logger::getInstance()->log("Ride completed for " + passenger.getName());

        delete vehicle;
    }

    ~RideManager() {
        delete strategy;
        for (auto d : drivers) delete d;
    }
};

RideManager* RideManager::instance = nullptr;

#endif