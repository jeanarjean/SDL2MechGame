cmake_minimum_required(VERSION 3.10)

project(SDL2MechGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB_RECURSE data resources/*)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories("${CMAKE_SOURCE_DIR}/src/")
include_directories("${CMAKE_SOURCE_DIR}/data/")
file(COPY ${data} DESTINATION resources)


add_executable(SDL2MechGame WIN32 Main.cpp)
target_link_libraries(SDL2MechGame ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
