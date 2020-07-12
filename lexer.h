#include <fstream>
#include <set>
#include <vector>

#include "token.h"


class Lexer {
private:
    void tokenize_line(const std::string&, const std::string&, int);

public:
    Lexer() {};
    ~Lexer() {};

    int tokenize(std::string);
};