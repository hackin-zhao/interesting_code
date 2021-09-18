cmake_minimum_required(VERSION 3.10.1)
project(tls CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads REQUIRED)

add_executable(tls
    main.cpp
)

target_link_libraries(tls
    ${CMAKE_THREAD_LIBS_INIT}
)