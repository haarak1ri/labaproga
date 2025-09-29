cmake_minimum_required(VERSION 3.16)
project(MyStringProject)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(MyStringProject
        main.cpp
        MyString.cpp
        MyString.h
)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Тесты — обязательно подключаем реализацию MyString.cpp
add_executable(mystring_test
        mystring_test.cpp
        MyString.cpp
        MyString.h
)

target_link_libraries(mystring_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mystring_test)
