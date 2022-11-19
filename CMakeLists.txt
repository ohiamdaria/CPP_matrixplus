

cmake_minimum_required(VERSION 3.22)
project(S21_matrix)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TARGET_LIBRARY s21_matrix_oop)
set(TARGET_TEST tests)

set(MORE_CXX_FLAGS "-std=c++17")
set(TESTFILE_FLAGS "")
set(TEST_FLAGS -Wall -Werror -Wextra -Wpedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -g)
set(COVERAGE_FLAGS --coverage)

#add_executable(S21_matrix main.cpp s21_matrix_oop.h core/s21_constructors.cpp core/s21_accessor_mutator.cpp operators/s21_operators.cpp arithmetic/s21_functions.cpp comparison/s21_others.cpp)

set(SOURCE core/s21_constructors.cpp core/s21_accessor_mutator.cpp operators/s21_operators.cpp arithmetic/s21_functions.cpp comparison/s21_others.cpp)
set(TEST_SOURCE test/test_constructors.cpp test/test_functions.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "TEST")
    set(MORE_CXX_FLAGS ${MORE_CXX_FLAGS} ${TEST_FLAGS} ${COVERAGE_FLAGS})
    set(TESTFILE_FLAGS ${TESTFILE_FLAGS} ${TEST_FLAGS})
endif()

include_directories(.)

add_library(${TARGET_LIBRARY} STATIC ${SOURCE})

target_compile_options(${TARGET_LIBRARY} PRIVATE ${CMAKE_CXX_FLAGS} ${MORE_CXX_FLAGS})
target_compile_features(${TARGET_LIBRARY} PRIVATE cxx_std_17)
target_link_options(${TARGET_LIBRARY} PRIVATE ${CMAKE_CXX_FLAGS} ${MORE_CXX_FLAGS})

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(${TARGET_TEST} ${TEST_SOURCE})
target_compile_features(${TARGET_TEST} PRIVATE cxx_std_17)
target_compile_options(${TARGET_TEST} PRIVATE ${TESTFILE_FLAGS} ${CMAKE_CXX_FLAGS})

if (CMAKE_BUILD_TYPE STREQUAL "TEST")
    target_link_options(${TARGET_TEST} PRIVATE ${TESTFILE_FLAGS} ${COVERAGE_FLAGS})
else()
    target_link_options(${TARGET_TEST} PRIVATE ${TESTFILE_FLAGS})
endif()

target_link_libraries(${TARGET_TEST} ${TARGET_LIBRARY} GTest::gtest_main)