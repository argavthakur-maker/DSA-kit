cmake_minimum_required(VERSION 3.16)
project(DSAkit VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(dsakit INTERFACE)
target_include_directories(dsakit INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_executable(linked_list_example examples/linked_list.cpp)
target_link_libraries(linked_list_example PRIVATE dsakit)

enable_testing()
add_executable(linked_list_tests tests/linked_list_tests.cpp)
target_link_libraries(linked_list_tests PRIVATE dsakit)
add_test(NAME linked_list_tests COMMAND linked_list_tests)
