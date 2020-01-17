include(CMakeParseArguments)

macro(conan_find_apple_frameworks FRAMEWORKS_FOUND FRAMEWORKS)
    if(APPLE)
        if(CMAKE_BUILD_TYPE)
            if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
                set(CONAN_FRAMEWORKS ${CONAN_FRAMEWORKS_DEBUG} ${CONAN_FRAMEWORKS})
                set(CONAN_FRAMEWORK_DIRS ${CONAN_FRAMEWORK_DIRS_DEBUG} ${CONAN_FRAMEWORK_DIRS})
            elseif(${CMAKE_BUILD_TYPE} MATCHES "Release")
                set(CONAN_FRAMEWORKS ${CONAN_FRAMEWORKS_RELEASE} ${CONAN_BUILD_MODULES_PATHS})
                set(CONAN_FRAMEWORK_DIRS ${CONAN_FRAMEWORK_DIRS_RELEASE} ${CONAN_FRAMEWORK_DIRS})
            elseif(${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo")
                set(CONAN_FRAMEWORKS ${CONAN_FRAMEWORKS_RELWITHDEBINFO} ${CONAN_BUILD_MODULES_PATHS})
                set(CONAN_FRAMEWORK_DIRS ${CONAN_FRAMEWORK_DIRS_RELWITHDEBINFO} ${CONAN_FRAMEWORK_DIRS})
            elseif(${CMAKE_BUILD_TYPE} MATCHES "MinSizeRel")
                set(CONAN_FRAMEWORKS ${CONAN_FRAMEWORKS_MINSIZEREL} ${CONAN_BUILD_MODULES_PATHS})
                set(CONAN_FRAMEWORK_DIRS ${CONAN_FRAMEWORK_DIRS_MINSIZEREL} ${CONAN_FRAMEWORK_DIRS})
            endif()
        endif()
        foreach(_FRAMEWORK ${FRAMEWORKS})
            # https://cmake.org/pipermail/cmake-developers/2017-August/030199.html
            find_library(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND NAME ${_FRAMEWORK} PATHS ${CONAN_FRAMEWORK_DIRS})
            if(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND)
                list(APPEND ${FRAMEWORKS_FOUND} ${CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND})
            else()
                message(FATAL_ERROR "Framework library ${_FRAMEWORK} not found in paths: ${CONAN_FRAMEWORK_DIRS}")
            endif()
        endforeach()
    endif()
endmacro()


set(CONAN_ENTT_ROOT "C:/Users/calm/.conan/data/entt/3.2.2/skypjack/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9")
set(CONAN_INCLUDE_DIRS_ENTT "C:/Users/calm/.conan/data/entt/3.2.2/skypjack/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include")
set(CONAN_LIB_DIRS_ENTT )
set(CONAN_BIN_DIRS_ENTT )
set(CONAN_RES_DIRS_ENTT )
set(CONAN_SRC_DIRS_ENTT )
set(CONAN_BUILD_DIRS_ENTT "C:/Users/calm/.conan/data/entt/3.2.2/skypjack/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/")
set(CONAN_FRAMEWORK_DIRS_ENTT )
set(CONAN_LIBS_ENTT )
set(CONAN_PKG_LIBS_ENTT )
set(CONAN_SYSTEM_LIBS_ENTT )
set(CONAN_FRAMEWORKS_ENTT )
set(CONAN_FRAMEWORKS_FOUND_ENTT "")  # Will be filled later
set(CONAN_DEFINES_ENTT )
set(CONAN_BUILD_MODULES_PATHS_ENTT )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_ENTT )

set(CONAN_C_FLAGS_ENTT "")
set(CONAN_CXX_FLAGS_ENTT "")
set(CONAN_SHARED_LINKER_FLAGS_ENTT "")
set(CONAN_EXE_LINKER_FLAGS_ENTT "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_ENTT_LIST "")
set(CONAN_CXX_FLAGS_ENTT_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_ENTT_LIST "")
set(CONAN_EXE_LINKER_FLAGS_ENTT_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_ENTT "${CONAN_FRAMEWORKS_ENTT}")
# Append to aggregated values variable
set(CONAN_LIBS_ENTT ${CONAN_PKG_LIBS_ENTT} ${CONAN_SYSTEM_LIBS_ENTT} ${CONAN_FRAMEWORKS_FOUND_ENTT})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_ENTT ${CONAN_PKG_LIBS_ENTT} ${CONAN_FRAMEWORKS_FOUND_ENTT})


set(CONAN_EIGEN3_ROOT "C:/Users/calm/.conan/data/eigen/3.3.7/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9")
set(CONAN_INCLUDE_DIRS_EIGEN3 "C:/Users/calm/.conan/data/eigen/3.3.7/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include/eigen3")
set(CONAN_LIB_DIRS_EIGEN3 )
set(CONAN_BIN_DIRS_EIGEN3 )
set(CONAN_RES_DIRS_EIGEN3 )
set(CONAN_SRC_DIRS_EIGEN3 )
set(CONAN_BUILD_DIRS_EIGEN3 "C:/Users/calm/.conan/data/eigen/3.3.7/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/")
set(CONAN_FRAMEWORK_DIRS_EIGEN3 )
set(CONAN_LIBS_EIGEN3 )
set(CONAN_PKG_LIBS_EIGEN3 )
set(CONAN_SYSTEM_LIBS_EIGEN3 )
set(CONAN_FRAMEWORKS_EIGEN3 )
set(CONAN_FRAMEWORKS_FOUND_EIGEN3 "")  # Will be filled later
set(CONAN_DEFINES_EIGEN3 )
set(CONAN_BUILD_MODULES_PATHS_EIGEN3 )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_EIGEN3 )

set(CONAN_C_FLAGS_EIGEN3 "")
set(CONAN_CXX_FLAGS_EIGEN3 "")
set(CONAN_SHARED_LINKER_FLAGS_EIGEN3 "")
set(CONAN_EXE_LINKER_FLAGS_EIGEN3 "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_EIGEN3_LIST "")
set(CONAN_CXX_FLAGS_EIGEN3_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_EIGEN3_LIST "")
set(CONAN_EXE_LINKER_FLAGS_EIGEN3_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_EIGEN3 "${CONAN_FRAMEWORKS_EIGEN3}")
# Append to aggregated values variable
set(CONAN_LIBS_EIGEN3 ${CONAN_PKG_LIBS_EIGEN3} ${CONAN_SYSTEM_LIBS_EIGEN3} ${CONAN_FRAMEWORKS_FOUND_EIGEN3})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_EIGEN3 ${CONAN_PKG_LIBS_EIGEN3} ${CONAN_FRAMEWORKS_FOUND_EIGEN3})


set(CONAN_SDL2_IMAGE_ROOT "C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd")
set(CONAN_INCLUDE_DIRS_SDL2_IMAGE "C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/include"
			"C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/include/SDL2")
set(CONAN_LIB_DIRS_SDL2_IMAGE "C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/lib")
set(CONAN_BIN_DIRS_SDL2_IMAGE )
set(CONAN_RES_DIRS_SDL2_IMAGE )
set(CONAN_SRC_DIRS_SDL2_IMAGE )
set(CONAN_BUILD_DIRS_SDL2_IMAGE "C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/")
set(CONAN_FRAMEWORK_DIRS_SDL2_IMAGE )
set(CONAN_LIBS_SDL2_IMAGE SDL2_image)
set(CONAN_PKG_LIBS_SDL2_IMAGE SDL2_image)
set(CONAN_SYSTEM_LIBS_SDL2_IMAGE )
set(CONAN_FRAMEWORKS_SDL2_IMAGE )
set(CONAN_FRAMEWORKS_FOUND_SDL2_IMAGE "")  # Will be filled later
set(CONAN_DEFINES_SDL2_IMAGE )
set(CONAN_BUILD_MODULES_PATHS_SDL2_IMAGE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_SDL2_IMAGE )

set(CONAN_C_FLAGS_SDL2_IMAGE "")
set(CONAN_CXX_FLAGS_SDL2_IMAGE "")
set(CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE "")
set(CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_SDL2_IMAGE_LIST "")
set(CONAN_CXX_FLAGS_SDL2_IMAGE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_SDL2_IMAGE "${CONAN_FRAMEWORKS_SDL2_IMAGE}")
# Append to aggregated values variable
set(CONAN_LIBS_SDL2_IMAGE ${CONAN_PKG_LIBS_SDL2_IMAGE} ${CONAN_SYSTEM_LIBS_SDL2_IMAGE} ${CONAN_FRAMEWORKS_FOUND_SDL2_IMAGE})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_SDL2_IMAGE ${CONAN_PKG_LIBS_SDL2_IMAGE} ${CONAN_FRAMEWORKS_FOUND_SDL2_IMAGE})


set(CONAN_BOX2D_ROOT "C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714")
set(CONAN_INCLUDE_DIRS_BOX2D "C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714/include")
set(CONAN_LIB_DIRS_BOX2D "C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714/lib")
set(CONAN_BIN_DIRS_BOX2D )
set(CONAN_RES_DIRS_BOX2D )
set(CONAN_SRC_DIRS_BOX2D )
set(CONAN_BUILD_DIRS_BOX2D "C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714/")
set(CONAN_FRAMEWORK_DIRS_BOX2D )
set(CONAN_LIBS_BOX2D Box2D)
set(CONAN_PKG_LIBS_BOX2D Box2D)
set(CONAN_SYSTEM_LIBS_BOX2D )
set(CONAN_FRAMEWORKS_BOX2D )
set(CONAN_FRAMEWORKS_FOUND_BOX2D "")  # Will be filled later
set(CONAN_DEFINES_BOX2D )
set(CONAN_BUILD_MODULES_PATHS_BOX2D )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_BOX2D )

set(CONAN_C_FLAGS_BOX2D "")
set(CONAN_CXX_FLAGS_BOX2D "")
set(CONAN_SHARED_LINKER_FLAGS_BOX2D "")
set(CONAN_EXE_LINKER_FLAGS_BOX2D "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_BOX2D_LIST "")
set(CONAN_CXX_FLAGS_BOX2D_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_BOX2D_LIST "")
set(CONAN_EXE_LINKER_FLAGS_BOX2D_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_BOX2D "${CONAN_FRAMEWORKS_BOX2D}")
# Append to aggregated values variable
set(CONAN_LIBS_BOX2D ${CONAN_PKG_LIBS_BOX2D} ${CONAN_SYSTEM_LIBS_BOX2D} ${CONAN_FRAMEWORKS_FOUND_BOX2D})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_BOX2D ${CONAN_PKG_LIBS_BOX2D} ${CONAN_FRAMEWORKS_FOUND_BOX2D})


