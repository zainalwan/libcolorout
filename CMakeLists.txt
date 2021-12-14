cmake_minimum_required(VERSION 3.22.1)

project("Color Output Library" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(LIBRARY_OUTPUT_NAME colorout)
set(LIBRARY_SOURCES src/ColorOut.cpp)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY})

add_library(shared_library SHARED ${LIBRARY_SOURCES})
target_include_directories(shared_library PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(shared_library PROPERTIES
    LIBRARY_OUTPUT_NAME ${LIBRARY_OUTPUT_NAME})

add_library(static_library STATIC ${LIBRARY_SOURCES})
target_include_directories(static_library PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(static_library PROPERTIES
    ARCHIVE_OUTPUT_NAME ${LIBRARY_OUTPUT_NAME})

function(build_test)
    set(BINARY_OUTPUT_NAME testing)
    set(BINARY_SOURCES src/main.cpp)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testing)

    add_executable(testing_bin ${BINARY_SOURCES})
    target_include_directories(testing_bin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(testing_bin shared_library)
    set_target_properties(testing_bin PROPERTIES RUNTIME_OUTPUT_NAME
        ${BINARY_OUTPUT_NAME})
endfunction()

# For testing purpose
# build_test()