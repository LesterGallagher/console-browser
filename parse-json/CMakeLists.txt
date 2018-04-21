cmake_minimum_required (VERSION 2.6)
project (parse-json)

add_library (parse-json json-parser helpers.c)

target_include_directories (parse-json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})