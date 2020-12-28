# Adding minimun require version
cmake_minimum_required (VERSION 3.1)

# Project Name
project(trie)

#-----------------------------------
# The version number.
#-----------------------------------
set (json_VERSION_MAJOR 1)
set (json_VERSION_MINOR 0)

#-----------------------------------
# Own Variables
#-----------------------------------
#set compilers path variables
set(clang_c_path /bin/clang)
set(clang_cxx_path /bin/clang++)

# set flags variables
set(compiler_flags "-Wall -pedantic -g")
#set(extra_flags "-D DEBUG")
set(cxx_standar_11 11)
set(cxx_standar_14 14)
set(cxx_standar_17 17)

#-----------------------------------
# Set Cmake conf
#-----------------------------------
# set a compiler for c and c++
#set(CMAKE_C_COMPILER "${clang_c_path}") C Compiler path
#set(CMAKE_CXX_COMPILER "${clang_cxx_path}")

# add flags to compiler
set(CMAKE_CXX_STANDARD  "${cxx_standar_11}")
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS  "${compiler_flags}")
#set( cmake_exe_linker_flags  "${cmake_exe_linker_flags} ${gcc_coverage_link_flags}" )


#-----------------------------------
# project files conf
#-----------------------------------
set (SRC "main.cpp")

# Add Executables
message("Creating Executable trie_project . . .")
add_executable(trie ${SRC})

