#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include <string>

class Vehicle {
public:
    virtual std::string getType() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    std::string getType() const override { return "Car"; }
};

class Bike : public Vehicle {
public:
    std::string getType() const override { return "Bike"; }
};

class VehicleFactory {
public:
    static Vehicle* createVehicle(const std::string& type) {
        if (type == "Car") return new Car();
        else if (type == "Bike") return new Bike();
        else return nullptr;
    }
};

#endif