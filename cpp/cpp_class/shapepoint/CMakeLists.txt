cmake_minimum_required(VERSION 3.10)
project(shapepoint)

set(CMAKE_CXX_STANDARD 11)

add_executable(shapepoint main.cpp UserApp.cpp Square.cpp Triangle.cpp Rectangle.cpp Graphics.cpp)