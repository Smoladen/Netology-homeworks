#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>


enum class MessageType {
    Warning,
    Error,
    FatalError,
    Unknown
};


class LogMessage {
public:
    LogMessage(MessageType type, const std::string& message)
        : _type(type), _message(message) {}

    MessageType type() const {
        return _type;
    }

    const std::string& message() const {
        return _message;
    }

private:
    MessageType _type;
    std::string _message;
};


class LogHandler {
private:
    std::shared_ptr<LogHandler> nextHandler;

public:
    virtual ~LogHandler() = default;

    void setNextHandler(const std::shared_ptr<LogHandler>& handler) {
        nextHandler = handler;
    }

    void receiveMessage(const LogMessage& msg) {
        if (canHandle() == msg.type()) {
            handleMessage(msg);
        } else if (nextHandler) {
            nextHandler->receiveMessage(msg);
        } else {
            throw std::runtime_error("Error: no handler for this message was found!");
        }
    }

protected:
    virtual void handleMessage(const LogMessage& msg) = 0;

    virtual MessageType canHandle() const = 0;
};


class FatalErrorHandler : public LogHandler {
protected:
    void handleMessage(const LogMessage& msg) override {
        throw std::runtime_error("Fatal Error: " + msg.message());
    }

    MessageType canHandle() const override {
        return MessageType::FatalError;
    }
};

class ErrorHandler : public LogHandler {
private:
    std::string filePath;

public:
    explicit ErrorHandler(const std::string& path) : filePath(path) {}

protected:
    void handleMessage(const LogMessage& msg) override {
        std::ofstream outFile(filePath, std::ios_base::app);
        if (outFile.is_open()) {
            outFile << "Error: " << msg.message() << std::endl;
        } else {
            std::cerr << "Cannot open file: " << filePath << std::endl;
        }
    }

    MessageType canHandle() const override {
        return MessageType::Error;
    }
};

class WarningHandler : public LogHandler {
protected:
    void handleMessage(const LogMessage& msg) override {
        std::cout << "Warning: " << msg.message() << std::endl;
    }

    MessageType canHandle() const override {
        return MessageType::Warning;
    }
};

class UnknownMessageHandler : public LogHandler {
protected:
    void handleMessage(const LogMessage& msg) override {
        throw std::runtime_error("Unknown message: " + msg.message());
    }

    MessageType canHandle() const override {
        return MessageType::Unknown;
    }
};
