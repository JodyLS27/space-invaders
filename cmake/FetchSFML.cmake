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

if(sfml_FOUND)
    message(STATUS "SFML Downloaded...")
else()
    message(STATUS "SFML Not found!")
endif()