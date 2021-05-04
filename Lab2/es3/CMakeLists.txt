cmake_minimum_required(VERSION 3.17)
project(es3)

set(CMAKE_CXX_STANDARD 14)

add_executable(es3 main.cpp Directory.cpp Directory.h Base.cpp Base.h File.cpp File.h)