# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-src"
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-build"
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/dashakoroleva/Desktop/CPP_matrixplus/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
