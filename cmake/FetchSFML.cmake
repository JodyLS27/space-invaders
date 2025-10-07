# Including the fetch content for SFML
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

# Setup local directory for checking
set(SFML_LOCAL "${CMAKE_CURRENT_SOURCE_DIR}/libs/sfml")

# Check if Local Copy exists
if (EXISTS ${SFML_LOCAL}/CMakeLists.txt)
    message(STATUS "Using local copy of SFML at :${SFML_LOCAL}")

    # Set local fetchcontent
    FetchContent_Declare(
            sfml
            SOURCE_DIR ${SFML_LOCAL}
    )
else ()
    message(STATUS "Fetching SFML from GitHub....")

    FetchContent_Declare(
            sfml
            GIT_REPOSITORY "https://github.com/SFML/SFML.git"
            GIT_TAG "3.0.2"
            SOURCE_DIR "${SFML_LOCAL}"
    )
endif ()

FetchContent_MakeAvailable(sfml)