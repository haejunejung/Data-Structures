project(Data-Structures)
cmake_minimum_required(VERSION 3.0)

# compile as C++17
add_compile_options(-std=c++17)

# include directories : specify additional locaitons of header files
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# Declare a C++ executable
add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/list.cpp
)

# linking external libraries
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE pthread
)