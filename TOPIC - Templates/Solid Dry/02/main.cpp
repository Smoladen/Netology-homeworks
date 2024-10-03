#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>


class TextPrintable {
public:
    virtual ~TextPrintable() = default;
    virtual std::string printAsText() const = 0;
};

class HTMLPrintable {
public:
    virtual ~HTMLPrintable() = default;
    virtual std::string printAsHTML() const = 0;
};

class JSONPrintable {
public:
    virtual ~JSONPrintable() = default;
    virtual std::string printAsJSON() const = 0;
};

class TextData : public TextPrintable {
private:
    std::string data_;
public:
    explicit TextData(std::string data) : data_(std::move(data)) {}

    std::string printAsText() const override {
        return data_;
    }
};

class HTMLData : public HTMLPrintable {
private:
    std::string data_;
public:
    explicit HTMLData(std::string data) : data_(std::move(data)) {}

    std::string printAsHTML() const override {
        return "<html>" + data_ + "</html>";
    }
};

class JSONData : public JSONPrintable {
private:
    std::string data_;
public:
    explicit JSONData(std::string data) : data_(std::move(data)) {}

    std::string printAsJSON() const override {
        return "{ \"data\": \"" + data_ + "\" }";
    }
};


void saveTo(std::ofstream& file, const TextPrintable& printable) {
    file << printable.printAsText();
}

void saveTo(std::ofstream& file, const HTMLPrintable& printable) {
    file << printable.printAsHTML();
}

void saveTo(std::ofstream& file, const JSONPrintable& printable) {
    file << printable.printAsJSON();
}


int main() {
    std::ofstream fileText("text_output.txt");
    std::ofstream fileHTML("html_output.html");
    std::ofstream fileJSON("json_output.json");

    TextData textData("This is plain text");
    HTMLData htmlData("This is HTML data");
    JSONData jsonData("This is JSON data");

    saveTo(fileText, textData);
    saveTo(fileHTML, htmlData);
    saveTo(fileJSON, jsonData);

    return 0;
}


