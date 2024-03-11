cmake_minimum_required(VERSION 3.28)
project(QueryBuilder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions("DATA_PATH=${CMAKE_SOURCE_DIR}/data")

add_executable(query_builder)
target_sources(query_builder
    PUBLIC
        FILE_SET CXX_MODULES FILES
            src/bvh_reader.cxx
            src/data_structures.cxx
    PRIVATE
        src/query_builder.cpp
)