set(CONAN_SDL2_ROOT "C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264")
set(CONAN_INCLUDE_DIRS_SDL2 "C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/include"
			"C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/include/SDL2")
set(CONAN_LIB_DIRS_SDL2 "C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/lib")
set(CONAN_BIN_DIRS_SDL2 )
set(CONAN_RES_DIRS_SDL2 )
set(CONAN_SRC_DIRS_SDL2 )
set(CONAN_BUILD_DIRS_SDL2 "C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/")
set(CONAN_FRAMEWORK_DIRS_SDL2 )
set(CONAN_LIBS_SDL2 SDL2 SDL2main)
set(CONAN_PKG_LIBS_SDL2 SDL2 SDL2main)
set(CONAN_SYSTEM_LIBS_SDL2 user32 gdi32 winmm imm32 ole32 oleaut32 version uuid advapi32 setupapi shell32)
set(CONAN_FRAMEWORKS_SDL2 )
set(CONAN_FRAMEWORKS_FOUND_SDL2 "")  # Will be filled later
set(CONAN_DEFINES_SDL2 )
set(CONAN_BUILD_MODULES_PATHS_SDL2 )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_SDL2 )

set(CONAN_C_FLAGS_SDL2 "")
set(CONAN_CXX_FLAGS_SDL2 "")
set(CONAN_SHARED_LINKER_FLAGS_SDL2 "")
set(CONAN_EXE_LINKER_FLAGS_SDL2 "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_SDL2_LIST "")
set(CONAN_CXX_FLAGS_SDL2_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_SDL2_LIST "")
set(CONAN_EXE_LINKER_FLAGS_SDL2_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_SDL2 "${CONAN_FRAMEWORKS_SDL2}")
# Append to aggregated values variable
set(CONAN_LIBS_SDL2 ${CONAN_PKG_LIBS_SDL2} ${CONAN_SYSTEM_LIBS_SDL2} ${CONAN_FRAMEWORKS_FOUND_SDL2})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_SDL2 ${CONAN_PKG_LIBS_SDL2} ${CONAN_FRAMEWORKS_FOUND_SDL2})


set(CONAN_LIBTIFF_ROOT "C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b")
set(CONAN_INCLUDE_DIRS_LIBTIFF "C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/include")
set(CONAN_LIB_DIRS_LIBTIFF "C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/lib")
set(CONAN_BIN_DIRS_LIBTIFF )
set(CONAN_RES_DIRS_LIBTIFF )
set(CONAN_SRC_DIRS_LIBTIFF )
set(CONAN_BUILD_DIRS_LIBTIFF "C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/")
set(CONAN_FRAMEWORK_DIRS_LIBTIFF )
set(CONAN_LIBS_LIBTIFF tiffd tiffxxd)
set(CONAN_PKG_LIBS_LIBTIFF tiffd tiffxxd)
set(CONAN_SYSTEM_LIBS_LIBTIFF )
set(CONAN_FRAMEWORKS_LIBTIFF )
set(CONAN_FRAMEWORKS_FOUND_LIBTIFF "")  # Will be filled later
set(CONAN_DEFINES_LIBTIFF )
set(CONAN_BUILD_MODULES_PATHS_LIBTIFF )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_LIBTIFF )

set(CONAN_C_FLAGS_LIBTIFF "")
set(CONAN_CXX_FLAGS_LIBTIFF "")
set(CONAN_SHARED_LINKER_FLAGS_LIBTIFF "")
set(CONAN_EXE_LINKER_FLAGS_LIBTIFF "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_LIBTIFF_LIST "")
set(CONAN_CXX_FLAGS_LIBTIFF_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_LIBTIFF_LIST "")
set(CONAN_EXE_LINKER_FLAGS_LIBTIFF_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_LIBTIFF "${CONAN_FRAMEWORKS_LIBTIFF}")
# Append to aggregated values variable
set(CONAN_LIBS_LIBTIFF ${CONAN_PKG_LIBS_LIBTIFF} ${CONAN_SYSTEM_LIBS_LIBTIFF} ${CONAN_FRAMEWORKS_FOUND_LIBTIFF})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_LIBTIFF ${CONAN_PKG_LIBS_LIBTIFF} ${CONAN_FRAMEWORKS_FOUND_LIBTIFF})


set(CONAN_LIBJPEG_ROOT "C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714")
set(CONAN_INCLUDE_DIRS_LIBJPEG "C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/include")
set(CONAN_LIB_DIRS_LIBJPEG "C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/lib")
set(CONAN_BIN_DIRS_LIBJPEG )
set(CONAN_RES_DIRS_LIBJPEG )
set(CONAN_SRC_DIRS_LIBJPEG )
set(CONAN_BUILD_DIRS_LIBJPEG "C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/")
set(CONAN_FRAMEWORK_DIRS_LIBJPEG )
set(CONAN_LIBS_LIBJPEG libjpeg)
set(CONAN_PKG_LIBS_LIBJPEG libjpeg)
set(CONAN_SYSTEM_LIBS_LIBJPEG )
set(CONAN_FRAMEWORKS_LIBJPEG )
set(CONAN_FRAMEWORKS_FOUND_LIBJPEG "")  # Will be filled later
set(CONAN_DEFINES_LIBJPEG )
set(CONAN_BUILD_MODULES_PATHS_LIBJPEG )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_LIBJPEG )

set(CONAN_C_FLAGS_LIBJPEG "")
set(CONAN_CXX_FLAGS_LIBJPEG "")
set(CONAN_SHARED_LINKER_FLAGS_LIBJPEG "")
set(CONAN_EXE_LINKER_FLAGS_LIBJPEG "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_LIBJPEG_LIST "")
set(CONAN_CXX_FLAGS_LIBJPEG_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_LIBJPEG_LIST "")
set(CONAN_EXE_LINKER_FLAGS_LIBJPEG_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_LIBJPEG "${CONAN_FRAMEWORKS_LIBJPEG}")
# Append to aggregated values variable
set(CONAN_LIBS_LIBJPEG ${CONAN_PKG_LIBS_LIBJPEG} ${CONAN_SYSTEM_LIBS_LIBJPEG} ${CONAN_FRAMEWORKS_FOUND_LIBJPEG})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_LIBJPEG ${CONAN_PKG_LIBS_LIBJPEG} ${CONAN_FRAMEWORKS_FOUND_LIBJPEG})


set(CONAN_LIBPNG_ROOT "C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b")
set(CONAN_INCLUDE_DIRS_LIBPNG "C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/include")
set(CONAN_LIB_DIRS_LIBPNG "C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/lib")
set(CONAN_BIN_DIRS_LIBPNG )
set(CONAN_RES_DIRS_LIBPNG )
set(CONAN_SRC_DIRS_LIBPNG )
set(CONAN_BUILD_DIRS_LIBPNG "C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/")
set(CONAN_FRAMEWORK_DIRS_LIBPNG )
set(CONAN_LIBS_LIBPNG libpng16d)
set(CONAN_PKG_LIBS_LIBPNG libpng16d)
set(CONAN_SYSTEM_LIBS_LIBPNG )
set(CONAN_FRAMEWORKS_LIBPNG )
set(CONAN_FRAMEWORKS_FOUND_LIBPNG "")  # Will be filled later
set(CONAN_DEFINES_LIBPNG )
set(CONAN_BUILD_MODULES_PATHS_LIBPNG )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_LIBPNG )

set(CONAN_C_FLAGS_LIBPNG "")
set(CONAN_CXX_FLAGS_LIBPNG "")
set(CONAN_SHARED_LINKER_FLAGS_LIBPNG "")
set(CONAN_EXE_LINKER_FLAGS_LIBPNG "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_LIBPNG_LIST "")
set(CONAN_CXX_FLAGS_LIBPNG_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_LIBPNG_LIST "")
set(CONAN_EXE_LINKER_FLAGS_LIBPNG_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_LIBPNG "${CONAN_FRAMEWORKS_LIBPNG}")
# Append to aggregated values variable
set(CONAN_LIBS_LIBPNG ${CONAN_PKG_LIBS_LIBPNG} ${CONAN_SYSTEM_LIBS_LIBPNG} ${CONAN_FRAMEWORKS_FOUND_LIBPNG})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_LIBPNG ${CONAN_PKG_LIBS_LIBPNG} ${CONAN_FRAMEWORKS_FOUND_LIBPNG})


set(CONAN_LIBWEBP_ROOT "C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e")
set(CONAN_INCLUDE_DIRS_LIBWEBP "C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e/include")
set(CONAN_LIB_DIRS_LIBWEBP "C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e/lib")
set(CONAN_BIN_DIRS_LIBWEBP )
set(CONAN_RES_DIRS_LIBWEBP )
set(CONAN_SRC_DIRS_LIBWEBP )
set(CONAN_BUILD_DIRS_LIBWEBP "C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e/")
set(CONAN_FRAMEWORK_DIRS_LIBWEBP )
set(CONAN_LIBS_LIBWEBP webpmux webpdemux webpdecoder webp)
set(CONAN_PKG_LIBS_LIBWEBP webpmux webpdemux webpdecoder webp)
set(CONAN_SYSTEM_LIBS_LIBWEBP )
set(CONAN_FRAMEWORKS_LIBWEBP )
set(CONAN_FRAMEWORKS_FOUND_LIBWEBP "")  # Will be filled later
set(CONAN_DEFINES_LIBWEBP )
set(CONAN_BUILD_MODULES_PATHS_LIBWEBP )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_LIBWEBP )

set(CONAN_C_FLAGS_LIBWEBP "")
set(CONAN_CXX_FLAGS_LIBWEBP "")
set(CONAN_SHARED_LINKER_FLAGS_LIBWEBP "")
set(CONAN_EXE_LINKER_FLAGS_LIBWEBP "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_LIBWEBP_LIST "")
set(CONAN_CXX_FLAGS_LIBWEBP_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_LIBWEBP_LIST "")
set(CONAN_EXE_LINKER_FLAGS_LIBWEBP_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_LIBWEBP "${CONAN_FRAMEWORKS_LIBWEBP}")
# Append to aggregated values variable
set(CONAN_LIBS_LIBWEBP ${CONAN_PKG_LIBS_LIBWEBP} ${CONAN_SYSTEM_LIBS_LIBWEBP} ${CONAN_FRAMEWORKS_FOUND_LIBWEBP})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_LIBWEBP ${CONAN_PKG_LIBS_LIBWEBP} ${CONAN_FRAMEWORKS_FOUND_LIBWEBP})


