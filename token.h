#include <iostream>
#include <string>


class Token {
private:
    std::string token;
    std::string src_file;
    int line_no;

public:
    Token(std::string token, std::string src_file, int line_no) {
        this->token = token;
        this->src_file = src_file;
        this->line_no = line_no;
    };

    ~Token();

    friend std::ostream& operator<<(std::ostream& os, const Token& tk);
    friend std::istream& operator>>(std::istream& is, Token& tk);
};