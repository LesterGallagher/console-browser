
cmake_minimum_required (VERSION 2.6)

project(console-browser)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS}")

set(ALL_SOURCES main.c)
set(ALL_SOURCES ${ALL_SOURCES} main.c console.c)

add_subdirectory(parse-json)
add_subdirectory(parse-xml)


include_directories("${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}")

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

add_executable(console-browser ${ALL_SOURCES})

target_link_libraries (console-browser LINK_PUBLIC parse-json parse-xml)

