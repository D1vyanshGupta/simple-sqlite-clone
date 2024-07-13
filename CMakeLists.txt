# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.29.6)

# Define the project name and version
project(dgSqlite VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(dgSqlite src/main.cpp)

# Optionally, link libraries (example)
# target_link_libraries(MyProject SomeLibrary)
