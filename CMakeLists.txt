
#	CMakeLists.txt
#	created on :28/8/2023
#	author 	   :shrief mahmoud

cmake_minimum_required(VERSION 3.10)
project(shrief_project)
set(CMAKE_CXX_STANDARD 11)

#configure the boost library
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)


#find the boost packages 
find_package(Boost 1.58 COMPONENTS log log_setup system thread REQUIRED)

#set the path of the boost root in the rpi
#set(BOOST_ROOT "/home/shrief")

#set the path of the cross compiler
#set(CMAKE_CXX_COMPILER "/home/shrief/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-g++")


#include the boost directory
include_directories(${Boost_INCLUDE_DIR})

#link the boost library 
link_directories(${Boost_LIBRARY_DIRS})

#add the dir of the libraries
add_subdirectory(lib)

#link the msgque_lib dynamically to the project
add_library(msgque_lib SHARED
	    lib/MsgQue_lib.cpp
	    lib/MsgQue_lib.hpp)

#add the executable of the math_app and the daemon_logger     
add_executable(lib_math math/math_app.cpp)
add_executable(TCP socket/machine.cpp)
add_executable(daemon_logger logger/simpleLogger.cpp logger/config_lib.cpp socket/rpi.cpp)

#link the library to the math_app and the daemon_logger 
target_link_libraries(lib_math  msgque_lib ${Boost_LIBRARIES} pthread)
target_link_libraries(daemon_logger msgque_lib ${Boost_LIBRARIES} pthread)


