#include "Lexical_analysis/source/MiniJavaScanner.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
int main() {
    /*ofstream out("out");
    ifstream in("in");
    MiniJavaScanner lexer(in);
    lexer.tokenize();
    return 0;*/

    MiniJavaScanner lexer;

    void* result;
    yy::parser parser(lexer);

    try {
        if (parser.parse()) {
            return 1;
        }
        assert(result != nullptr);
        //result->Print(std::cout);
    } catch (std::exception &e) {
        std::cerr << "\x1B[31m" << e.what() << "\x1B[0m" << std::endl;
    }
    return 1;
}
/*
#include <iostream>

#include "olc_lexer.h"
#include "tokentree.h"

int main() {
    OlcLex::OlcLexer lexer;

    TreeNodePtr result;
    yy::parser parser(lexer, result);

    try {
        if( parser.parse() ) {
            return 1;
        }
        assert(result != nullptr);
        result->Print(std::cout);
    } catch (std::exception& e) {
        std::cerr << "\x1B[31m" << e.what() << "\x1B[0m" << std::endl;
    }
    return 0;
}*/