cmake_minimum_required(VERSION 3.8)
project(P1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Token.cpp Token.h Scanner.cpp Scanner.h TestScanner.cpp TestScanner.h util.cpp util.h)
add_executable(P1 ${SOURCE_FILES})