cmake_minimum_required(VERSION 3.14)
project(Battleship2312)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_executable(Battleship2312 main.cpp board.cpp player.cpp)