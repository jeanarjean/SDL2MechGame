# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#.rst:
# FindSDL2_image
# -------------
#
# Locate SDL2_image library
#
# This module defines:
#
# ::
#
#   EIGEN_LIBRARIES, the name of the library to link against
#   EIGEN_INCLUDE_DIR, where to find the headers
#   SDL2_IMAGE_FOUND, if false, do not try to link against
#   SDL2_IMAGE_VERSION_STRING - human-readable string containing the
#                              version of SDL2_image
#
#
#
# For backward compatibility the following variables are also set:
#
# ::
#
#   SDL2IMAGE_LIBRARY (same value as EIGEN_LIBRARIES)
#   EIGEN_INCLUDE_DIR (same value as EIGEN_INCLUDE_DIR)
#   EIGEN_FOUND (same value as SDL2_IMAGE_FOUND)
#
#
#
# $SDLDIR is an environment variable that would correspond to the
# ./configure --prefix=$SDLDIR used in building SDL.
#
# Created by Eric Wing.  This was influenced by the FindSDL.cmake
# module, but with modifications to recognize OS X frameworks and
# additional Unix paths (FreeBSD, etc).

if(NOT EIGEN_INCLUDE_DIR AND EIGEN_INCLUDE_DIR)
  set(EIGEN_INCLUDE_DIR ${EIGEN_INCLUDE_DIR} CACHE PATH "directory cache
entry initialized from old variable name")
endif()
find_path(EIGEN_INCLUDE_DIR EIGEN
  HINTS
    ENV EIGENEDIR
    ENV EIGENDIR
    ${EIGEN_DIR}
  PATH_SUFFIXES Eigen
                # path suffixes to search inside ENV{SDL2DIR}
                include/Eigen include
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(VC_LIB_PATH_SUFFIX lib/x64)
else()
  set(VC_LIB_PATH_SUFFIX lib/x86)
endif()

if(NOT EIGEN_LIBRARY AND EIGEN_LIBRARY_CACHE)
  set(EIGEN_LIBRARY ${EIGEN_LIBRARY_CACHE} CACHE FILEPATH "file cache entry
initialized from old variable name")
endif()
find_library(EIGEN_LIBRARIES
  NAMES EIGEN Eigen
  HINTS
    ENV EIGEN
    ENV EIGENDIR
    ${EIGEN_DIR}
    ${CMAKE_SOURCE_DIR}/extern/
  PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX} Eigen
)

set(EIGEN_LIBRARIES ${EIGEN_LIBRARY})
set(EIGEN_INCLUDE_DIRS ${EIGEN_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(EIGEN
                                  REQUIRED_VARS EIGEN_LIBRARIES EIGEN_INCLUDE_DIRS)

# for backward compatibility
set(EIGEN_LIBRARY ${EIGEN_LIBRARIES})
set(EIGEN_INCLUDE_DIR ${EIGEN_INCLUDE_DIRS})
set(EIGEN_FOUND ${EIGEN_FOUND})

mark_as_advanced(EIGEN_LIBRARY EIGEN_INCLUDE_DIR)
