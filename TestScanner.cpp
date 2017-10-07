#include "TestScanner.h"
#include "TokenIdentifier.h"
#include "Scanner.h"

#include <iostream>

using namespace std;

TestScanner::TestScanner() = default;

bool TestScanner::isCommentMode() const {
    return commentMode;
}

void TestScanner::setCommentMode(bool commentMode) {
    TestScanner::commentMode = commentMode;
}

std::string TestScanner::preformScan(const std::string &rawData) {
    Scanner *scanner = new Scanner();
    int currentIndex = 0;
    int currentLineNumber = 1 + newLinesBeforeNextToken(rawData, currentIndex);
    Token *currentToken;
    string tokenOutput;

    do {
        try {
            currentToken = scanner->getNextToken(rawData, currentIndex, currentLineNumber);
            tokenOutput += currentToken->toString() + "\n";
            currentIndex += currentToken->getValue().length();
            currentLineNumber += newLinesBeforeNextToken(rawData, currentIndex);
        } catch (string &exception) {
            tokenOutput += exception + "\n";
            break;
        }
    } while ((TOKEN_IDENTIFIER_TO_NAME_MAP.at(currentToken->getTokenIdentifier()) != "END_OF_FILE"));

    return tokenOutput;
}

int TestScanner::newLinesBeforeNextToken(const string &rawData, int &currentIndex) {
    int newLinesBeforeNextToken = 0;

    while (currentIndex < rawData.length() && (rawData[currentIndex] == '\n' || (isCommentMode() ? true : rawData[currentIndex] == ' ') || rawData[currentIndex] == '#')) {
        if (rawData[currentIndex] == '\n') {
            newLinesBeforeNextToken++;
        }

        if (rawData[currentIndex] == '#') {
            setCommentMode(!isCommentMode());
        }

        currentIndex++;
    }

    return newLinesBeforeNextToken;
}
