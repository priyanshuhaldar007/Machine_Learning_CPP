# Define the project name and specify the minimum version of CMake required
project(CppDocker)
cmake_minimum_required(VERSION 2.8)

# Find Python3 and its components (development libraries and NumPy)
find_package(Python3 COMPONENTS Interpreter Development NumPy)

# Include directories for Python3 headers and the "include" folder in your project
include_directories(${Python3_INCLUDE_DIRS} include)

# Add an executable target for your project (test.cpp)
add_executable(test src/main.cpp)

# Link the Python3 libraries to your executable
target_link_libraries(test ${Python3_LIBRARIES})

# Ensure that NumPy is also linked if it is needed by your code
target_include_directories(test PRIVATE ${Python3_NumPy_INCLUDE_DIRS})