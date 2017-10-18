#include <iostream>
#include "testScanner.h"
#include "scanner.h"

using namespace std;

const static int EXIT_CODE_SCANNER_ERROR = 3;

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
            cerr << scannerError << endl;
            throw EXIT_CODE_SCANNER_ERROR;
        }
    } while ((TOKEN_IDENTIFIER_TO_TOKEN_NAME_MAP.at(currentToken->getTokenIdentifier()) != END_OF_FILE_TOKEN_NAME));

    return tokenOutput;
}

const int TestScanner::newLinesBeforeNextToken(const string &rawData, int &currentIndex) {
    int newLinesBeforeNextToken = 0;

    while (currentIndex < rawData.length() && nextCharacterIsNotTokenCharacter(rawData[currentIndex])) {
        if (rawData[currentIndex] == '#') {
            setCommentMode(!isCommentMode());
        }

        if (rawData[currentIndex] == '\n') {
            newLinesBeforeNextToken++;
        }

        currentIndex++;
    }

    return newLinesBeforeNextToken;
}

const bool TestScanner::nextCharacterIsNotTokenCharacter(const char nextChar) const {
    if (isCommentMode()) {
        return true;
    } else {
        return nextChar == ' ' || nextChar == '\n' || nextChar == '#';
    }
}