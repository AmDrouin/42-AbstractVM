#pragma once
#include <string>

/**
 * @brief Categories of tokens produced by the lexer
 * 
 * Every token recognized belongs to one of the categories.
 * The lexer only classifies words: the parser is responsible for checking 
 */
enum eTokenType{
    WORD,           //type name like push or int32
    P_OPEN,         //"("
    P_CLOSE,        //")"
    INTEGER,        //[0-9]
    DECIMAL,        //
    NEW_LINE,       //
    END             //
};

/**
 * @class Token
 * @brief Lexical united produced by the lexer
 * 
 * A token holds a category (eTokenType), the text as it appears in the source
 * and the line number where it was read
 */
class Token {
    public:
        //Canonical form
        Token();
        Token(const Token &og);
        Token(eTokenType type, const std::string &text, int line);
        Token & operator=(const Token &rhs);
        ~Token();

        eTokenType  getType() const;
        std::string getText() const;
        int         getLine() const;

    private:
        eTokenType  _type;
        std::string _text;
        int         _line;
};