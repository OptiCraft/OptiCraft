cmake_minimum_required(VERSION 3.23)

project(OptiCraft)

set(SOURCE_FILES
    "src/main.cpp"
    "src/Window.hpp"
    "src/Application.hpp"
    "src/Application.cpp"
    "src/Window.cpp"
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

find_package(Vulkan REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS})

add_executable(OptiCraft ${SOURCE_FILES})
target_link_libraries(OptiCraft ${SDL2_LIBRARIES} ${Vulkan_LIBRARIES})

if(WIN32)
    add_custom_command(TARGET OptiCraft POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Copying SDL2.dll from ${SDL2_DLL} to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL}"
        "${CMAKE_CURRENT_BINARY_DIR}"
    )
endif()