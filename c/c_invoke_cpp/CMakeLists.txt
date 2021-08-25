cmake_minimum_required(VERSION 3.10.1)
project(c_invoke_cpp CXX C)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

add_library(cpp_lib SHARED
    cpp.cpp
    cpp_wapper.cpp
)

add_executable(c_invoke_cpp
    main.c
)

target_link_libraries(c_invoke_cpp
    cpp_lib
)