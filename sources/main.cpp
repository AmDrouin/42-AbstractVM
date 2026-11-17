#include "Token.hpp"
#include "Lexer.hpp"
#include <iostream>

int main() {

    Token a(WORD, "push", 1);
    Token b(a);
    Token c;
    c = a;

    std::cout << b.getType() << " " << b.getText() << b.getLine() << std::endl;
    std::cout << c.getType() << " " << c.getText() << c.getLine() << std::endl;

    try {
        Lexer lexer("test");
        lexer.tokenize();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
