#include "RideManager.h"
#include <thread>
#include <chrono>
#include <vector>

void simulateRide(int passengerId, const std::string& name, const std::string& vehicleType) {
    Passenger p(passengerId, name);
    RideManager::getInstance()->requestRide(p, vehicleType);
}

int main() {
    RideManager* manager = RideManager::getInstance();

    manager->addDriver(new Driver(101, "Alice"));
    manager->addDriver(new Driver(102, "Bob"));
    manager->addDriver(new Driver(103, "Charlie"));

    std::vector<std::thread> threads;

    threads.emplace_back(simulateRide, 1, "Aarav", "Car");
    threads.emplace_back(simulateRide, 2, "Sanya", "Bike");
    threads.emplace_back(simulateRide, 3, "Ravi", "Car");
    threads.emplace_back(simulateRide, 4, "Neha", "Bike");

    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    Logger::getInstance()->log("All rides simulated successfully.");
    return 0;
}