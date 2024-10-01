#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class print_message : public LogCommand{
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};


class message_in_file : public LogCommand{
private:
    std::string filePath;
public:
    explicit message_in_file(const std::string& path) : filePath(path) {}

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
    print_message consoleLogger;
    message_in_file fileLogger("log.txt");

    consoleLogger.print("Message");
    fileLogger.print("Message for file");

    return 0;
}
