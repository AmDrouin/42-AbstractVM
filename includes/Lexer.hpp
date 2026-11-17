#pragma once

#include "Token.hpp"
#include <vector>
#include <string>

class Lexer {
    public:
        Lexer();
        Lexer(const std::string &text);
        Lexer(const Lexer &og);
        ~Lexer();
        Lexer &operator = (const Lexer &rhs);

        void tokenize();
        const std::vector<Token>& getTokens() const;

    private:
        std::string         _src;
        std::size_t              _pos;
        int                 _line;
        std::vector<Token>  _tokens;

        void    readWord();
        void    readNumber();
        void    skipComment();
};