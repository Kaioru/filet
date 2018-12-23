cmake_minimum_required(VERSION 3.12)
project(filet)

set(CMAKE_CXX_STANDARD 14)

file(GLOB src
    "*.h"
    "*.cpp"
)

add_executable(filet ${src})