cmake_minimum_required(VERSION 3.23)

project(OptiCraft)

set(CMAKE_CXX_STANDARD 20)

# MinGW not supported
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	message(FATAL_ERROR "MinGW is not supported")
endif()

set(SOURCE_FILES
    "src/OptiCraft/main.cpp"
    "src/OptiCraft/Window.hpp"
    "src/OptiCraft/Application.hpp"
    "src/OptiCraft/Application.cpp"
    "src/OptiCraft/Window.cpp"
    "src/pch.hpp"
    "src/OptiCraft/ErrorHandling.cpp"
    "src/OptiCraft/Macros.hpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

find_package(Vulkan REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS})

add_subdirectory(../AssetPackCompiler/Library libarc)

add_executable(OptiCraft ${SOURCE_FILES})
target_link_libraries(OptiCraft ${SDL2_LIBRARIES} ${Vulkan_LIBRARIES})

target_precompile_headers(OptiCraft PRIVATE "src/pch.hpp")

target_compile_definitions(OptiCraft PRIVATE $<$<CONFIG:Debug>:OC_DEBUG>)

if(WIN32)
    add_custom_command(TARGET OptiCraft POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Copying SDL2.dll from ${SDL2_DLL} to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL}"
        "${CMAKE_CURRENT_BINARY_DIR}"
    )
endif()