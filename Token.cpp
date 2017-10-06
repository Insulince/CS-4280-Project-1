#include "Token.h"

using namespace std;

Token::Token(const TOKEN_IDENTIFIER tokenIdentifier, const string value, const string lineNumber) : tokenIdentifier(tokenIdentifier),
                                                                                                          value(value),
                                                                                                          lineNumber(lineNumber) {
}

Token::~Token() = default;

const TOKEN_IDENTIFIER Token::getTokenIdentifier() const {
    return tokenIdentifier;
}

const string &Token::getValue() const {
    return value;
}

const string &Token::getLineNumber() const {
    return lineNumber;
}

const string Token::toString() const {
    string output = "";

    output += "Line Number: \"";
    output += getLineNumber();
    output += "\", Token Identifier: \"";
    output += getTokenIdentifier();
    output += "\", Token Value: \"";
    output += getValue();
    output += "\"";

    return output;
}
