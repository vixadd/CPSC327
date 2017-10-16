cmake_minimum_required(VERSION 3.5)
project(Project_1___Intro)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cc
    src/proj_one.cc
    src/proj_one.hh)

add_executable(Project_1___Intro ${SOURCE_FILES})