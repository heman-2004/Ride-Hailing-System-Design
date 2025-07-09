#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <atomic>

class Driver {
    int id;
    std::string name;
    std::atomic<bool> available;

public:
    Driver(int id, const std::string& name)
        : id(id), name(name), available(true) {}

    int getId() const { return id; }
    std::string getName() const { return name; }

    bool isAvailable() const { return available; }

    void assignRide() { available = false; }
    void completeRide() { available = true; }
};

#endif