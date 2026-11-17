#include "Exception.hpp"

LexicalError::LexicalError() : std::exception(), _msg("Lexical error") {}

LexicalError::LexicalError(const std::string &msg) : std::exception(), _msg(msg) {}

LexicalError::LexicalError(const LexicalError &og) : std::exception(og), _msg(og._msg) {}

LexicalError &LexicalError::operator=(const LexicalError &rhs)
{
    if (this != &rhs){
        std::exception::operator=(rhs);
        _msg = rhs._msg;
    }
    return *this;
}

LexicalError::~LexicalError() {}

const char *LexicalError::what() const noexcept
{
    return _msg.c_str();
}