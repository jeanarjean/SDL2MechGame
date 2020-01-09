cmake_minimum_required(VERSION 3.10)

project(SDL2MechGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE data resources/*)
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.cpp
	)
file(COPY ${data} DESTINATION resources)

include(${PROJECT_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(SDL2MechGame WIN32 Main.cpp ${SOURCES})
target_link_libraries(SDL2MechGame ${CONAN_LIBS})
