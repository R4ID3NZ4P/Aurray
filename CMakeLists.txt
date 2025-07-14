cmake_minimum_required(VERSION 3.10)
project(Aurray LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfma -mavx2 -O3")

include_directories(include)

add_library(Aurray STATIC
    src/aurray.cpp
)

add_executable(test test/test.cpp)
target_link_libraries(test Aurray)