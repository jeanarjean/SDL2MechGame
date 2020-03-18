cmake_minimum_required(VERSION 3.10)

project(SDL2MechGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Set this to release for release 
SET( CMAKE_BUILD_TYPE Debug) 


file(GLOB_RECURSE data  ${CMAKE_SOURCE_DIR}/resources/*)
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.cpp
	)
file(COPY ${data} DESTINATION resources)

find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIR})

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

include(${PROJECT_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
# WHAT I NEED TO DO IS NOT SET THE BOX2D TO DEBUG, IT IS TO SET THE PROPER FLAGS IN MY SETUP
#set_target_properties(${CONAN_LIBS_BOX2D} PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO DEBUG)
#add_definitions(-_ITERATOR_DEBUG_LEVEL=2)

add_executable(SDL2MechGame WIN32 Main.cpp ${SOURCES})
target_link_libraries(SDL2MechGame ${CONAN_LIBS} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})
