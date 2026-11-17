#include "Token.hpp"

//default constructor
Token::Token() : _type(END), _text(""), _line(0) {}

Token::Token(eTokenType type, const std::string &text, int line){
    _type = type;
    _text = text;
    _line = line;
}

Token::Token(const Token &og): _type(og._type), _text(og._text), _line(og._line) {}


Token & Token::operator=(const Token &rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        _text = rhs._text;
        _line = rhs._line;
    }
    return *this;
}

Token::~Token() {}

// Getters
eTokenType  Token::getType() const {return _type;}
std::string Token::getText() const {return _text;}
int         Token::getLine() const {return _line;}