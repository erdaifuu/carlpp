cmake_minimum_required(VERSION 4.2)
project(carlpp CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library: exposes include/ so you can #include <carstl/vector.h>
add_library(carstl INTERFACE)
target_include_directories(carstl INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Scratch playground
add_executable(carlpp main.cpp)
target_link_libraries(carlpp PRIVATE carstl)

# GoogleTest
include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# Every tests/*_test.cpp becomes its own test target
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS tests/*_test.cpp)
foreach(src ${TEST_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
    target_link_libraries(${name} PRIVATE carstl GTest::gtest_main)
    target_compile_options(${name} PRIVATE -Wall -Wextra
            $<$<CONFIG:Debug>:-fsanitize=address,undefined -fno-omit-frame-pointer>)
    target_link_options(${name} PRIVATE $<$<CONFIG:Debug>:-fsanitize=address,undefined>)
    gtest_discover_tests(${name})
endforeach()