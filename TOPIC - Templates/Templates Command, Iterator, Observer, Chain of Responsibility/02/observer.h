#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


class Observer {
public:
    virtual ~Observer() = default;

    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};
class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }
};


class ErrorObserver : public Observer {
private:
    std::string filePath;

public:
    explicit ErrorObserver(const std::string& path) : filePath(path) {}

    void onError(const std::string& message) override {
        std::ofstream outFile(filePath, std::ios_base::app);
        if (outFile.is_open()) {
            outFile << "Error: " << message << std::endl;
        } else {
            std::cerr << "Cannot open file: " << filePath << std::endl;
        }
    }
};


class FatalErrorObserver : public Observer {
private:
    std::string filePath;

public:
    explicit FatalErrorObserver(const std::string& path) : filePath(path) {}

    void onFatalError(const std::string& message) override {

        std::cout << "Fatal Error: " << message << std::endl;

        std::ofstream outFile(filePath, std::ios_base::app);
        if (outFile.is_open()) {
            outFile << "Fatal Error: " << message << std::endl;
        } else {
            std::cerr << "Cannot open file: " << filePath << std::endl;
        }
    }
};
