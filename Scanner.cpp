#include <map>
#include "Scanner.h"

using namespace std;

Scanner::Scanner() {
}

Token *Scanner::getToken(const std::string &rawData, int currentIndex) {
    int state = INTERMEDIATE_STATE_INITIAL;
    string value;
    TOKEN_IDENTIFIER currentTokenIdentifier = END_OF_FILE;

    while (state >= 0 && state < 1000) {
        char nextChar = rawData[currentIndex];

        if (nextChar != '\n') {
            state = FSA_TABLE[TOKEN_IDENTIFIER_TO_FSA_TABLE_ROW_INDEX_MAP.at(currentTokenIdentifier)][CHARACTER_TO_FSA_TABLE_COLUMN_INDEX_MAP.at(nextChar)];
            currentTokenIdentifier = STATE_TO_TOKEN_IDENTIFIER_MAP.at(state);
        }

        value += nextChar;
        currentIndex++;
    }

    Token *token = new Token(currentTokenIdentifier, value, to_string(0));

    return token;
}
