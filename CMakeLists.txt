cmake_minimum_required(VERSION 3.7)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BankAccount.cpp BankAccount.h)
add_executable(untitled1 ${SOURCE_FILES})