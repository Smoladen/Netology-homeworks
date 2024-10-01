#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "observer.h"

class Observable {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void warning(const std::string& message) const {
        for (auto observer : observers) {
            observer->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        for (auto observer : observers) {
            observer->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        for (auto observer : observers) {
            observer->onFatalError(message);
        }
    }
};



int main() {
    Observable logger;

    WarningObserver warningObserver;
    ErrorObserver errorObserver("error_log.txt");
    FatalErrorObserver fatalErrorObserver("fatal_log.txt");

    logger.addObserver(&warningObserver);
    logger.addObserver(&errorObserver);
    logger.addObserver(&fatalErrorObserver);

    logger.warning("This is a warning");
    logger.error("This is an error");
    logger.fatalError("This is a fatal error");

    return 0;
}
