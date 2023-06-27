cmake_minimum_required(VERSION 3.18)
Project(MoveToTarget VERSION 0.03)

set(CMAKE_CXX_STANDARD 20)

# Including the fetch content for SFML
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
message(STATUS "Fetching SFML....")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml"
)
FetchContent_MakeAvailable(sfml)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_sources(${PROJECT_NAME} PRIVATE "src/main.cpp"
"src/player.hpp" "src/player.cpp" "src/target.hpp" "src/target.cpp"  "src/logger.hpp" "src/logger.cpp")