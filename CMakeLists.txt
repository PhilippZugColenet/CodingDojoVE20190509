cmake_minimum_required(VERSION 3.3)

project(CodingDojoVE)

add_executable (CodingDojoVE main.cpp kata.cpp)

target_compile_options(CodingDojoVE PUBLIC -std=c++14 -Wextra)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

target_link_libraries(CodingDojoVE
        CppUTest
        #CppUTestExt
        )
