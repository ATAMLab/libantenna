cmake_minimum_required(VERSION 3.23.0)
project(antenna VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_BINARY "Build 'antenna' command line executable" ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Header
include_directories(.)

# Source
file(GLOB SOURCES "libantenna.c")

# Library
set(LIBNAME ${CMAKE_PROJECT_NAME})

# MSVC
if(MSVC)
  set(LIBNAME lib${CMAKE_PROJECT_NAME})
  if(BUILD_SHARED_LIBS)
    add_definitions(-DMSVC_DLL)
    add_definitions(-DMSVC_DLL_EXPORT)
    include (GenerateExportHeader)
    GENERATE_EXPORT_HEADER(${LIBNAME} BASE_NAME ${LIBNAME} STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
  endif(BUILD_SHARED_LIBS)
endif(MSVC)

# Buid library
if(BUILD_SHARED_LIBS)
  add_library(${LIBNAME} SHARED ${SOURCES}) 
else()
  add_library(${LIBNAME} STATIC ${SOURCES}) 
endif(BUILD_SHARED_LIBS)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
#if (WIN32)
#  install(TARGETS libantenna
#  LIBRARY DESTINATION "lib"
#  ARCHIVE DESTINATION "lib"
#  RUNTIME DESTINATION "bin"
#  INCLUDES DESTINATION "include"
#  )
#else()
#  install(TARGETS antenna
#  LIBRARY DESTINATION "lib"
#  ARCHIVE DESTINATION "lib"
#  RUNTIME DESTINATION "bin"
#  INCLUDES DESTINATION "include"
#  )
#endif (WIN32)


