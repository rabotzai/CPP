cmake_minimum_required(VERSION 3.10)

project(helloworld)

set(BUILD_NUMBER "0" CACHE STRING "Build number")

add_executable(helloworld_cli
        src/main.cpp
)

target_compile_definitions(
        helloworld_cli
        PRIVATE BUILD_NUMBER=${BUILD_NUMBER}
)


enable_testing()

add_executable(test_version
        tests/test_version.cpp
)

add_test(
        NAME version_test
        COMMAND test_version
)