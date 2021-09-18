cmake_minimum_required(VERSION 3.10.1)
project(observer CXX C)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

add_executable(observer
    observer.cpp
    main.cpp
)
