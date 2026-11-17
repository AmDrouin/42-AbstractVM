#pragma once

#include <string>

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