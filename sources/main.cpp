#include "Token.hpp"
#include "Lexer.hpp"
#include <iostream>
#include "Exception.hpp"

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

        const std::vector<Token> &tokens = lexer.getTokens();
        for (std::size_t i = 0; i < tokens.size(); ++i)
            std::cout << tokens[i].getType() << " [" << tokens[i].getText() << "] line " << tokens[i].getLine() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
