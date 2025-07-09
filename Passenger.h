#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
    int id;
    std::string name;

public:
    Passenger(int id, const std::string& name) : id(id), name(name) {}
    int getId() const { return id; }
    std::string getName() const { return name; }
};

#endif