# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.29.6)

# Define the project name and version
project(dgSqlite VERSION 0.0.1 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add global C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fcolor-diagnostics -fansi-escape-codes -g -Wall")

# Define source code library
add_library(source_code_lib OBJECT
    ${PROJECT_SOURCE_DIR}/src/IOUtils.cpp
    ${PROJECT_SOURCE_DIR}/src/MetaCommand.cpp
    ${PROJECT_SOURCE_DIR}/src/Statement.cpp
    ${PROJECT_SOURCE_DIR}/src/Utils.cpp
    ${PROJECT_SOURCE_DIR}/src/ReferenceWrapperString.cpp
)

# Specify include directories for the source code library
target_include_directories(
    source_code_lib PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Add the executable
add_executable(dgSqlite
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Link the executable with source code library
target_link_libraries(
    dgSqlite PRIVATE source_code_lib
)

# Include FetchContent
include(FetchContent)

# Declare and fetch GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
FetchContent_MakeAvailable(googletest)

# Define tests library
add_library(tests_lib OBJECT
    ${PROJECT_SOURCE_DIR}/tests/test_IOUtils.cpp
    ${PROJECT_SOURCE_DIR}/tests/test_MetaCommand.cpp
    ${PROJECT_SOURCE_DIR}/tests/test_Statement.cpp
    ${PROJECT_SOURCE_DIR}/tests/test_Utils.cpp
)

# Specify include directories for the tests library
target_include_directories(
    tests_lib PUBLIC ${gtest_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Add test executable
add_executable(
    dgSqliteTests
    ${PROJECT_SOURCE_DIR}/tests/test_main.cpp
)

# Link GoogleTest to test executable
target_link_libraries(
    dgSqliteTests
    source_code_lib
    tests_lib
    GTest::gtest_main
)

# Include the GoogleTest module
include(GoogleTest)

# Include CTest module
include(CTest)

# Enable testing
enable_testing()

# Discover and add test cases to CTest
gtest_discover_tests(dgSqliteTests)
