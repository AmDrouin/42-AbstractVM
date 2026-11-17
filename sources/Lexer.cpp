#include "Lexer.hpp"

Lexer::Lexer() : _src(""), _pos(0), _line(1), _tokens() {}

Lexer::Lexer(const std::string &text){
    this->_src = text;
    this->_pos = 0;
    this->_line = 1; 
}

Lexer::Lexer(const Lexer &og): _src(og._src), _pos(og._pos), _line(og._line), _tokens(og._tokens) {}

Lexer::~Lexer() {}

Lexer &Lexer::operator = (const Lexer &rhs) {
    if(this != &rhs){
        _src = rhs._src;
        _pos = rhs._pos;
        _line = rhs._line; 
        _tokens = rhs._tokens;
    }
    return *this;
}

void Lexer::tokenize(){}


const std::vector<Token> &Lexer::getTokens() const{return _tokens;}

void Lexer::readWord(){}
void Lexer::readNumber(){}
void Lexer::skipComment(){}
