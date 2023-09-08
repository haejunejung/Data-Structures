project(DataStructuresGtest)
cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++17)

set(HEADER_DIR ${CMAKE_SOURCE_DIR}/../include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/../src)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG        "main"
)
FetchContent_MakeAvailable(googletest)

include_directories(
    ${HEADER_DIR}
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCE_DIR}/list.cpp

    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/src/list.test.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE pthread
    PRIVATE gtest
    PRIVATE gtest_main
)