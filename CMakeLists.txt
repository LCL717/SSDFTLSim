cmake_minimum_required(VERSION 3.0)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to Debug to include debugging information
set(CMAKE_BUILD_TYPE Debug)

# Add your source files here
set(SOURCES
    main.cpp
    ftl.cpp
    block.cpp
    nand.cpp
    page.cpp
    trace.cpp
    measurement.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} ${SOURCES})
