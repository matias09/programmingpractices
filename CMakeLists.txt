cmake_minimum_required (VERSION 3.1)

set (PRJ_NAME   "pathfinding")
set (LIB_DIR    ${CMAKE_SOURCE_DIR}/lib)
set (CONFIG_DIR ${CMAKE_SOURCE_DIR}/config)
set (HEADER_DIR ${CMAKE_SOURCE_DIR}/header)
set (SRC_DIR    ${CMAKE_SOURCE_DIR}/src)

# project name
project (PRJ_NAME)


#-----------------------------------
# cmake Variables
#-----------------------------------
#set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})

#-----------------------------------
# own Variables
#-----------------------------------
# set flags variables
set (warnings_compile_flags "-Wall -pedantic -g")
set (cxx_standar_11 11)
set (cxx_standar_14 14)
set (cxx_standar_17 17)

# add flags to compiler
set (CMAKE_CXX_STANDARD  "${cxx_standar_11}")
set (CMAKE_CXX_FLAGS     "${warnings_compile_flags}")

set (SOURCES "main.cpp")


#-----------------------------------
# project files conf
#-----------------------------------
add_executable (PRJ_NAME ${SOURCES})
