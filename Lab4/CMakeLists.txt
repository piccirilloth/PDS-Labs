cmake_minimum_required(VERSION 3.19)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab4 main.cpp MapperInput.cpp MapperInput.h Result.cpp Result.h Mapper.hpp ReducerInput.cpp ReducerInput.h Reducer.hpp)