cmake_minimum_required(VERSION 3.15)
project(Bitfield)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bitfield main.cpp include/tbitfield.h include/tset.h source/tbitfield.cpp source/tset.cpp)