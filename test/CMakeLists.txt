cmake_minimum_required(VERSION 3.10)
project(6502LsTest)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(nlohmann_json)

include_directories(
    ${CMAKE_SOURCE_DIR}/../src
    ${CMAKE_SOURCE_DIR}/../src/Algo
    ${CMAKE_SOURCE_DIR}/../src/Capabilities
    ${CMAKE_SOURCE_DIR}/../src/Core
    ${CMAKE_SOURCE_DIR}/../src/Enums
    ${CMAKE_SOURCE_DIR}/../src/Errors
    ${CMAKE_SOURCE_DIR}/../src/CodeActions
    ${CMAKE_SOURCE_DIR}/../src/Diagnostics
    ${CMAKE_SOURCE_DIR}/../src/Completions
    ${CMAKE_SOURCE_DIR}/../src/Snippets
    ${CMAKE_SOURCE_DIR}/../src/Factories
    ${CMAKE_SOURCE_DIR}/../src/Messages
    ${CMAKE_SOURCE_DIR}/../src/Params
    ${CMAKE_SOURCE_DIR}/../src/Rpc
    ${CMAKE_SOURCE_DIR}/../src/Types
    ${CMAKE_SOURCE_DIR}/../src/Config
    ${CMAKE_SOURCE_DIR}/../src/Utils
)

set(SOURCE_FILES
    ../src/Algo/Trie.cpp 
    ../src/Messages/Response/CompletionResponse.cpp
    ../src/Messages/Response/InitializeResponse.cpp
    ../src/Messages/Response/ResponseMessage.cpp
    ../src/Messages/Response/ResponseError.cpp
    ../src/Messages/Notification/NotificationMessage.cpp
    ../src/Messages/Notification/PublishDiagnosticsNotification.cpp
    ../src/Params/PublishDiagnosticsParams.cpp
    ../src/Results/CompletionResult.cpp
    ../src/Results/InitializeResult.cpp
    ../src/Capabilities/ServerCapabilities.cpp
    ../src/Types/Diagnostic.cpp
    ../src/Config/ConfigurationManager.cpp
)

# TODO add rest of the tests
set(TEST_FILES
    Test.cpp
    Algo/TrieTest.cpp 
    Rpc/RpcTest.cpp 
    Messages/ResponseMessageTest.cpp
    Messages/CompletionResponseTest.cpp
    Messages/InitializeResponseTest.cpp
    Messages/ShutdownResponseTest.cpp
    Messages/PublishDiagnosticsTest.cpp
    Utils/ConvertTest.cpp 
    Utils/RequestMethodType.cpp
    Utils/MessageUtilTest.cpp
    Utils/TraceLevelTest.cpp
    Utils/AddressingModeUtil.cpp
    Utils/XMLUtilTest.cpp
    Config/ConfigurationManageTest.cpp
)

add_executable(run-tests ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(run-tests PRIVATE ${GTEST_LIBRARIES} pthread nlohmann_json::nlohmann_json)

