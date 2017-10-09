cmake_minimum_required(VERSION 3.8)
project(P1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp token.cpp token.h scanner.cpp scanner.h testScanner.cpp testScanner.h util.cpp util.h)
add_executable(P1 ${SOURCE_FILES})