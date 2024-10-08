#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>
#include "logHangler.h"



int main() {
    auto fatalHandler = std::make_shared<FatalErrorHandler>();
    auto errorHandler = std::make_shared<ErrorHandler>("error_log.txt");
    auto warningHandler = std::make_shared<WarningHandler>();
    auto unknownHandler = std::make_shared<UnknownMessageHandler>();

    unknownHandler->setNextHandler(warningHandler);
    warningHandler->setNextHandler(errorHandler);
    errorHandler->setNextHandler(fatalHandler);

    LogMessage warningMessage(MessageType::Warning, "This is a warning");
    LogMessage errorMessage(MessageType::Error, "This is an error");
    LogMessage fatalMessage(MessageType::FatalError, "This is a fatal error");
    LogMessage unknownMessage(MessageType::Unknown, "This is an unknown message");

    try {
        unknownHandler->receiveMessage(warningMessage);
        unknownHandler->receiveMessage(errorMessage);
        unknownHandler->receiveMessage(fatalMessage);
        unknownHandler->receiveMessage(unknownMessage);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
