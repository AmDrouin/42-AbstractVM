#include "Lexer.hpp"
#include "Exception.hpp"
#include <cctype>

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

void Lexer::tokenize(){
    while (_pos < _src.size()) {
        char c = _src[_pos];

        if (c == ' ' || c == '\t' || c == '\r')
            _pos++;
        else if (c == ';')
            skipComment();
        else if (c == '\n'){
            _tokens.push_back(Token(NEW_LINE, "\\n", _line));
            _line++;
            _pos++;
        }
        else if (c == '('){
            _tokens.push_back(Token(P_OPEN, "(", _line));
            _pos++;
        }
        else if (c == ')'){
            _tokens.push_back(Token(P_CLOSE, ")", _line));
            _pos++;
        }
        else if (std::isalpha(static_cast<unsigned char>(c)))
            readWord();
        else if (c == '-' || std::isdigit(static_cast<unsigned char>(c)))
            readNumber();
        else
            throw LexicalError("unexpected charac");
    }
    _tokens.push_back(Token(END, "", _line));
}


const std::vector<Token> &Lexer::getTokens() const{return _tokens;}

void Lexer::readNumber(){}
void Lexer::readWord(){
    std::size_t start = _pos;
    while (_pos < _src.size() && std::isalnum(static_cast<unsigned char>(_src[_pos]))){
        _pos++;
    }
    _tokens.push_back(Token(WORD, _src.substr(start, _pos - start), _line));

}
void Lexer::skipComment(){
    while (_pos < _src.size() && _src[_pos] != '\n'){
        _pos++;
    }
}
