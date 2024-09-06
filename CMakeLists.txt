cmake_minimum_required(VERSION 3.12)
project(Random_Data_Generator)

set(CMAKE_CXX_STANDARD 11)

# Include directories for external libraries
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})

add_custom_target(run
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)