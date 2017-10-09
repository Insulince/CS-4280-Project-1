For P1 I am using option 3: FSA Table + Driver.

The FSA Table is declared in "scanner.h" and erected in "scanner.cpp" as the variable "const int FSA_TABLE[][]"".

The driver is the function "const std::string TestScanner::performScan(const std::string &rawData)" in "testScanner.cpp".

The table is huge, but this is mostly because of the length of the names of the enums and constants I used to make the table more english-readable. I also submitted a file called "DFSA Table.xlsx" which is an excel file modeling my FSA table using the actual state codes which will make it much easier to see what's going on (if you wish to explore).