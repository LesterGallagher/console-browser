
cmake_minimum_required (VERSION 2.6)
project(parse-xml)

add_library (parse-xml xml-parser.c helpers.c)

target_include_directories (parse-xml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
