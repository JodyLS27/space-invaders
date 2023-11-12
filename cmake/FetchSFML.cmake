# Including the fetch content for SFML
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
message(STATUS "Fetching SFML....")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml"
)
FetchContent_MakeAvailable(sfml)


if(sfml_FOUND)
    message(STATUS "--- SFML Downloaded ---")
else()
    message(STATUS "!--- SFML Not found! ---!")
endif()