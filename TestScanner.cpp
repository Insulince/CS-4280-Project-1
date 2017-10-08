#include <iostream>
#include "TestScanner.h"
#include "Scanner.h"

using namespace std;

TestScanner::TestScanner() = default;

TestScanner::~TestScanner() = default;

const bool TestScanner::isCommentMode() const {
    return commentMode;
}

void TestScanner::setCommentMode(const bool commentMode) {
    TestScanner::commentMode = commentMode;
}

const std::string TestScanner::performScan(const std::string &rawData) {
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
        } catch (const string &scannerError) {
            tokenOutput += scannerError + "\n";
            break;
        }
    } while ((TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP.at(currentToken->getTokenIdentifier()) != END_OF_FILE_TOKEN_NAME));

    return tokenOutput;
}

const int TestScanner::newLinesBeforeNextToken(const string &rawData, int &currentIndex) {
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