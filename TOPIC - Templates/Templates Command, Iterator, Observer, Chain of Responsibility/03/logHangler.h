#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>


enum class Type {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
public:
    LogMessage(Type type, const std::string& message) : _type(type), _message(message) {}

    Type type() const {
        return _type;
    }

    const std::string& message() const {
        return _message;
    }

private:
    Type _type;
    std::string _message;
};


class LogHandler {
protected:
    std::shared_ptr<LogHandler> nextHandler;

public:
    virtual ~LogHandler() = default;

    void setNextHandler(const std::shared_ptr<LogHandler>& handler) {
        nextHandler = handler;
    }

    virtual void handle(const LogMessage& logMessage) {
        if (nextHandler) {
            nextHandler->handle(logMessage);
        } else {
            throw std::runtime_error("Unprocessed message: " + logMessage.message());
        }
    }
};

class FatalErrorHandler : public LogHandler {
public:
    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Type::FatalError) {
            throw std::runtime_error("Fatal Error: " + logMessage.message());
        } else {
            LogHandler::handle(logMessage);
        }
    }
};

class ErrorHandler : public LogHandler {
private:
    std::string filePath;

public:
    explicit ErrorHandler(const std::string& path) : filePath(path) {}

    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Type::Error) {
            std::ofstream outFile(filePath, std::ios_base::app);
            if (outFile.is_open()) {
                outFile << "Error: " << logMessage.message() << std::endl;
            } else {
                std::cerr << "Cannot open file: " << filePath << std::endl;
            }
        } else {
            LogHandler::handle(logMessage);
        }
    }
};

class WarningHandler : public LogHandler {
public:
    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Type::Warning) {
            std::cout << "Warning: " << logMessage.message() << std::endl;
        } else {
            LogHandler::handle(logMessage);
        }
    }
};

class UnknownMessageHandler : public LogHandler {
public:
    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Type::Unknown) {
            throw std::runtime_error("Unknown message: " + logMessage.message());
        } else {
            LogHandler::handle(logMessage);
        }
    }
};
