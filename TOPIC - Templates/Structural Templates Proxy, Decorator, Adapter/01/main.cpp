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
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph: public DecoratedText{
public:
    explicit Paragraph(Text* text) : DecoratedText(text){}
    void render(const std::string& data) const{
    std::cout << "<p>";
    text_->render(data);
    std::cout << "</p>";

    }
};
class Reversed: public DecoratedText{
public:
    explicit Reversed(Text* text) : DecoratedText(text){}
    void render(const std::string& data) const{
    std::string reversed_data = data;
    std::reverse(reversed_data.begin(), reversed_data.end());
    text_->render(reversed_data);
    }
};
class Link: public DecoratedText{
public:
    explicit Link(Text* text) : DecoratedText(text){}
    void render(const std::string& link, const std::string& data) const{
    std::cout << "<a href=";
    text_->render(link);
    std::cout << ">";
    text_->render(data);
    std::cout << "</a>";
    }


};

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    auto new_paragraph = new Paragraph(new Text());
    auto reversed = new Reversed(new Text());
    auto link = new Link(new Text());

    text_block->render("Hello world");
    std::cout << "\n";
    new_paragraph->render("Hello world");
    std::cout << "\n";
    reversed->render("Hello world");
    std::cout << "\n";
    link->render("netology.ru", "Hello world");
    std::cout << "\n";

}
