cmake_minimum_required(VERSION 3.14)
project(Prog3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Prog3
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/phonebook.txt
        cmake-build-debug/Program3.cbp
        cmake-build-debug/Program3.exe
        CMakeLists.txt
        Driver.cpp
        Hash.cpp
        Hash.h
        README.md)
