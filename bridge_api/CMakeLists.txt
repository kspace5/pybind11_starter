cmake_minimum_required(VERSION 2.8.12)
project(example)

##################################################
# Set - Include Directories
#################################################
set( INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../includes )
include_directories( ${INCLUDE_DIR} )

##################################################
# Set - External Libraries
##################################################
# Assumes libraries are copied to current src dir for simplicity
set( LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory(../pybind11 build)
pybind11_add_module(example example.cpp)
# PUBLIC here is critical
target_link_libraries( example PRIVATE ${LIBS_PATH}/libabc.a)
