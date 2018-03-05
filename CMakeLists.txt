cmake_minimum_required(VERSION 3.9)
project(TPAPG)

set(CMAKE_CXX_STANDARD 11)

add_executable(TPAPG main.cpp service.cpp service.h supplier.cpp supplier.h)