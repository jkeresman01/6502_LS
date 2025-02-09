cmake_minimum_required(VERSION 3.15)
project(6502LSProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/Algo)
include_directories(${SRC_DIR}/Capabilities)
include_directories(${SRC_DIR}/Snippets)
include_directories(${SRC_DIR}/Config)
include_directories(${SRC_DIR}/Diagnostics)
include_directories(${SRC_DIR}/Completions)
include_directories(${SRC_DIR}/Config)
include_directories(${SRC_DIR}/Core)
include_directories(${SRC_DIR}/Enums)
include_directories(${SRC_DIR}/Errors)
include_directories(${SRC_DIR}/Messages)
include_directories(${SRC_DIR}/Params)
include_directories(${SRC_DIR}/Rpc)
include_directories(${SRC_DIR}/Types)
include_directories(${SRC_DIR}/Utils)

file(GLOB_RECURSE SOURCES
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.h
)

add_executable(6502LS ${SOURCES})

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.10.5
)

FetchContent_MakeAvailable(nlohmann_json)
target_link_libraries(6502LS PRIVATE nlohmann_json::nlohmann_json)