set(CONAN_ZLIB_ROOT "C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714")
set(CONAN_INCLUDE_DIRS_ZLIB "C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/include")
set(CONAN_LIB_DIRS_ZLIB "C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/lib")
set(CONAN_BIN_DIRS_ZLIB )
set(CONAN_RES_DIRS_ZLIB )
set(CONAN_SRC_DIRS_ZLIB )
set(CONAN_BUILD_DIRS_ZLIB "C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/")
set(CONAN_FRAMEWORK_DIRS_ZLIB )
set(CONAN_LIBS_ZLIB zlib)
set(CONAN_PKG_LIBS_ZLIB zlib)
set(CONAN_SYSTEM_LIBS_ZLIB )
set(CONAN_FRAMEWORKS_ZLIB )
set(CONAN_FRAMEWORKS_FOUND_ZLIB "")  # Will be filled later
set(CONAN_DEFINES_ZLIB )
set(CONAN_BUILD_MODULES_PATHS_ZLIB )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_ZLIB )

set(CONAN_C_FLAGS_ZLIB "")
set(CONAN_CXX_FLAGS_ZLIB "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_ZLIB_LIST "")
set(CONAN_CXX_FLAGS_ZLIB_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_LIST "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_ZLIB "${CONAN_FRAMEWORKS_ZLIB}")
# Append to aggregated values variable
set(CONAN_LIBS_ZLIB ${CONAN_PKG_LIBS_ZLIB} ${CONAN_SYSTEM_LIBS_ZLIB} ${CONAN_FRAMEWORKS_FOUND_ZLIB})
# Aggregate package libs and frameworks for conan_package_library_targets()
set(CONAN_LIBS_FRAMEWORKS_ZLIB ${CONAN_PKG_LIBS_ZLIB} ${CONAN_FRAMEWORKS_FOUND_ZLIB})


### Definition of global aggregated variables ###

set(CONAN_PACKAGE_NAME None)
set(CONAN_PACKAGE_VERSION None)

set(CONAN_SETTINGS_ARCH "x86_64")
set(CONAN_SETTINGS_ARCH_BUILD "x86_64")
set(CONAN_SETTINGS_BUILD_TYPE "Debug")
set(CONAN_SETTINGS_COMPILER "Visual Studio")
set(CONAN_SETTINGS_COMPILER_RUNTIME "MDd")
set(CONAN_SETTINGS_COMPILER_VERSION "16")
set(CONAN_SETTINGS_CPPSTD "17")
set(CONAN_SETTINGS_OS "Windows")
set(CONAN_SETTINGS_OS_BUILD "Windows")

set(CONAN_DEPENDENCIES entt eigen sdl2_image box2d sdl2 libtiff libjpeg libpng libwebp zlib)
# Storing original command line args (CMake helper) flags
set(CONAN_CMD_CXX_FLAGS ${CONAN_CXX_FLAGS})

set(CONAN_CMD_SHARED_LINKER_FLAGS ${CONAN_SHARED_LINKER_FLAGS})
set(CONAN_CMD_C_FLAGS ${CONAN_C_FLAGS})
# Defining accumulated conan variables for all deps

set(CONAN_INCLUDE_DIRS "C:/Users/calm/.conan/data/entt/3.2.2/skypjack/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include"
			"C:/Users/calm/.conan/data/eigen/3.3.7/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include/eigen3"
			"C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/include"
			"C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/include/SDL2"
			"C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714/include"
			"C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/include"
			"C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/include/SDL2"
			"C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/include"
			"C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/include"
			"C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/include"
			"C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e/include"
			"C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/include" ${CONAN_INCLUDE_DIRS})
set(CONAN_LIB_DIRS "C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/lib"
			"C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714/lib"
			"C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/lib"
			"C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/lib"
			"C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/lib"
			"C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/lib"
			"C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e/lib"
			"C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/lib" ${CONAN_LIB_DIRS})
set(CONAN_BIN_DIRS  ${CONAN_BIN_DIRS})
set(CONAN_RES_DIRS  ${CONAN_RES_DIRS})
set(CONAN_FRAMEWORK_DIRS  ${CONAN_FRAMEWORK_DIRS})
set(CONAN_LIBS SDL2_image Box2D SDL2 SDL2main tiffd tiffxxd libjpeg libpng16d webpmux webpdemux webpdecoder webp zlib ${CONAN_LIBS})
set(CONAN_PKG_LIBS SDL2_image Box2D SDL2 SDL2main tiffd tiffxxd libjpeg libpng16d webpmux webpdemux webpdecoder webp zlib ${CONAN_PKG_LIBS})
set(CONAN_SYSTEM_LIBS user32 gdi32 winmm imm32 ole32 oleaut32 version uuid advapi32 setupapi shell32)
set(CONAN_FRAMEWORKS  ${CONAN_FRAMEWORKS})
set(CONAN_FRAMEWORKS_FOUND "")  # Will be filled later
set(CONAN_DEFINES  ${CONAN_DEFINES})
set(CONAN_BUILD_MODULES_PATHS  ${CONAN_BUILD_MODULES_PATHS})
set(CONAN_CMAKE_MODULE_PATH "C:/Users/calm/.conan/data/entt/3.2.2/skypjack/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"C:/Users/calm/.conan/data/eigen/3.3.7/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"C:/Users/calm/.conan/data/sdl2_image/2.0.5/bincrafters/stable/package/12d51f9b6f981f5aa991686f53d433e4b1d62fbd/"
			"C:/Users/calm/.conan/data/box2d/2.3.1/conan/stable/package/d057732059ea44a47760900cb5e4855d2bea8714/"
			"C:/Users/calm/.conan/data/sdl2/2.0.10/bincrafters/stable/package/0e00c502f993a3f1f4917cbf8f2405ea02594264/"
			"C:/Users/calm/.conan/data/libtiff/4.0.9/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/"
			"C:/Users/calm/.conan/data/libjpeg/9c/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/"
			"C:/Users/calm/.conan/data/libpng/1.6.37/_/_/package/6acf24cd4adf2df742e006cc0e5f0329e3b6e60b/"
			"C:/Users/calm/.conan/data/libwebp/1.0.3/_/_/package/092f77d3b4b4678d81fbffc1fccc9642b870175e/"
			"C:/Users/calm/.conan/data/zlib/1.2.11/_/_/package/d057732059ea44a47760900cb5e4855d2bea8714/" ${CONAN_CMAKE_MODULE_PATH})

set(CONAN_CXX_FLAGS " ${CONAN_CXX_FLAGS}")
set(CONAN_SHARED_LINKER_FLAGS " ${CONAN_SHARED_LINKER_FLAGS}")
set(CONAN_EXE_LINKER_FLAGS " ${CONAN_EXE_LINKER_FLAGS}")
set(CONAN_C_FLAGS " ${CONAN_C_FLAGS}")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND "${CONAN_FRAMEWORKS}")
# Append to aggregated values variable
set(CONAN_LIBS ${CONAN_PKG_LIBS} ${CONAN_SYSTEM_LIBS} ${CONAN_FRAMEWORKS_FOUND})


###  Definition of macros and functions ###

macro(conan_define_targets)
    if(${CMAKE_VERSION} VERSION_LESS "3.1.2")
        message(FATAL_ERROR "TARGETS not supported by your CMake version!")
    endif()  # CMAKE > 3.x
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CONAN_CMD_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CONAN_CMD_C_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${CONAN_CMD_SHARED_LINKER_FLAGS}")


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ENTT}" "${CONAN_LIB_DIRS_ENTT}"
                                  CONAN_PACKAGE_TARGETS_ENTT "${CONAN_SYSTEM_LIBS_ENTT} "
                                  "" entt)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ENTT_DEBUG}" "${CONAN_LIB_DIRS_ENTT_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_ENTT_DEBUG "${CONAN_SYSTEM_LIBS_ENTT_DEBUG} "
                                  "debug" entt)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ENTT_RELEASE}" "${CONAN_LIB_DIRS_ENTT_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_ENTT_RELEASE "${CONAN_SYSTEM_LIBS_ENTT_RELEASE} "
                                  "release" entt)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ENTT_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_ENTT_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_ENTT_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_ENTT_RELWITHDEBINFO} "
                                  "relwithdebinfo" entt)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ENTT_MINSIZEREL}" "${CONAN_LIB_DIRS_ENTT_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_ENTT_MINSIZEREL "${CONAN_SYSTEM_LIBS_ENTT_MINSIZEREL} "
                                  "minsizerel" entt)

    add_library(CONAN_PKG::entt INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::entt PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_ENTT} ${CONAN_SHARED_LINKER_FLAGS_ENTT_LIST} ${CONAN_EXE_LINKER_FLAGS_ENTT_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_ENTT_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_ENTT_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_ENTT_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_ENTT_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_ENTT_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_ENTT_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_ENTT_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_ENTT_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_ENTT_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_ENTT_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_ENTT_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_ENTT_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::entt PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_ENTT}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_ENTT_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_ENTT_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_ENTT_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_ENTT_DEBUG}>)
    set_property(TARGET CONAN_PKG::entt PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_ENTT}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_ENTT_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_ENTT_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_ENTT_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_ENTT_DEBUG}>)
    set_property(TARGET CONAN_PKG::entt PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_ENTT_LIST} ${CONAN_CXX_FLAGS_ENTT_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_ENTT_RELEASE_LIST} ${CONAN_CXX_FLAGS_ENTT_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_ENTT_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_ENTT_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_ENTT_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_ENTT_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_ENTT_DEBUG_LIST}  ${CONAN_CXX_FLAGS_ENTT_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_EIGEN3}" "${CONAN_LIB_DIRS_EIGEN3}"
                                  CONAN_PACKAGE_TARGETS_EIGEN3 "${CONAN_SYSTEM_LIBS_EIGEN3} "
                                  "" Eigen3)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_EIGEN3_DEBUG}" "${CONAN_LIB_DIRS_EIGEN3_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_EIGEN3_DEBUG "${CONAN_SYSTEM_LIBS_EIGEN3_DEBUG} "
                                  "debug" Eigen3)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_EIGEN3_RELEASE}" "${CONAN_LIB_DIRS_EIGEN3_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_EIGEN3_RELEASE "${CONAN_SYSTEM_LIBS_EIGEN3_RELEASE} "
                                  "release" Eigen3)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_EIGEN3_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_EIGEN3_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_EIGEN3_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_EIGEN3_RELWITHDEBINFO} "
                                  "relwithdebinfo" Eigen3)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_EIGEN3_MINSIZEREL}" "${CONAN_LIB_DIRS_EIGEN3_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_EIGEN3_MINSIZEREL "${CONAN_SYSTEM_LIBS_EIGEN3_MINSIZEREL} "
                                  "minsizerel" Eigen3)

    add_library(CONAN_PKG::Eigen3 INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::Eigen3 PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_EIGEN3} ${CONAN_SHARED_LINKER_FLAGS_EIGEN3_LIST} ${CONAN_EXE_LINKER_FLAGS_EIGEN3_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_EIGEN3_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_EIGEN3_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_EIGEN3_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_EIGEN3_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_EIGEN3_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_EIGEN3_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_EIGEN3_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_EIGEN3_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_EIGEN3_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_EIGEN3_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_EIGEN3_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_EIGEN3_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::Eigen3 PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_EIGEN3}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_EIGEN3_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_EIGEN3_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_EIGEN3_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_EIGEN3_DEBUG}>)
    set_property(TARGET CONAN_PKG::Eigen3 PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_EIGEN3}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_EIGEN3_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_EIGEN3_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_EIGEN3_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_EIGEN3_DEBUG}>)
    set_property(TARGET CONAN_PKG::Eigen3 PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_EIGEN3_LIST} ${CONAN_CXX_FLAGS_EIGEN3_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_EIGEN3_RELEASE_LIST} ${CONAN_CXX_FLAGS_EIGEN3_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_EIGEN3_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_EIGEN3_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_EIGEN3_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_EIGEN3_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_EIGEN3_DEBUG_LIST}  ${CONAN_CXX_FLAGS_EIGEN3_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_IMAGE}" "${CONAN_LIB_DIRS_SDL2_IMAGE}"
                                  CONAN_PACKAGE_TARGETS_SDL2_IMAGE "${CONAN_SYSTEM_LIBS_SDL2_IMAGE} CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib"
                                  "" sdl2_image)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_IMAGE_DEBUG}" "${CONAN_LIB_DIRS_SDL2_IMAGE_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_SDL2_IMAGE_DEBUG "${CONAN_SYSTEM_LIBS_SDL2_IMAGE_DEBUG} CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib"
                                  "debug" sdl2_image)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_IMAGE_RELEASE}" "${CONAN_LIB_DIRS_SDL2_IMAGE_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_SDL2_IMAGE_RELEASE "${CONAN_SYSTEM_LIBS_SDL2_IMAGE_RELEASE} CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib"
                                  "release" sdl2_image)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_IMAGE_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_SDL2_IMAGE_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_SDL2_IMAGE_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_SDL2_IMAGE_RELWITHDEBINFO} CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib"
                                  "relwithdebinfo" sdl2_image)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_IMAGE_MINSIZEREL}" "${CONAN_LIB_DIRS_SDL2_IMAGE_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_SDL2_IMAGE_MINSIZEREL "${CONAN_SYSTEM_LIBS_SDL2_IMAGE_MINSIZEREL} CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib"
                                  "minsizerel" sdl2_image)

    add_library(CONAN_PKG::sdl2_image INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::sdl2_image PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_SDL2_IMAGE} ${CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_SDL2_IMAGE_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_SDL2_IMAGE_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_SDL2_IMAGE_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_SDL2_IMAGE_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_SDL2_IMAGE_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_IMAGE_DEBUG_LIST}>
                                                                 CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib)
    set_property(TARGET CONAN_PKG::sdl2_image PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_SDL2_IMAGE}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_SDL2_IMAGE_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_SDL2_IMAGE_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_SDL2_IMAGE_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_SDL2_IMAGE_DEBUG}>)
    set_property(TARGET CONAN_PKG::sdl2_image PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_SDL2_IMAGE}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_SDL2_IMAGE_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_SDL2_IMAGE_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_SDL2_IMAGE_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_SDL2_IMAGE_DEBUG}>)
    set_property(TARGET CONAN_PKG::sdl2_image PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_SDL2_IMAGE_LIST} ${CONAN_CXX_FLAGS_SDL2_IMAGE_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_SDL2_IMAGE_RELEASE_LIST} ${CONAN_CXX_FLAGS_SDL2_IMAGE_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_SDL2_IMAGE_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_SDL2_IMAGE_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_SDL2_IMAGE_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_SDL2_IMAGE_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_SDL2_IMAGE_DEBUG_LIST}  ${CONAN_CXX_FLAGS_SDL2_IMAGE_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_BOX2D}" "${CONAN_LIB_DIRS_BOX2D}"
                                  CONAN_PACKAGE_TARGETS_BOX2D "${CONAN_SYSTEM_LIBS_BOX2D} "
                                  "" box2d)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_BOX2D_DEBUG}" "${CONAN_LIB_DIRS_BOX2D_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_BOX2D_DEBUG "${CONAN_SYSTEM_LIBS_BOX2D_DEBUG} "
                                  "debug" box2d)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_BOX2D_RELEASE}" "${CONAN_LIB_DIRS_BOX2D_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_BOX2D_RELEASE "${CONAN_SYSTEM_LIBS_BOX2D_RELEASE} "
                                  "release" box2d)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_BOX2D_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_BOX2D_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_BOX2D_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_BOX2D_RELWITHDEBINFO} "
                                  "relwithdebinfo" box2d)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_BOX2D_MINSIZEREL}" "${CONAN_LIB_DIRS_BOX2D_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_BOX2D_MINSIZEREL "${CONAN_SYSTEM_LIBS_BOX2D_MINSIZEREL} "
                                  "minsizerel" box2d)

    add_library(CONAN_PKG::box2d INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::box2d PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_BOX2D} ${CONAN_SHARED_LINKER_FLAGS_BOX2D_LIST} ${CONAN_EXE_LINKER_FLAGS_BOX2D_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_BOX2D_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_BOX2D_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_BOX2D_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_BOX2D_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_BOX2D_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_BOX2D_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_BOX2D_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_BOX2D_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_BOX2D_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_BOX2D_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_BOX2D_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_BOX2D_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::box2d PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_BOX2D}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_BOX2D_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_BOX2D_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_BOX2D_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_BOX2D_DEBUG}>)
    set_property(TARGET CONAN_PKG::box2d PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_BOX2D}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_BOX2D_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_BOX2D_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_BOX2D_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_BOX2D_DEBUG}>)
    set_property(TARGET CONAN_PKG::box2d PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_BOX2D_LIST} ${CONAN_CXX_FLAGS_BOX2D_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_BOX2D_RELEASE_LIST} ${CONAN_CXX_FLAGS_BOX2D_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_BOX2D_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_BOX2D_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_BOX2D_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_BOX2D_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_BOX2D_DEBUG_LIST}  ${CONAN_CXX_FLAGS_BOX2D_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2}" "${CONAN_LIB_DIRS_SDL2}"
                                  CONAN_PACKAGE_TARGETS_SDL2 "${CONAN_SYSTEM_LIBS_SDL2} "
                                  "" sdl2)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_DEBUG}" "${CONAN_LIB_DIRS_SDL2_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_SDL2_DEBUG "${CONAN_SYSTEM_LIBS_SDL2_DEBUG} "
                                  "debug" sdl2)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_RELEASE}" "${CONAN_LIB_DIRS_SDL2_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_SDL2_RELEASE "${CONAN_SYSTEM_LIBS_SDL2_RELEASE} "
                                  "release" sdl2)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_SDL2_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_SDL2_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_SDL2_RELWITHDEBINFO} "
                                  "relwithdebinfo" sdl2)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_SDL2_MINSIZEREL}" "${CONAN_LIB_DIRS_SDL2_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_SDL2_MINSIZEREL "${CONAN_SYSTEM_LIBS_SDL2_MINSIZEREL} "
                                  "minsizerel" sdl2)

    add_library(CONAN_PKG::sdl2 INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::sdl2 PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_SDL2} ${CONAN_SHARED_LINKER_FLAGS_SDL2_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_SDL2_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_SDL2_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_SDL2_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_SDL2_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_SDL2_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_SDL2_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_SDL2_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_SDL2_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_SDL2_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::sdl2 PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_SDL2}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_SDL2_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_SDL2_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_SDL2_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_SDL2_DEBUG}>)
    set_property(TARGET CONAN_PKG::sdl2 PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_SDL2}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_SDL2_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_SDL2_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_SDL2_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_SDL2_DEBUG}>)
    set_property(TARGET CONAN_PKG::sdl2 PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_SDL2_LIST} ${CONAN_CXX_FLAGS_SDL2_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_SDL2_RELEASE_LIST} ${CONAN_CXX_FLAGS_SDL2_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_SDL2_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_SDL2_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_SDL2_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_SDL2_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_SDL2_DEBUG_LIST}  ${CONAN_CXX_FLAGS_SDL2_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBTIFF}" "${CONAN_LIB_DIRS_LIBTIFF}"
                                  CONAN_PACKAGE_TARGETS_LIBTIFF "${CONAN_SYSTEM_LIBS_LIBTIFF} CONAN_PKG::zlib"
                                  "" libtiff)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBTIFF_DEBUG}" "${CONAN_LIB_DIRS_LIBTIFF_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_LIBTIFF_DEBUG "${CONAN_SYSTEM_LIBS_LIBTIFF_DEBUG} CONAN_PKG::zlib"
                                  "debug" libtiff)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBTIFF_RELEASE}" "${CONAN_LIB_DIRS_LIBTIFF_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_LIBTIFF_RELEASE "${CONAN_SYSTEM_LIBS_LIBTIFF_RELEASE} CONAN_PKG::zlib"
                                  "release" libtiff)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBTIFF_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_LIBTIFF_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_LIBTIFF_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_LIBTIFF_RELWITHDEBINFO} CONAN_PKG::zlib"
                                  "relwithdebinfo" libtiff)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBTIFF_MINSIZEREL}" "${CONAN_LIB_DIRS_LIBTIFF_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_LIBTIFF_MINSIZEREL "${CONAN_SYSTEM_LIBS_LIBTIFF_MINSIZEREL} CONAN_PKG::zlib"
                                  "minsizerel" libtiff)

    add_library(CONAN_PKG::libtiff INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::libtiff PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_LIBTIFF} ${CONAN_SHARED_LINKER_FLAGS_LIBTIFF_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBTIFF_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_LIBTIFF_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_LIBTIFF_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBTIFF_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_LIBTIFF_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_LIBTIFF_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBTIFF_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_LIBTIFF_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_LIBTIFF_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBTIFF_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_LIBTIFF_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_LIBTIFF_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBTIFF_DEBUG_LIST}>
                                                                 CONAN_PKG::zlib)
    set_property(TARGET CONAN_PKG::libtiff PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_LIBTIFF}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_LIBTIFF_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_LIBTIFF_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_LIBTIFF_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_LIBTIFF_DEBUG}>)
    set_property(TARGET CONAN_PKG::libtiff PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_LIBTIFF}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_LIBTIFF_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_LIBTIFF_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_LIBTIFF_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_LIBTIFF_DEBUG}>)
    set_property(TARGET CONAN_PKG::libtiff PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_LIBTIFF_LIST} ${CONAN_CXX_FLAGS_LIBTIFF_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_LIBTIFF_RELEASE_LIST} ${CONAN_CXX_FLAGS_LIBTIFF_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_LIBTIFF_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_LIBTIFF_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_LIBTIFF_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_LIBTIFF_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_LIBTIFF_DEBUG_LIST}  ${CONAN_CXX_FLAGS_LIBTIFF_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBJPEG}" "${CONAN_LIB_DIRS_LIBJPEG}"
                                  CONAN_PACKAGE_TARGETS_LIBJPEG "${CONAN_SYSTEM_LIBS_LIBJPEG} "
                                  "" libjpeg)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBJPEG_DEBUG}" "${CONAN_LIB_DIRS_LIBJPEG_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_LIBJPEG_DEBUG "${CONAN_SYSTEM_LIBS_LIBJPEG_DEBUG} "
                                  "debug" libjpeg)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBJPEG_RELEASE}" "${CONAN_LIB_DIRS_LIBJPEG_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_LIBJPEG_RELEASE "${CONAN_SYSTEM_LIBS_LIBJPEG_RELEASE} "
                                  "release" libjpeg)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBJPEG_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_LIBJPEG_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_LIBJPEG_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_LIBJPEG_RELWITHDEBINFO} "
                                  "relwithdebinfo" libjpeg)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBJPEG_MINSIZEREL}" "${CONAN_LIB_DIRS_LIBJPEG_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_LIBJPEG_MINSIZEREL "${CONAN_SYSTEM_LIBS_LIBJPEG_MINSIZEREL} "
                                  "minsizerel" libjpeg)

    add_library(CONAN_PKG::libjpeg INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::libjpeg PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_LIBJPEG} ${CONAN_SHARED_LINKER_FLAGS_LIBJPEG_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBJPEG_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_LIBJPEG_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_LIBJPEG_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBJPEG_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_LIBJPEG_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_LIBJPEG_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBJPEG_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_LIBJPEG_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_LIBJPEG_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBJPEG_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_LIBJPEG_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_LIBJPEG_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBJPEG_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::libjpeg PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_LIBJPEG}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_LIBJPEG_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_LIBJPEG_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_LIBJPEG_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_LIBJPEG_DEBUG}>)
    set_property(TARGET CONAN_PKG::libjpeg PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_LIBJPEG}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_LIBJPEG_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_LIBJPEG_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_LIBJPEG_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_LIBJPEG_DEBUG}>)
    set_property(TARGET CONAN_PKG::libjpeg PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_LIBJPEG_LIST} ${CONAN_CXX_FLAGS_LIBJPEG_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_LIBJPEG_RELEASE_LIST} ${CONAN_CXX_FLAGS_LIBJPEG_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_LIBJPEG_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_LIBJPEG_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_LIBJPEG_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_LIBJPEG_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_LIBJPEG_DEBUG_LIST}  ${CONAN_CXX_FLAGS_LIBJPEG_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBPNG}" "${CONAN_LIB_DIRS_LIBPNG}"
                                  CONAN_PACKAGE_TARGETS_LIBPNG "${CONAN_SYSTEM_LIBS_LIBPNG} CONAN_PKG::zlib"
                                  "" libpng)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBPNG_DEBUG}" "${CONAN_LIB_DIRS_LIBPNG_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_LIBPNG_DEBUG "${CONAN_SYSTEM_LIBS_LIBPNG_DEBUG} CONAN_PKG::zlib"
                                  "debug" libpng)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBPNG_RELEASE}" "${CONAN_LIB_DIRS_LIBPNG_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_LIBPNG_RELEASE "${CONAN_SYSTEM_LIBS_LIBPNG_RELEASE} CONAN_PKG::zlib"
                                  "release" libpng)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBPNG_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_LIBPNG_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_LIBPNG_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_LIBPNG_RELWITHDEBINFO} CONAN_PKG::zlib"
                                  "relwithdebinfo" libpng)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBPNG_MINSIZEREL}" "${CONAN_LIB_DIRS_LIBPNG_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_LIBPNG_MINSIZEREL "${CONAN_SYSTEM_LIBS_LIBPNG_MINSIZEREL} CONAN_PKG::zlib"
                                  "minsizerel" libpng)

    add_library(CONAN_PKG::libpng INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::libpng PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_LIBPNG} ${CONAN_SHARED_LINKER_FLAGS_LIBPNG_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBPNG_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_LIBPNG_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_LIBPNG_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBPNG_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_LIBPNG_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_LIBPNG_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBPNG_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_LIBPNG_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_LIBPNG_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBPNG_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_LIBPNG_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_LIBPNG_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBPNG_DEBUG_LIST}>
                                                                 CONAN_PKG::zlib)
    set_property(TARGET CONAN_PKG::libpng PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_LIBPNG}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_LIBPNG_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_LIBPNG_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_LIBPNG_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_LIBPNG_DEBUG}>)
    set_property(TARGET CONAN_PKG::libpng PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_LIBPNG}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_LIBPNG_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_LIBPNG_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_LIBPNG_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_LIBPNG_DEBUG}>)
    set_property(TARGET CONAN_PKG::libpng PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_LIBPNG_LIST} ${CONAN_CXX_FLAGS_LIBPNG_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_LIBPNG_RELEASE_LIST} ${CONAN_CXX_FLAGS_LIBPNG_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_LIBPNG_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_LIBPNG_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_LIBPNG_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_LIBPNG_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_LIBPNG_DEBUG_LIST}  ${CONAN_CXX_FLAGS_LIBPNG_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBWEBP}" "${CONAN_LIB_DIRS_LIBWEBP}"
                                  CONAN_PACKAGE_TARGETS_LIBWEBP "${CONAN_SYSTEM_LIBS_LIBWEBP} "
                                  "" libwebp)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBWEBP_DEBUG}" "${CONAN_LIB_DIRS_LIBWEBP_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_LIBWEBP_DEBUG "${CONAN_SYSTEM_LIBS_LIBWEBP_DEBUG} "
                                  "debug" libwebp)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBWEBP_RELEASE}" "${CONAN_LIB_DIRS_LIBWEBP_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_LIBWEBP_RELEASE "${CONAN_SYSTEM_LIBS_LIBWEBP_RELEASE} "
                                  "release" libwebp)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBWEBP_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_LIBWEBP_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_LIBWEBP_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_LIBWEBP_RELWITHDEBINFO} "
                                  "relwithdebinfo" libwebp)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_LIBWEBP_MINSIZEREL}" "${CONAN_LIB_DIRS_LIBWEBP_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_LIBWEBP_MINSIZEREL "${CONAN_SYSTEM_LIBS_LIBWEBP_MINSIZEREL} "
                                  "minsizerel" libwebp)

    add_library(CONAN_PKG::libwebp INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::libwebp PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_LIBWEBP} ${CONAN_SHARED_LINKER_FLAGS_LIBWEBP_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBWEBP_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_LIBWEBP_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_LIBWEBP_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBWEBP_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_LIBWEBP_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_LIBWEBP_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBWEBP_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_LIBWEBP_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_LIBWEBP_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBWEBP_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_LIBWEBP_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_LIBWEBP_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_LIBWEBP_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::libwebp PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_LIBWEBP}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_LIBWEBP_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_LIBWEBP_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_LIBWEBP_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_LIBWEBP_DEBUG}>)
    set_property(TARGET CONAN_PKG::libwebp PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_LIBWEBP}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_LIBWEBP_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_LIBWEBP_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_LIBWEBP_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_LIBWEBP_DEBUG}>)
    set_property(TARGET CONAN_PKG::libwebp PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_LIBWEBP_LIST} ${CONAN_CXX_FLAGS_LIBWEBP_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_LIBWEBP_RELEASE_LIST} ${CONAN_CXX_FLAGS_LIBWEBP_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_LIBWEBP_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_LIBWEBP_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_LIBWEBP_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_LIBWEBP_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_LIBWEBP_DEBUG_LIST}  ${CONAN_CXX_FLAGS_LIBWEBP_DEBUG_LIST}>)


    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ZLIB}" "${CONAN_LIB_DIRS_ZLIB}"
                                  CONAN_PACKAGE_TARGETS_ZLIB "${CONAN_SYSTEM_LIBS_ZLIB} "
                                  "" zlib)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ZLIB_DEBUG}" "${CONAN_LIB_DIRS_ZLIB_DEBUG}"
                                  CONAN_PACKAGE_TARGETS_ZLIB_DEBUG "${CONAN_SYSTEM_LIBS_ZLIB_DEBUG} "
                                  "debug" zlib)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ZLIB_RELEASE}" "${CONAN_LIB_DIRS_ZLIB_RELEASE}"
                                  CONAN_PACKAGE_TARGETS_ZLIB_RELEASE "${CONAN_SYSTEM_LIBS_ZLIB_RELEASE} "
                                  "release" zlib)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ZLIB_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_ZLIB_RELWITHDEBINFO}"
                                  CONAN_PACKAGE_TARGETS_ZLIB_RELWITHDEBINFO "${CONAN_SYSTEM_LIBS_ZLIB_RELWITHDEBINFO} "
                                  "relwithdebinfo" zlib)
    conan_package_library_targets("${CONAN_LIBS_FRAMEWORKS_ZLIB_MINSIZEREL}" "${CONAN_LIB_DIRS_ZLIB_MINSIZEREL}"
                                  CONAN_PACKAGE_TARGETS_ZLIB_MINSIZEREL "${CONAN_SYSTEM_LIBS_ZLIB_MINSIZEREL} "
                                  "minsizerel" zlib)

    add_library(CONAN_PKG::zlib INTERFACE IMPORTED)

    # Property INTERFACE_LINK_FLAGS do not work, necessary to add to INTERFACE_LINK_LIBRARIES
    set_property(TARGET CONAN_PKG::zlib PROPERTY INTERFACE_LINK_LIBRARIES ${CONAN_PACKAGE_TARGETS_ZLIB} ${CONAN_SHARED_LINKER_FLAGS_ZLIB_LIST} ${CONAN_EXE_LINKER_FLAGS_ZLIB_LIST}
                                                                 $<$<CONFIG:Release>:${CONAN_PACKAGE_TARGETS_ZLIB_RELEASE} ${CONAN_SHARED_LINKER_FLAGS_ZLIB_RELEASE_LIST} ${CONAN_EXE_LINKER_FLAGS_ZLIB_RELEASE_LIST}>
                                                                 $<$<CONFIG:RelWithDebInfo>:${CONAN_PACKAGE_TARGETS_ZLIB_RELWITHDEBINFO} ${CONAN_SHARED_LINKER_FLAGS_ZLIB_RELWITHDEBINFO_LIST} ${CONAN_EXE_LINKER_FLAGS_ZLIB_RELWITHDEBINFO_LIST}>
                                                                 $<$<CONFIG:MinSizeRel>:${CONAN_PACKAGE_TARGETS_ZLIB_MINSIZEREL} ${CONAN_SHARED_LINKER_FLAGS_ZLIB_MINSIZEREL_LIST} ${CONAN_EXE_LINKER_FLAGS_ZLIB_MINSIZEREL_LIST}>
                                                                 $<$<CONFIG:Debug>:${CONAN_PACKAGE_TARGETS_ZLIB_DEBUG} ${CONAN_SHARED_LINKER_FLAGS_ZLIB_DEBUG_LIST} ${CONAN_EXE_LINKER_FLAGS_ZLIB_DEBUG_LIST}>
                                                                 )
    set_property(TARGET CONAN_PKG::zlib PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CONAN_INCLUDE_DIRS_ZLIB}
                                                                      $<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_ZLIB_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_ZLIB_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_ZLIB_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_ZLIB_DEBUG}>)
    set_property(TARGET CONAN_PKG::zlib PROPERTY INTERFACE_COMPILE_DEFINITIONS ${CONAN_COMPILE_DEFINITIONS_ZLIB}
                                                                      $<$<CONFIG:Release>:${CONAN_COMPILE_DEFINITIONS_ZLIB_RELEASE}>
                                                                      $<$<CONFIG:RelWithDebInfo>:${CONAN_COMPILE_DEFINITIONS_ZLIB_RELWITHDEBINFO}>
                                                                      $<$<CONFIG:MinSizeRel>:${CONAN_COMPILE_DEFINITIONS_ZLIB_MINSIZEREL}>
                                                                      $<$<CONFIG:Debug>:${CONAN_COMPILE_DEFINITIONS_ZLIB_DEBUG}>)
    set_property(TARGET CONAN_PKG::zlib PROPERTY INTERFACE_COMPILE_OPTIONS ${CONAN_C_FLAGS_ZLIB_LIST} ${CONAN_CXX_FLAGS_ZLIB_LIST}
                                                                  $<$<CONFIG:Release>:${CONAN_C_FLAGS_ZLIB_RELEASE_LIST} ${CONAN_CXX_FLAGS_ZLIB_RELEASE_LIST}>
                                                                  $<$<CONFIG:RelWithDebInfo>:${CONAN_C_FLAGS_ZLIB_RELWITHDEBINFO_LIST} ${CONAN_CXX_FLAGS_ZLIB_RELWITHDEBINFO_LIST}>
                                                                  $<$<CONFIG:MinSizeRel>:${CONAN_C_FLAGS_ZLIB_MINSIZEREL_LIST} ${CONAN_CXX_FLAGS_ZLIB_MINSIZEREL_LIST}>
                                                                  $<$<CONFIG:Debug>:${CONAN_C_FLAGS_ZLIB_DEBUG_LIST}  ${CONAN_CXX_FLAGS_ZLIB_DEBUG_LIST}>)

    set(CONAN_TARGETS CONAN_PKG::entt CONAN_PKG::Eigen3 CONAN_PKG::sdl2_image CONAN_PKG::box2d CONAN_PKG::sdl2 CONAN_PKG::libtiff CONAN_PKG::libjpeg CONAN_PKG::libpng CONAN_PKG::libwebp CONAN_PKG::zlib)

