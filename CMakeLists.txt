cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(LiDarDriver VERSION 1.0 LANGUAGES CXX)


add_library(LidarDriver
	include/LidarDriver.h
	src/LidarDriver.cpp
)

add_library(CircularArray
	include/CircularArray.h
	src/CircularArray.cpp
)

add_executable(main
	src/main.cpp
)

target_link_libraries(main
	LidarDriver
	CircularArray	
)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
