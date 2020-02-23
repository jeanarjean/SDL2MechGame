# IMPORTANT
to build debug build, use:  
	conan install -s build_type=Debug .


default way to get dependencies:
	conan install -s build_type=Debug . --build=box2d --build=sdl2_image
