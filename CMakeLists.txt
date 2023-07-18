cmake_minimum_required(VERSION 3.25)
project(bad-sorts)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(bad-sorts main.cpp sorts.h color-codes.h)