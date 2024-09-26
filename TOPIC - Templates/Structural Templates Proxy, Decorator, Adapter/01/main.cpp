#include <string>
#include <iostream>
#include <algorithm>
class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
    virtual ~Text() = default;
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(std::unique_ptr<Text> text) : text_(std::move(text)) {}
    std::unique_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph: public DecoratedText{
public:
    explicit Paragraph(std::unique_ptr<Text> text) : DecoratedText(std::move(text)){}
    void render(const std::string& data) const{
    std::cout << "<p>";
    text_->render(data);
    std::cout << "</p>";

    }
};
class Reversed: public DecoratedText{
public:
    explicit Reversed(std::unique_ptr<Text> text) : DecoratedText(std::move(text)){}
    void render(const std::string& data) const{
    std::string reversed_data = data;
    std::reverse(reversed_data.begin(), reversed_data.end());
    text_->render(reversed_data);
    }
};
class Link: public DecoratedText{
public:
    explicit Link(std::unique_ptr<Text> text) : DecoratedText(std::move(text)){}
    void render(const std::string& link, const std::string& data) const{
    std::cout << "<a href=";
    text_->render(link);
    std::cout << ">";
    text_->render(data);
    std::cout << "</a>";
    }


};

int main() {
    auto text_block = std::make_unique<ItalicText>(std::make_unique<BoldText>(std::make_unique<Text>()));
    auto new_paragraph = std::make_unique<Paragraph>(std::make_unique<Text>());
    auto reversed = std::make_unique<Reversed>(std::make_unique<Text>());
    auto link = std::make_unique<Link>(std::make_unique<Text>());

    text_block->render("Hello world");
    std::cout << "\n";
    new_paragraph->render("Hello world");
    std::cout << "\n";
    reversed->render("Hello world");
    std::cout << "\n";
    link->render("netology.ru", "Hello world");
    std::cout << "\n";

}
