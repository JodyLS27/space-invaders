cmake_minimum_required(VERSION 3.18)
Project(RapidRecharge VERSION 0.0.4)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME})

include(cmake/FetchSFML.cmake) # Additional CMake scripts
add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)