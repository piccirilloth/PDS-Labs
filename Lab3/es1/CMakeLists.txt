cmake_minimum_required(VERSION 3.17)
project(es1)

set(CMAKE_CXX_STANDARD 17)

add_executable(es1 main.cpp MyList.hpp cmake-build-debug/MyClass.cpp cmake-build-debug/MyClass.h)