cmake_minimum_required(VERSION 3.19)
project(interdll)

set(CMAKE_CXX_STANDARD 14)

add_library(interdll SHARED library.cpp library.h)