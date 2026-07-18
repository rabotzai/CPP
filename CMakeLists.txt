cmake_minimum_required(VERSION 3.14)

project(helloworld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_NUMBER "0" CACHE STRING "Build number")


add_executable(helloworld_cli
        src/main.cpp
)


target_compile_definitions(
        helloworld_cli
        PRIVATE BUILD_NUMBER=${BUILD_NUMBER}
)


# GoogleTest

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)


FetchContent_MakeAvailable(googletest)


enable_testing()


add_executable(
        test_version
        tests/test_version.cpp
)


target_link_libraries(
        test_version
        GTest::gtest_main
)


include(GoogleTest)

gtest_discover_tests(test_version)