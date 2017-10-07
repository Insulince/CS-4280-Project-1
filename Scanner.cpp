#include <map>
#include <iostream>
#include <cstring>
#include "Scanner.h"
#include "util.h"

using namespace std;

Scanner::Scanner() {
}

Token *Scanner::getNextToken(const std::string &rawData, int currentIndex, int currentLineNumber) {
    int state = INTERMEDIATE_STATE_INITIAL;
    string value;
    TOKEN_IDENTIFIER candidateToken = END_OF_FILE;

    bool stateIsNotFinal = true;

    while (stateIsNotFinal) {
        char nextChar = rawData[currentIndex];

        if (nextChar && nextChar != '#') {
            try {
                state = FSA_TABLE[TOKEN_IDENTIFIER_TO_FSA_TABLE_ROW_INDEX_MAP.at(candidateToken)][CHARACTER_TO_FSA_TABLE_COLUMN_INDEX_MAP.at(nextChar)];
                candidateToken = STATE_TO_TOKEN_IDENTIFIER_MAP.at(state);
            } catch (std::out_of_range &exception) {
                string error = "Scanner Error: unrecognized character \"";
                error += nextChar;
                error += "\" on line \"";
                error += to_string(currentLineNumber);
                error += "\".";

                throw error;
            }
        } else {
            state = 9999;
        }

        if (state >= 0) {
            if (state < 1000) {
                value += nextChar;
                currentIndex++;
            } else {
                stateIsNotFinal = false;
            }
        } else {
            //TODO Handle error states here?
            stateIsNotFinal = false;
        }
    }

    if (candidateToken == IDENTIFIER) {
        string trimmedValue = trim(value);

        if (trimmedValue == "Begin") {
            candidateToken = KEYWORD_BEGIN;
        } else if (trimmedValue == "End") {
            candidateToken = KEYWORD_END;
        } else if (trimmedValue == "Check") {
            candidateToken = KEYWORD_CHECK;
        } else if (trimmedValue == "Loop") {
            candidateToken = KEYWORD_LOOP;
        } else if (trimmedValue == "Void") {
            candidateToken = KEYWORD_VOID;
        } else if (trimmedValue == "Var") {
            candidateToken = KEYWORD_VAR;
        } else if (trimmedValue == "Return") {
            candidateToken = KEYWORD_RETURN;
        } else if (trimmedValue == "Input") {
            candidateToken = KEYWORD_INPUT;
        } else if (trimmedValue == "Output") {
            candidateToken = KEYWORD_OUTPUT;
        } else if (trimmedValue == "Program") {
            candidateToken = KEYWORD_PROGRAM;
        }
    }

    Token *token = new Token(candidateToken, value, to_string(currentLineNumber));

    return token;
}
