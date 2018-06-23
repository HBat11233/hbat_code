cmake_minimum_required(VERSION 3.10)
project(ATM)

set(CMAKE_CXX_STANDARD 11)

add_executable(ATM main.cpp Account.cpp Savings.cpp Credit.cpp Bank.cpp ATM.cpp)