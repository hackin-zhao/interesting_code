cmake_minimum_required(VERSION 3.10.1)

add_library(cpp_lib
    cpp.cpp
)

add_executable(c_invoke_cpp
    main.c
)

target_link_libraries(c_invoke_cpp
    cpp_lib
)