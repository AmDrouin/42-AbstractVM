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
        int                 _pos;
        int                 _line;
        std::vector<Token>  _tokens;

        void    readWord();
        void    readNumber();
        void    skipComment();
};

class LexicalError : public std::exception {
    public :
        LexicalError();
        LexicalError(const std::string &text);
        LexicalError(const LexicalError &og);
        ~LexicalError() override;
        LexicalError &operator = (const LexicalError &rhs);
        const char * what() const noexcept override;
    private:
        std::string _msg;
};