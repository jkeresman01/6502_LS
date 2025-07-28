cmake_minimum_required(VERSION 3.15)
project(6502ls-algo)

add_library(6502ls-algo STATIC
    src/Trie.cpp
)

target_include_directories(6502ls-algo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(6502ls-algo PUBLIC cxx_std_17)

