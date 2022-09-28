cmake_minimum_required(VERSION 3.24)
project(sample)

set(CMAKE_CXX_STANDARD 14)

add_library(sample STATIC)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
)

option(JSONCPP_WITH_TESTS OFF CACHE)
option(JSONCPP_WITH_POST_BUILD_UNITTEST OFF CACHE)
option(BUILD_SHARED_LIBS OFF CACHE)
add_subdirectory(jsoncpp)
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/jsoncpp/include>)

target_link_libraries(${PROJECT_NAME} PUBLIC jsoncpp)

set(
        SOURCES
        src/SampleImpl.cc
)

set(
        PRIVATE_HEADERS
        src/SampleImpl.h
)

set(
        PUBLIC_HEADERS
        inc/sample/Interface.h
        inc/sample/Sample.h
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

target_sources(
        ${PROJECT_NAME}
        PRIVATE ${SOURCES}
        ${PRIVATE_HEADERS}
        ${PUBLIC_HEADERS}
)
