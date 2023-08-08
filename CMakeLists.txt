cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)

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