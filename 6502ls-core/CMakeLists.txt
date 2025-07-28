cmake_minimum_required(VERSION 3.14)

project(ls6502-core)

add_library(ls6502-core
    src/Ls6502Client.cpp
    src/Ls6502Counter.cpp
    src/Ls6502ErrorHandler.cpp
    src/Ls6502Facade.cpp
    src/Ls6502ReqHandler.cpp
    src/Ls6502Server.cpp
)

target_include_directories(ls6502-core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(ls6502-core PUBLIC cxx_std_17)

