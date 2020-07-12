#include "token.h"


std::ostream& operator<<(std::ostream& os, const Token& tk) {
    os << tk.src_file << " " << tk.line_no << " " << tk.token;
    return os;
}


std::istream& operator>>(std::istream& is, Token& tk) {
    is >> tk.src_file >> tk.line_no >> tk.token;
    return is;
}