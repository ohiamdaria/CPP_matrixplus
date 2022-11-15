cmake_minimum_required(VERSION 3.22)
project(S21_matrix)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(S21_matrix main.cpp S21Matrix.cpp S21Matrix.h)
