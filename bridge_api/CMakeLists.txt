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
set( LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib )

if (WIN32) # Windows x86 and x64
set( LIB_ABC ${LIBS_PATH}/abc.lib ) # Static
set( LIB_XYZ ${LIBS_PATH}/xyz.lib )  # Shared
else() # Linux
set( LIB_ABC ${LIBS_PATH}/abc.a )  # Static
set( LIB_XYZ ${LIBS_PATH}/xyz.so )  # Shared
endif (WIN32)

add_subdirectory(../pybind11 build)
pybind11_add_module(example example.cpp)

# Static lib example
# PUBLIC here is critical
target_link_libraries( example PUBLIC ${LIB_ABC})
# Shared lib example
target_link_libraries( example PRIVATE ${LIB_XYZ})