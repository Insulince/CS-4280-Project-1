#ifndef P1_TESTSCANNER_H
#define P1_TESTSCANNER_H

#include <string>

class TestScanner {
private:
    bool commentMode = false;

    int newLinesBeforeNextToken(const std::string &rawData, int &currentIndex);

public:
    TestScanner();

    bool isCommentMode() const;

    void setCommentMode(bool commentMode);

    std::string preformScan(const std::string &rawData);
};

#endif //P1_TESTSCANNER_H
