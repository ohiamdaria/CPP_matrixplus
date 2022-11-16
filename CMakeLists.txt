cmake_minimum_required(VERSION 3.22)
project(S21_matrix)

set(CMAKE_CXX_STANDARD 17)


add_executable(S21_matrix main.cpp S21Matrix.cpp S21Matrix.h s21_constructors.cpp s21_accessor_mutator.cpp s21_operators.cpp s21_functions.cpp s21_others.cpp)