endmacro()


macro(conan_basic_setup)
    set(options TARGETS NO_OUTPUT_DIRS SKIP_RPATH KEEP_RPATHS SKIP_STD SKIP_FPIC)
    cmake_parse_arguments(ARGUMENTS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

    if(CONAN_EXPORTED)
        conan_message(STATUS "Conan: called by CMake conan helper")
    endif()

    if(CONAN_IN_LOCAL_CACHE)
        conan_message(STATUS "Conan: called inside local cache")
    endif()

    if(NOT ARGUMENTS_NO_OUTPUT_DIRS)
        conan_message(STATUS "Conan: Adjusting output directories")
        conan_output_dirs_setup()
    endif()

    if(NOT ARGUMENTS_TARGETS)
        conan_message(STATUS "Conan: Using cmake global configuration")
        conan_global_flags()
    else()
        conan_message(STATUS "Conan: Using cmake targets configuration")
        conan_define_targets()
    endif()

    if(ARGUMENTS_SKIP_RPATH)
        # Change by "DEPRECATION" or "SEND_ERROR" when we are ready
        conan_message(WARNING "Conan: SKIP_RPATH is deprecated, it has been renamed to KEEP_RPATHS")
    endif()

    if(NOT ARGUMENTS_SKIP_RPATH AND NOT ARGUMENTS_KEEP_RPATHS)
        # Parameter has renamed, but we keep the compatibility with old SKIP_RPATH
        conan_message(STATUS "Conan: Adjusting default RPATHs Conan policies")
        conan_set_rpath()
    endif()

    if(NOT ARGUMENTS_SKIP_STD)
        conan_message(STATUS "Conan: Adjusting language standard")
        conan_set_std()
    endif()

    if(NOT ARGUMENTS_SKIP_FPIC)
        conan_set_fpic()
    endif()

    conan_check_compiler()
    conan_set_libcxx()
    conan_set_vs_runtime()
    conan_set_find_paths()
    conan_include_build_modules()
    conan_set_find_library_paths()
endmacro()

macro(conan_set_find_paths)
    # CMAKE_MODULE_PATH does not have Debug/Release config, but there are variables
    # CONAN_CMAKE_MODULE_PATH_DEBUG to be used by the consumer
    # CMake can find findXXX.cmake files in the root of packages
    set(CMAKE_MODULE_PATH ${CONAN_CMAKE_MODULE_PATH} ${CMAKE_MODULE_PATH})

    # Make find_package() to work
    set(CMAKE_PREFIX_PATH ${CONAN_CMAKE_MODULE_PATH} ${CMAKE_PREFIX_PATH})

    # Set the find root path (cross build)
    set(CMAKE_FIND_ROOT_PATH ${CONAN_CMAKE_FIND_ROOT_PATH} ${CMAKE_FIND_ROOT_PATH})
    if(CONAN_CMAKE_FIND_ROOT_PATH_MODE_PROGRAM)
        set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ${CONAN_CMAKE_FIND_ROOT_PATH_MODE_PROGRAM})
    endif()
    if(CONAN_CMAKE_FIND_ROOT_PATH_MODE_LIBRARY)
        set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ${CONAN_CMAKE_FIND_ROOT_PATH_MODE_LIBRARY})
    endif()
    if(CONAN_CMAKE_FIND_ROOT_PATH_MODE_INCLUDE)
        set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ${CONAN_CMAKE_FIND_ROOT_PATH_MODE_INCLUDE})
    endif()
