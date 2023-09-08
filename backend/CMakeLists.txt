project(Data-Structures)
cmake_minimum_required(VERSION 3.0)

# compile as C++17
add_compile_options(-std=c++17)

# include directories : specify additional locaitons of header files
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# setup the directory that includes source files
file(GLOB SOURCES src/*.cpp)

# Declare a C++ executable
add_executable(
    ${PROJECT_NAME} 
    SOURCES
)

# linking external libraries
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE pthread
)