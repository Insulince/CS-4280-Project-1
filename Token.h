#ifndef P1_TOKEN_H
#define P1_TOKEN_H

#include <string>
#include "TokenIdentifier.h"

class Token {
private:
    const TOKEN_IDENTIFIER tokenIdentifier = nullptr;
    const std::string value = nullptr;
    const std::string lineNumber;
public:
    Token(const TOKEN_IDENTIFIER tokenIdentifier, const std::string value, const std::string lineNumber);

    ~Token();

    const TOKEN_IDENTIFIER getTokenIdentifier() const;

    const std::string &getValue() const;

    const std::string &getLineNumber() const;

    const std::string toString() const;
};

#endif //P1_TOKEN_H