endmacro()

macro(conan_set_find_library_paths)
    # CMAKE_INCLUDE_PATH, CMAKE_LIBRARY_PATH does not have Debug/Release config, but there are variables
    # CONAN_INCLUDE_DIRS_DEBUG/RELEASE CONAN_LIB_DIRS_DEBUG/RELEASE to be used by the consumer
    # For find_library
    set(CMAKE_INCLUDE_PATH ${CONAN_INCLUDE_DIRS} ${CMAKE_INCLUDE_PATH})
    set(CMAKE_LIBRARY_PATH ${CONAN_LIB_DIRS} ${CMAKE_LIBRARY_PATH})
endmacro()

macro(conan_set_vs_runtime)
    if(CONAN_LINK_RUNTIME)
        foreach(flag CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE
                     CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO
                     CMAKE_C_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_MINSIZEREL)
            if(DEFINED ${flag})
                string(REPLACE "/MD" ${CONAN_LINK_RUNTIME} ${flag} "${${flag}}")
            endif()
        endforeach()
        foreach(flag CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG)
            if(DEFINED ${flag})
                string(REPLACE "/MDd" ${CONAN_LINK_RUNTIME} ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endmacro()

macro(conan_flags_setup)
    # Macro maintained for backwards compatibility
    conan_set_find_library_paths()
    conan_global_flags()
    conan_set_rpath()
    conan_set_vs_runtime()
    conan_set_libcxx()
endmacro()

function(conan_message MESSAGE_OUTPUT)
    if(NOT CONAN_CMAKE_SILENT_OUTPUT)
        message(${ARGV${0}})
    endif()
endfunction()

function(conan_find_libraries_abs_path libraries package_libdir libraries_abs_path)
    foreach(_LIBRARY_NAME ${libraries})
        unset(CONAN_FOUND_LIBRARY CACHE)
        find_library(CONAN_FOUND_LIBRARY NAME ${_LIBRARY_NAME} PATHS ${package_libdir}
                     NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if(CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            set(CONAN_FULLPATH_LIBS ${CONAN_FULLPATH_LIBS} ${CONAN_FOUND_LIBRARY})
        else()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            set(CONAN_FULLPATH_LIBS ${CONAN_FULLPATH_LIBS} ${_LIBRARY_NAME})
        endif()
    endforeach()
    unset(CONAN_FOUND_LIBRARY CACHE)
    set(${libraries_abs_path} ${CONAN_FULLPATH_LIBS} PARENT_SCOPE)
endfunction()

function(conan_package_library_targets libraries package_libdir libraries_abs_path deps build_type package_name)
    foreach(_LIBRARY_NAME ${libraries})
        unset(CONAN_FOUND_LIBRARY CACHE)
        find_library(CONAN_FOUND_LIBRARY NAME ${_LIBRARY_NAME} PATHS ${package_libdir}
                     NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if(CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            set(_LIB_NAME CONAN_LIB::${package_name}_${_LIBRARY_NAME}${build_type})
            add_library(${_LIB_NAME} UNKNOWN IMPORTED)
            set_target_properties(${_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CONAN_FOUND_LIBRARY})
            string(REPLACE " " ";" deps_list "${deps}")
            set_property(TARGET ${_LIB_NAME} PROPERTY INTERFACE_LINK_LIBRARIES ${deps_list})
            set(CONAN_FULLPATH_LIBS ${CONAN_FULLPATH_LIBS} ${_LIB_NAME})
        else()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            set(CONAN_FULLPATH_LIBS ${CONAN_FULLPATH_LIBS} ${_LIBRARY_NAME})
        endif()
    endforeach()
    unset(CONAN_FOUND_LIBRARY CACHE)
    set(${libraries_abs_path} ${CONAN_FULLPATH_LIBS} PARENT_SCOPE)
endfunction()

macro(conan_set_libcxx)
    if(DEFINED CONAN_LIBCXX)
        conan_message(STATUS "Conan: C++ stdlib: ${CONAN_LIBCXX}")
        if(CONAN_COMPILER STREQUAL "clang" OR CONAN_COMPILER STREQUAL "apple-clang")
            if(CONAN_LIBCXX STREQUAL "libstdc++" OR CONAN_LIBCXX STREQUAL "libstdc++11" )
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")
            elseif(CONAN_LIBCXX STREQUAL "libc++")
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
            endif()
        endif()
        if(CONAN_COMPILER STREQUAL "sun-cc")
            if(CONAN_LIBCXX STREQUAL "libCstd")
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -library=Cstd")
            elseif(CONAN_LIBCXX STREQUAL "libstdcxx")
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -library=stdcxx4")
            elseif(CONAN_LIBCXX STREQUAL "libstlport")
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -library=stlport4")
            elseif(CONAN_LIBCXX STREQUAL "libstdc++")
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -library=stdcpp")
            endif()
        endif()
        if(CONAN_LIBCXX STREQUAL "libstdc++11")
            add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
        elseif(CONAN_LIBCXX STREQUAL "libstdc++")
            add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
        endif()
    endif()
endmacro()

macro(conan_set_std)
    # Do not warn "Manually-specified variables were not used by the project"
    set(ignorevar "${CONAN_STD_CXX_FLAG}${CONAN_CMAKE_CXX_STANDARD}${CONAN_CMAKE_CXX_EXTENSIONS}")
    if (CMAKE_VERSION VERSION_LESS "3.1" OR
        (CMAKE_VERSION VERSION_LESS "3.12" AND ("${CONAN_CMAKE_CXX_STANDARD}" STREQUAL "20" OR "${CONAN_CMAKE_CXX_STANDARD}" STREQUAL "gnu20")))
    if(CONAN_STD_CXX_FLAG)
        conan_message(STATUS "Conan setting CXX_FLAGS flags: ${CONAN_STD_CXX_FLAG}")
        set(CMAKE_CXX_FLAGS "${CONAN_STD_CXX_FLAG} ${CMAKE_CXX_FLAGS}")
    endif()
    else()
        if(CONAN_CMAKE_CXX_STANDARD)
            conan_message(STATUS "Conan setting CPP STANDARD: ${CONAN_CMAKE_CXX_STANDARD} WITH EXTENSIONS ${CONAN_CMAKE_CXX_EXTENSIONS}")
            set(CMAKE_CXX_STANDARD ${CONAN_CMAKE_CXX_STANDARD})
            set(CMAKE_CXX_EXTENSIONS ${CONAN_CMAKE_CXX_EXTENSIONS})
        endif()
    endif()
endmacro()

macro(conan_set_rpath)
    if(APPLE)
        # https://cmake.org/Wiki/CMake_RPATH_handling
        # CONAN GUIDE: All generated libraries should have the id and dependencies to other
        # dylibs without path, just the name, EX:
        # libMyLib1.dylib:
        #     libMyLib1.dylib (compatibility version 0.0.0, current version 0.0.0)
        #     libMyLib0.dylib (compatibility version 0.0.0, current version 0.0.0)
        #     /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.0.0)
        #     /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1197.1.1)
        set(CMAKE_SKIP_RPATH 1)  # AVOID RPATH FOR *.dylib, ALL LIBS BETWEEN THEM AND THE EXE
                                 # SHOULD BE ON THE LINKER RESOLVER PATH (./ IS ONE OF THEM)
        # Policy CMP0068
        # We want the old behavior, in CMake >= 3.9 CMAKE_SKIP_RPATH won't affect the install_name in OSX
        set(CMAKE_INSTALL_NAME_DIR "")
    endif()
endmacro()

macro(conan_set_fpic)
    if(DEFINED CONAN_CMAKE_POSITION_INDEPENDENT_CODE)
        conan_message(STATUS "Conan: Adjusting fPIC flag (${CONAN_CMAKE_POSITION_INDEPENDENT_CODE})")
        set(CMAKE_POSITION_INDEPENDENT_CODE ${CONAN_CMAKE_POSITION_INDEPENDENT_CODE})
    endif()
endmacro()

macro(conan_output_dirs_setup)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
endmacro()

macro(conan_split_version VERSION_STRING MAJOR MINOR)
    #make a list from the version string
    string(REPLACE "." ";" VERSION_LIST "${VERSION_STRING}")

    #write output values
    list(LENGTH VERSION_LIST _version_len)
    list(GET VERSION_LIST 0 ${MAJOR})
    if(${_version_len} GREATER 1)
        list(GET VERSION_LIST 1 ${MINOR})
    endif()
endmacro()

macro(conan_error_compiler_version)
    message(FATAL_ERROR "Detected a mismatch for the compiler version between your conan profile settings and CMake: 
"
                        "Compiler version specified in your conan profile: ${CONAN_COMPILER_VERSION}
"
                        "Compiler version detected in CMake: ${VERSION_MAJOR}.${VERSION_MINOR}
"
                        "Please check your conan profile settings (conan profile show [default|your_profile_name])"
           )
endmacro()

set(_CONAN_CURRENT_DIR ${CMAKE_CURRENT_LIST_DIR})
function(conan_get_compiler CONAN_INFO_COMPILER CONAN_INFO_COMPILER_VERSION)
    conan_message(STATUS "Current conanbuildinfo.cmake directory: " ${_CONAN_CURRENT_DIR})
    if(NOT EXISTS ${_CONAN_CURRENT_DIR}/conaninfo.txt)
        conan_message(STATUS "WARN: conaninfo.txt not found")
        return()
    endif()

    file (READ "${_CONAN_CURRENT_DIR}/conaninfo.txt" CONANINFO)

    string(REGEX MATCH "compiler=([-A-Za-z0-9_ ]+)" _MATCHED ${CONANINFO})
    if(DEFINED CMAKE_MATCH_1)
        string(STRIP "${CMAKE_MATCH_1}" _CONAN_INFO_COMPILER)
        set(${CONAN_INFO_COMPILER} ${_CONAN_INFO_COMPILER} PARENT_SCOPE)
    endif()

    string(REGEX MATCH "compiler.version=([-A-Za-z0-9_.]+)" _MATCHED ${CONANINFO})
    if(DEFINED CMAKE_MATCH_1)
        string(STRIP "${CMAKE_MATCH_1}" _CONAN_INFO_COMPILER_VERSION)
        set(${CONAN_INFO_COMPILER_VERSION} ${_CONAN_INFO_COMPILER_VERSION} PARENT_SCOPE)
    endif()
endfunction()

function(check_compiler_version)
    conan_split_version(${CMAKE_CXX_COMPILER_VERSION} VERSION_MAJOR VERSION_MINOR)
    if(DEFINED CONAN_SETTINGS_COMPILER_TOOLSET)
       conan_message(STATUS "Conan: Skipping compiler check: Declared 'compiler.toolset'")
       return()
    endif()
    if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
        # MSVC_VERSION is defined since 2.8.2 at least
        # https://cmake.org/cmake/help/v2.8.2/cmake.html#variable:MSVC_VERSION
        # https://cmake.org/cmake/help/v3.14/variable/MSVC_VERSION.html
        if(
            # 1920-1929 = VS 16.0 (v142 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "16" AND NOT((MSVC_VERSION GREATER 1919) AND (MSVC_VERSION LESS 1930))) OR
            # 1910-1919 = VS 15.0 (v141 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "15" AND NOT((MSVC_VERSION GREATER 1909) AND (MSVC_VERSION LESS 1920))) OR
            # 1900      = VS 14.0 (v140 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "14" AND NOT(MSVC_VERSION EQUAL 1900)) OR
            # 1800      = VS 12.0 (v120 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "12" AND NOT VERSION_MAJOR STREQUAL "18") OR
            # 1700      = VS 11.0 (v110 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "11" AND NOT VERSION_MAJOR STREQUAL "17") OR
            # 1600      = VS 10.0 (v100 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "10" AND NOT VERSION_MAJOR STREQUAL "16") OR
            # 1500      = VS  9.0 (v90 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "9" AND NOT VERSION_MAJOR STREQUAL "15") OR
            # 1400      = VS  8.0 (v80 toolset)
            (CONAN_COMPILER_VERSION STREQUAL "8" AND NOT VERSION_MAJOR STREQUAL "14") OR
            # 1310      = VS  7.1, 1300      = VS  7.0
            (CONAN_COMPILER_VERSION STREQUAL "7" AND NOT VERSION_MAJOR STREQUAL "13") OR
            # 1200      = VS  6.0
            (CONAN_COMPILER_VERSION STREQUAL "6" AND NOT VERSION_MAJOR STREQUAL "12") )
            conan_error_compiler_version()
        endif()
    elseif(CONAN_COMPILER STREQUAL "gcc")
        set(_CHECK_VERSION ${VERSION_MAJOR}.${VERSION_MINOR})
        if(NOT ${CONAN_COMPILER_VERSION} VERSION_LESS 5.0)
            conan_message(STATUS "Conan: Compiler GCC>=5, checking major version ${CONAN_COMPILER_VERSION}")
            conan_split_version(${CONAN_COMPILER_VERSION} CONAN_COMPILER_MAJOR CONAN_COMPILER_MINOR)
            if("${CONAN_COMPILER_MINOR}" STREQUAL "")
                set(_CHECK_VERSION ${VERSION_MAJOR})
            endif()
        endif()
        conan_message(STATUS "Conan: Checking correct version: ${_CHECK_VERSION}")
        if(NOT ${_CHECK_VERSION} VERSION_EQUAL CONAN_COMPILER_VERSION)
            conan_error_compiler_version()
        endif()
    elseif(CONAN_COMPILER STREQUAL "clang")
        set(_CHECK_VERSION ${VERSION_MAJOR}.${VERSION_MINOR})
        if(NOT ${CONAN_COMPILER_VERSION} VERSION_LESS 8.0)
            conan_message(STATUS "Conan: Compiler Clang>=8, checking major version ${CONAN_COMPILER_VERSION}")
            conan_split_version(${CONAN_COMPILER_VERSION} CONAN_COMPILER_MAJOR CONAN_COMPILER_MINOR)
            if("${CONAN_COMPILER_MINOR}" STREQUAL "")
                set(_CHECK_VERSION ${VERSION_MAJOR})
            endif()
        endif()
        conan_message(STATUS "Conan: Checking correct version: ${_CHECK_VERSION}")
        if(NOT ${_CHECK_VERSION} VERSION_EQUAL CONAN_COMPILER_VERSION)
            conan_error_compiler_version()
        endif()
    elseif(CONAN_COMPILER STREQUAL "apple-clang" OR CONAN_COMPILER STREQUAL "sun-cc")
        conan_split_version(${CONAN_COMPILER_VERSION} CONAN_COMPILER_MAJOR CONAN_COMPILER_MINOR)
        if(NOT ${VERSION_MAJOR}.${VERSION_MINOR} VERSION_EQUAL ${CONAN_COMPILER_MAJOR}.${CONAN_COMPILER_MINOR})
           conan_error_compiler_version()
        endif()
    else()
        conan_message(STATUS "WARN: Unknown compiler '${CONAN_COMPILER}', skipping the version check...")
    endif()
endfunction()

function(conan_check_compiler)
    if(CONAN_DISABLE_CHECK_COMPILER)
        conan_message(STATUS "WARN: Disabled conan compiler checks")
        return()
    endif()
    if(NOT DEFINED CMAKE_CXX_COMPILER_ID)
        if(DEFINED CMAKE_C_COMPILER_ID)
            conan_message(STATUS "This project seems to be plain C, using '${CMAKE_C_COMPILER_ID}' compiler")
            set(CMAKE_CXX_COMPILER_ID ${CMAKE_C_COMPILER_ID})
            set(CMAKE_CXX_COMPILER_VERSION ${CMAKE_C_COMPILER_VERSION})
        else()
            message(FATAL_ERROR "This project seems to be plain C, but no compiler defined")
        endif()
    endif()
    if(NOT CMAKE_CXX_COMPILER_ID AND NOT CMAKE_C_COMPILER_ID)
        # This use case happens when compiler is not identified by CMake, but the compilers are there and work
        conan_message(STATUS "*** WARN: CMake was not able to identify a C or C++ compiler ***")
        conan_message(STATUS "*** WARN: Disabling compiler checks. Please make sure your settings match your environment ***")
        return()
    endif()
    if(NOT DEFINED CONAN_COMPILER)
        conan_get_compiler(CONAN_COMPILER CONAN_COMPILER_VERSION)
        if(NOT DEFINED CONAN_COMPILER)
            conan_message(STATUS "WARN: CONAN_COMPILER variable not set, please make sure yourself that "
                          "your compiler and version matches your declared settings")
            return()
        endif()
    endif()

    if(NOT CMAKE_HOST_SYSTEM_NAME STREQUAL ${CMAKE_SYSTEM_NAME})
        set(CROSS_BUILDING 1)
    endif()

    # If using VS, verify toolset
    if (CONAN_COMPILER STREQUAL "Visual Studio")
        if (CONAN_SETTINGS_COMPILER_TOOLSET MATCHES "LLVM" OR
            CONAN_SETTINGS_COMPILER_TOOLSET MATCHES "clang")
            set(EXPECTED_CMAKE_CXX_COMPILER_ID "Clang")
        elseif (CONAN_SETTINGS_COMPILER_TOOLSET MATCHES "Intel")
            set(EXPECTED_CMAKE_CXX_COMPILER_ID "Intel")
        else()
            set(EXPECTED_CMAKE_CXX_COMPILER_ID "MSVC")
        endif()

        if (NOT CMAKE_CXX_COMPILER_ID MATCHES ${EXPECTED_CMAKE_CXX_COMPILER_ID})
            message(FATAL_ERROR "Incorrect '${CONAN_COMPILER}'. Toolset specifies compiler as '${EXPECTED_CMAKE_CXX_COMPILER_ID}' "
                                "but CMake detected '${CMAKE_CXX_COMPILER_ID}'")
        endif()

    # Avoid checks when cross compiling, apple-clang crashes because its APPLE but not apple-clang
    # Actually CMake is detecting "clang" when you are using apple-clang, only if CMP0025 is set to NEW will detect apple-clang
    elseif((CONAN_COMPILER STREQUAL "gcc" AND NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR
        (CONAN_COMPILER STREQUAL "apple-clang" AND NOT CROSS_BUILDING AND (NOT APPLE OR NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")) OR
        (CONAN_COMPILER STREQUAL "clang" AND NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR
        (CONAN_COMPILER STREQUAL "sun-cc" AND NOT CMAKE_CXX_COMPILER_ID MATCHES "SunPro") )
        message(FATAL_ERROR "Incorrect '${CONAN_COMPILER}', is not the one detected by CMake: '${CMAKE_CXX_COMPILER_ID}'")
    endif()


    if(NOT DEFINED CONAN_COMPILER_VERSION)
        conan_message(STATUS "WARN: CONAN_COMPILER_VERSION variable not set, please make sure yourself "
                             "that your compiler version matches your declared settings")
        return()
    endif()
    check_compiler_version()
endfunction()

macro(conan_set_flags build_type)
    set(CMAKE_CXX_FLAGS${build_type} "${CMAKE_CXX_FLAGS${build_type}} ${CONAN_CXX_FLAGS${build_type}}")
    set(CMAKE_C_FLAGS${build_type} "${CMAKE_C_FLAGS${build_type}} ${CONAN_C_FLAGS${build_type}}")
    set(CMAKE_SHARED_LINKER_FLAGS${build_type} "${CMAKE_SHARED_LINKER_FLAGS${build_type}} ${CONAN_SHARED_LINKER_FLAGS${build_type}}")
    set(CMAKE_EXE_LINKER_FLAGS${build_type} "${CMAKE_EXE_LINKER_FLAGS${build_type}} ${CONAN_EXE_LINKER_FLAGS${build_type}}")
endmacro()

macro(conan_global_flags)
    if(CONAN_SYSTEM_INCLUDES)
        include_directories(SYSTEM ${CONAN_INCLUDE_DIRS}
                                   "$<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_RELEASE}>"
                                   "$<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_RELWITHDEBINFO}>"
                                   "$<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_MINSIZEREL}>"
                                   "$<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_DEBUG}>")
    else()
        include_directories(${CONAN_INCLUDE_DIRS}
                            "$<$<CONFIG:Release>:${CONAN_INCLUDE_DIRS_RELEASE}>"
                            "$<$<CONFIG:RelWithDebInfo>:${CONAN_INCLUDE_DIRS_RELWITHDEBINFO}>"
                            "$<$<CONFIG:MinSizeRel>:${CONAN_INCLUDE_DIRS_MINSIZEREL}>"
                            "$<$<CONFIG:Debug>:${CONAN_INCLUDE_DIRS_DEBUG}>")
    endif()

    link_directories(${CONAN_LIB_DIRS})

    conan_find_libraries_abs_path("${CONAN_LIBS_DEBUG}" "${CONAN_LIB_DIRS_DEBUG}"
                                  CONAN_LIBS_DEBUG)
    conan_find_libraries_abs_path("${CONAN_LIBS_RELEASE}" "${CONAN_LIB_DIRS_RELEASE}"
                                  CONAN_LIBS_RELEASE)
    conan_find_libraries_abs_path("${CONAN_LIBS_RELWITHDEBINFO}" "${CONAN_LIB_DIRS_RELWITHDEBINFO}"
                                  CONAN_LIBS_RELWITHDEBINFO)
    conan_find_libraries_abs_path("${CONAN_LIBS_MINSIZEREL}" "${CONAN_LIB_DIRS_MINSIZEREL}"
                                  CONAN_LIBS_MINSIZEREL)

    add_compile_options(${CONAN_DEFINES}
                        "$<$<CONFIG:Debug>:${CONAN_DEFINES_DEBUG}>"
                        "$<$<CONFIG:Release>:${CONAN_DEFINES_RELEASE}>"
                        "$<$<CONFIG:RelWithDebInfo>:${CONAN_DEFINES_RELWITHDEBINFO}>"
                        "$<$<CONFIG:MinSizeRel>:${CONAN_DEFINES_MINSIZEREL}>")

    conan_set_flags("")
    conan_set_flags("_RELEASE")
    conan_set_flags("_DEBUG")

endmacro()

macro(conan_target_link_libraries target)
    if(CONAN_TARGETS)
        target_link_libraries(${target} ${CONAN_TARGETS})
    else()
        target_link_libraries(${target} ${CONAN_LIBS})
        foreach(_LIB ${CONAN_LIBS_RELEASE})
            target_link_libraries(${target} optimized ${_LIB})
        endforeach()
        foreach(_LIB ${CONAN_LIBS_DEBUG})
            target_link_libraries(${target} debug ${_LIB})
        endforeach()
    endif()
endmacro()

macro(conan_include_build_modules)
    if(CMAKE_BUILD_TYPE)
        if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
            set(CONAN_BUILD_MODULES_PATHS ${CONAN_BUILD_MODULES_PATHS_DEBUG} ${CONAN_BUILD_MODULES_PATHS})
        elseif(${CMAKE_BUILD_TYPE} MATCHES "Release")
            set(CONAN_BUILD_MODULES_PATHS ${CONAN_BUILD_MODULES_PATHS_RELEASE} ${CONAN_BUILD_MODULES_PATHS})
        elseif(${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo")
            set(CONAN_BUILD_MODULES_PATHS ${CONAN_BUILD_MODULES_PATHS_RELWITHDEBINFO} ${CONAN_BUILD_MODULES_PATHS})
        elseif(${CMAKE_BUILD_TYPE} MATCHES "MinSizeRel")
            set(CONAN_BUILD_MODULES_PATHS ${CONAN_BUILD_MODULES_PATHS_MINSIZEREL} ${CONAN_BUILD_MODULES_PATHS})
        endif()
    endif()

    foreach(_BUILD_MODULE_PATH ${CONAN_BUILD_MODULES_PATHS})
        include(${_BUILD_MODULE_PATH})
    endforeach()
endmacro()


### Definition of user declared vars (user_info) ###

