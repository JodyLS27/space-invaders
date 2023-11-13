# Including the fetch content for SFML
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
message(STATUS "Fetching SFML....")

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG 69ea0cd863aed1d4092b970b676924a716ff718b # v2.6.1
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/sfml"
)
FetchContent_MakeAvailable(sfml)


if(sfml_FOUND)
    message(STATUS "--- SFML Downloaded ---")
else()
    message(STATUS "!--- SFML Not found! ---!")
endif()