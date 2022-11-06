cmake_minimum_required(VERSION 3.24.2)

project(OptiCraft)

if(MINGW)
    message(FATAL_ERROR "MinGW is not supported!")
endif()

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(OptiCraft)