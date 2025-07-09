#ifndef LOGGER_H
#define LOGGER_H

#include <mutex>
#include <iostream>

class Logger {
    static Logger* instance;
    static std::mutex mtx;

    Logger() {}

public:
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance)
            instance = new Logger();
        return instance;
    }

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "[LOG] " << msg << std::endl;
    }
};

Logger* Logger::instance = nullptr;
std::mutex Logger::mtx;

#endif