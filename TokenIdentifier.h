#ifndef P1_TOKENIDENTIFIER_H
#define P1_TOKENIDENTIFIER_H

enum TOKEN_IDENTIFIER {
    END_OF_FILE, //Indicates the end of the file has been reached.
    IDENTIFIER, //Conforms to the regex (JavaScript notation) "/^[a-zA-Z]{1}[a-zA-Z0-9]{0,7}$/".
    INTEGER, //Conforms to the regex (JavaScript notation) "/^[0-9]{1,8}$/".
   // COMMENT, //Conforms to the regex (JavaScript notation) "/^#([^#]|\n)*#$/".
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
    OPERATOR_ASSIGNM, //"="
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
    DELIMITER_LEFT_PARANTHESIS, //"("
    DELIMITER_RIGHT_PARANTHESIS, //")"
    DELIMITER_LEFT_CURLY_BRACE, //"{"
    DELIMITER_RIGHT_CURLY_BRACE, //"}"
    DELIMITER_LEFT_SQUARE_BRACKET, //"["
    DELIMITER_RIGHT_SQUARE_BRACKET, //"]"
    DELIMITER_COMMA, //","
    DELIMITER_SEMICOLON //";"
};

#endif //P1_TOKENIDENTIFIER_H
