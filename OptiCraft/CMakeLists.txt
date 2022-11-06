cmake_minimum_required(VERSION 3.24.2)

project(OptiCraft)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

message(STATUS "Found SDL2 headers: ${SDL2_INCLUDE_DIR}")
message(STATUS "Linking to SDL2 libraries: ${SDL2_LIBRARIES}")
message(STATUS "Found SDL2 DLL: ${SDL2_DLL}")

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(OptiCraft src/main.cpp)
target_link_libraries(OptiCraft ${SDL2_LIBRARIES})

add_custom_command(TARGET OptiCraft POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying SDL2.dll from ${SDL2_DLL} to build directory"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL}"
        "${CMAKE_CURRENT_BINARY_DIR}"
)