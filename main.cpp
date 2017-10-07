#include <iostream>
#include <fstream>
#include "Scanner.h"

using namespace std;

const static char *ERROR_MESSAGE_ILLEGAL_QUANTITY_ARGUMENTS = "Invalid quantity of command line arguments encountered, pass either zero arguments for keyboard input, or one argument for file input.\n";
const static char *ERROR_MESSAGE_NO_SUCH_FILE = "No file with the provided name exists: \"";

const static int QUANTITY_DEFAULT_ARGUMENTS = 1;

const static int EXIT_CODE_SUCCESS = 0;
const static int EXIT_CODE_ILLEGAL_QUANTITY_ARGUMENTS = 1;
const static int EXIT_CODE_NO_SUCH_INPUT_FILE = 2;

const static char *KEYBOARD_MODE_OUTPUT_FILE_NAME = "out";
const static char *IMPLICIT_INPUT_FILE_EXTENSION = ".fs17";

bool noArgumentsPassed(int quantityCommandLineArgumentsWithoutDefaultArgument);

void runForKeyboardInput();

bool oneArgumentPassed(int quantityCommandLineArgumentsWithoutDefaultArgument);

void runForFileInput(char *const *commandLineArguments);

string getRawKeyboardData();

string getRawInputFileData(const string &inputFileName);

void processData(const string &rawData, const string &fileName);

int main(int quantityCommandLineArguments, char *commandLineArguments[]) {
    int quantityCommandLineArgumentsWithoutDefaultArgument = quantityCommandLineArguments - QUANTITY_DEFAULT_ARGUMENTS;

    if (noArgumentsPassed(quantityCommandLineArgumentsWithoutDefaultArgument)) {
        try {
            runForKeyboardInput();
        } catch (int &exitCode) {
            return exitCode;
        }
    } else if (oneArgumentPassed(quantityCommandLineArgumentsWithoutDefaultArgument)) {
        try {
            runForFileInput(commandLineArguments);
        } catch (int &exitCode) {
            return exitCode;
        }
    } else {
        cerr << ERROR_MESSAGE_ILLEGAL_QUANTITY_ARGUMENTS << endl;
        return EXIT_CODE_ILLEGAL_QUANTITY_ARGUMENTS;
    }

    return EXIT_CODE_SUCCESS;
}

bool noArgumentsPassed(int quantityCommandLineArgumentsWithoutDefaultArgument) {
    return quantityCommandLineArgumentsWithoutDefaultArgument == 0;
}

void runForKeyboardInput() {
    string rawKeyboardData = getRawKeyboardData();
    processData(rawKeyboardData, KEYBOARD_MODE_OUTPUT_FILE_NAME);
}

bool oneArgumentPassed(int quantityCommandLineArgumentsWithoutDefaultArgument) {
    return quantityCommandLineArgumentsWithoutDefaultArgument == 1;
}

void runForFileInput(char *const *commandLineArguments) {
    string inputFileName = commandLineArguments[1];
    string rawInputFileData = getRawInputFileData(inputFileName);
    processData(rawInputFileData, inputFileName);
}

string getRawKeyboardData() {
    string rawKeyboardData;
    string rawKeyboardLine;

    getline(cin, rawKeyboardLine);
    while (rawKeyboardLine != "^Z") {
        if (rawKeyboardData.empty()) {
            rawKeyboardData = rawKeyboardLine;
        } else {
            rawKeyboardData += "\n" + rawKeyboardLine;
        }
        getline(cin, rawKeyboardLine);
    }

    return rawKeyboardData;
}

string getRawInputFileData(const string &inputFileName) {
    ifstream inputFile(inputFileName + IMPLICIT_INPUT_FILE_EXTENSION);

    if (inputFile) {
        string rawInputFileData;
        string rawInputFileLine;

        while (!inputFile.eof()) {
            getline(inputFile, rawInputFileLine);
            if (rawInputFileData.empty()) {
                rawInputFileData = rawInputFileLine;
            } else {
                rawInputFileData += "\n" + rawInputFileLine;
            }
        }

        inputFile.close();

        return rawInputFileData;
    } else {
        cerr << ERROR_MESSAGE_NO_SUCH_FILE << inputFileName << "\"\n";
        throw EXIT_CODE_NO_SUCH_INPUT_FILE;
    }
}

void processData(const string &rawData, const string &fileName) {
//    cout << "Processing for file \"" << fileName << "\":\n\"\n" << rawData << "\n\"\n";

//    cout << "`\n";
//    for (int i = 0; i < rawData.length(); i++) {
//        cout << "\"" << rawData[i] << "\"\t" << (rawData[i] == '\n') << "\n";
//    }
//    cout << "`\n";

    Scanner *scanner = new Scanner();
    int currentIndex = 0;
    Token *currentToken;

    while (currentIndex != rawData.length()) {
        currentToken = scanner->getToken(rawData, currentIndex);
        cout << currentToken->toString() << endl;
        currentIndex += currentToken->getValue().length();
    }
}