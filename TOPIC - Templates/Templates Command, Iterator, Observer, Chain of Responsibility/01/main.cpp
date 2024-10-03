#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintMessage  : public LogCommand{
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};


class MessageInFile : public LogCommand{
private:
    std::string filePath;
public:
    explicit MessageInFile(const std::string& path) : filePath(path) {}

    void print(const std::string& message) override {
        std::ofstream outFile(filePath, std::ios_base::app);
        if (outFile.is_open()) {
            outFile << message << std::endl;
        } else {
            std::cerr << "Failed to open file: " << filePath << std::endl;
        }
    }
};


int main()
{
    PrintMessage consoleLogger;
    MessageInFile fileLogger("log.txt");

    consoleLogger.print("Message");
    fileLogger.print("Message for file");

    return 0;
}
