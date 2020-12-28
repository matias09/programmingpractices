cmake_minimum_required(VERSION 3.1)

# project name
project(tape_equilibrium)

#-----------------------------------
# The version number.
#-----------------------------------
set (json_VERSION_MAJOR 1)
set (json_VERSION_MINOR 0)

#-----------------------------------
# Own Variables
#-----------------------------------
#set compilers path variables
set(clang_c_path /usr/bin/clang)
set(clang_cxx_path /usr/bin/clang++)

# set flags variables
set(warnings_compile_flags "-Wall -pedantic")
set(debbuger_flags "-g")
set(cxx_standard_11 11)
set(cxx_standard_14 14)
set(cxx_standard_17 17)


#-----------------------------------
# Set Cmake conf
#-----------------------------------
# set a compiler for c and c++
#set(CMAKE_C_COMPILER "${clang_c_path}") C Compiler path
#set(CMAKE_CXX_COMPILER "${clang_cxx_path}")

# add flags to compiler
set(CMAKE_CXX_STANDARD  "${cxx_standard_11}")
set(CMAKE_CXX_FLAGS  "${warnings_compile_flags} ${debbuger_flags}")
#set( cmake_exe_linker_flags  "${cmake_exe_linker_flags} ${gcc_coverage_link_flags}" )

#-----------------------------------
# project files conf
#-----------------------------------
#include_directories(inc) # - Not needed at the moment
#add_subdirectory(src)    # - Not needed at the moment

file(GLOB all_cpp_files "*.cpp")
add_executable(tape_equilibrium ${all_cpp_files})
