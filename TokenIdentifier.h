#ifndef P1_TOKENIDENTIFIER_H
#define P1_TOKENIDENTIFIER_H

#include <string>
#include <map>

enum TOKEN_IDENTIFIER {
    // COMMENT, //Conforms to the regex (JavaScript notation) "/^#([^#]|\n)*#$/".

    END_OF_FILE, //Indicates the end of the file has been reached.
    IDENTIFIER, //Conforms to the regex (JavaScript notation) "/^[a-zA-Z]{1}[a-zA-Z0-9]{0,7}$/".
    INTEGER, //Conforms to the regex (JavaScript notation) "/^[0-9]{1,8}$/".
    KEYWORD_BEGIN, //"Begin"
    KEYWORD_END, //"End"
    KEYWORD_CHECK, //"Check"
    KEYWORD_LOOP, //"Loop"
    KEYWORD_VOID, //"Void"
    KEYWORD_VAR, //"Var"
    KEYWORD_RETURN, //"Return"
    KEYWORD_INPUT, //"Input"
    KEYWORD_OUTPUT, //"Output"
    KEYWORD_PROGRAM, //"Program"
    OPERATOR_ASSIGN, //"="
    OPERATOR_LESS_THAN, //"<"
    OPERATOR_LESS_THAN_OR_EQUAL_TO, //"<="
    OPERATOR_GREATER_THAN, //">"
    OPERATOR_GREATER_THAN_OR_EQUAL_TO, //">="
    ILLEGAL_OPERATOR_NOT, //"!"
    OPERATOR_NOT_EQUAL_TO, //"!="
    OPERATOR_EQUAL_TO, //"=="
    OPERATOR_COLON, //":"
    OPERATOR_ADDITION, //"+"
    OPERATOR_SUBTRACTION, //"-"
    OPERATOR_MULTIPLICATION, //"*"
    OPERATOR_DIVISION, //"/"
    OPERATOR_AND, //"&"
    OPERATOR_MODULO, //"%"
    OPERATOR_CONCATENATION, //"."
    DELIMITER_LEFT_PARENTHESIS, //"("
    DELIMITER_RIGHT_PARENTHESIS, //")"
    DELIMITER_LEFT_CURLY_BRACE, //"{"
    DELIMITER_RIGHT_CURLY_BRACE, //"}"
    DELIMITER_LEFT_SQUARE_BRACKET, //"["
    DELIMITER_RIGHT_SQUARE_BRACKET, //"]"
    DELIMITER_COMMA, //","
    DELIMITER_SEMICOLON //";"
};

const std::map<TOKEN_IDENTIFIER, std::string> TOKEN_IDENTIFIER_TO_NAME_MAP = {
        {END_OF_FILE,                       "END_OF_FILE"},
        {IDENTIFIER,                        "IDENTIFIER"},
        {INTEGER,                           "INTEGER"},
        {KEYWORD_BEGIN,                     "KEYWORD_BEGIN"},
        {KEYWORD_END,                       "KEYWORD_END"},
        {KEYWORD_CHECK,                     "KEYWORD_CHECK"},
        {KEYWORD_LOOP,                      "KEYWORD_LOOP"},
        {KEYWORD_VOID,                      "KEYWORD_VOID"},
        {KEYWORD_VAR,                       "KEYWORD_VAR"},
        {KEYWORD_RETURN,                    "KEYWORD_RETURN"},
        {KEYWORD_INPUT,                     "KEYWORD_INPUT"},
        {KEYWORD_OUTPUT,                    "KEYWORD_OUTPUT"},
        {KEYWORD_PROGRAM,                   "KEYWORD_PROGRAM"},
        {OPERATOR_ASSIGN,                   "OPERATOR_ASSIGN"},
        {OPERATOR_LESS_THAN,                "OPERATOR_LESS_THAN"},
        {OPERATOR_LESS_THAN_OR_EQUAL_TO,    "OPERATOR_LESS_THAN_OR_EQUAL_TO"},
        {OPERATOR_GREATER_THAN,             "OPERATOR_GREATER_THAN"},
        {OPERATOR_GREATER_THAN_OR_EQUAL_TO, "OPERATOR_GREATER_THAN_OR_EQUAL_TO"},
        {ILLEGAL_OPERATOR_NOT,              "ILLEGAL_OPERATOR_NOT"}, //TODO
        {OPERATOR_NOT_EQUAL_TO,             "OPERATOR_NOT_EQUAL_TO"},
        {OPERATOR_EQUAL_TO,                 "OPERATOR_EQUAL_TO"},
        {OPERATOR_COLON,                    "OPERATOR_COLON"},
        {OPERATOR_ADDITION,                 "OPERATOR_ADDITION"},
        {OPERATOR_SUBTRACTION,              "OPERATOR_SUBTRACTION"},
        {OPERATOR_MULTIPLICATION,           "OPERATOR_MULTIPLICATION"},
        {OPERATOR_DIVISION,                 "OPERATOR_DIVISION"},
        {OPERATOR_AND,                      "OPERATOR_AND"},
        {OPERATOR_MODULO,                   "OPERATOR_MODULO"},
        {OPERATOR_CONCATENATION,            "OPERATOR_CONCATENATION"},
        {DELIMITER_LEFT_PARENTHESIS,        "DELIMITER_LEFT_PARENTHESIS"},
        {DELIMITER_RIGHT_PARENTHESIS,       "DELIMITER_RIGHT_PARENTHESIS"},
        {DELIMITER_LEFT_CURLY_BRACE,        "DELIMITER_LEFT_CURLY_BRACE"},
        {DELIMITER_RIGHT_CURLY_BRACE,       "DELIMITER_RIGHT_CURLY_BRACE"},
        {DELIMITER_LEFT_SQUARE_BRACKET,     "DELIMITER_LEFT_SQUARE_BRACKET"},
        {DELIMITER_RIGHT_SQUARE_BRACKET,    "DELIMITER_RIGHT_SQUARE_BRACKET"},
        {DELIMITER_COMMA,                   "DELIMITER_COMMA"},
        {DELIMITER_SEMICOLON,               "DELIMITER_SEMICOLON"}
};

#endif //P1_TOKENIDENTIFIER_H
