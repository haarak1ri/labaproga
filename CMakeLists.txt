cmake_minimum_required(VERSION 3.16)
project(MyStringProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyStringProject
        main.cpp
        MyString.cpp
        MyString.h
)

