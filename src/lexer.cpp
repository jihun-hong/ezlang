#include "lexer.h"


#define RET_SUCCESS 0       // Success for lexer
#define RET_ERR_ARG 1     // Error in argument
#define RET_ERR_LEX 2     // Error in lexer


void Lexer::tokenize_line(const std::string& cur_line,
                          const std::string& src_file_name, int cur_lineno) {
    std::string cur_token = "";
    char cur_char;

    const std::set<char> lexer_special_chars = { '"', '\'', '.', ':', 
                                                 '{', '}', ',' };
    std::vector<std::string> tokens;
    
    for (int i = 0; i < cur_line.size(); i++) {
        char ch = cur_line[i];
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (cur_token.size() > 0) tokens.push_back(cur_token);
            cur_token = "";
        } else if (lexer_special_chars.count(ch) > 0) {
            if (cur_token.size() > 0) tokens.push_back(cur_token);
            std::string ch_str(1, ch);
            tokens.push_back(ch_str);
            cur_token = "";
        } else {
            cur_token += ch;
        }
    }

    if (cur_token.size() > 0) tokens.push_back(cur_token);

    for (std::string& tok : tokens) {
        Token* tk = new Token(tok, src_file_name, cur_lineno);
        std::cout << *tk << std::endl;
    }
}


int Lexer::tokenize(std::string src_file_name) {
    std::fstream src_file_stream;
    src_file_stream.open(src_file_name, std::ios::in);

    if (!src_file_stream.is_open()) return RET_ERR_LEX;

    std::string cur_line;
    int cur_lineno = 1;

    while(getline(src_file_stream, cur_line)) {
        tokenize_line(cur_line, src_file_name, cur_lineno);
        cur_lineno++;
    }
    return RET_SUCCESS;
}


/* Print the correct usage of lexer program to std::cerr. */
static void print_usage(std::string prog_name)
{
    std::cerr << "Usage: " << prog_name << " FILE" << std::endl;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return RET_ERR_ARG;
    }

    Lexer* lexer = new Lexer();
    for (int i = 1; i < argc; ++i) {
        std::string src_file_name = argv[i];
        int status = lexer->tokenize(src_file_name);
        if (status != RET_SUCCESS) return status;
    }
    return RET_SUCCESS;
}