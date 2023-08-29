cmake_minimum_required(VERSION 3.18)
Project(RapidRecharge VERSION 0.04)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)


add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_include_directories(${PROJECT_NAME} PRIVATE src)