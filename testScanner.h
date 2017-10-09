#ifndef P1_TESTSCANNER_H
#define P1_TESTSCANNER_H

#include <string>

class TestScanner {
private:
    bool commentMode = false;

    const int newLinesBeforeNextToken(const std::string &rawData, int &currentIndex);

public:
    TestScanner();

    ~TestScanner();

    const bool isCommentMode() const;

    void setCommentMode(const bool commentMode);

    const std::string performScan(const std::string &rawData);
};

#endif //P1_TESTSCANNER_H
