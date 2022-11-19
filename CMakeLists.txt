cmake_minimum_required(VERSION 3.22)
project(S21_matrix)

set(CMAKE_CXX_STANDARD 17)


add_executable(S21_matrix main.cpp s21_matrix_oop.h core/s21_constructors.cpp core/s21_accessor_mutator.cpp operators/s21_operators.cpp arithmetic/s21_functions.cpp comparison/s21_others.cpp)
