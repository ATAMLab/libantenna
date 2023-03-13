cmake_minimum_required(VERSION 3.22.0)
project(antenna VERSION 0.1.0)

# option
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(ENABLE_TESTS "Build test binaries" ON)

# commons
if(WIN32)
  file(TO_CMAKE_PATH "$ENV{LocalAppData}" EXTERNALS_DIR)
endif(WIN32)

if(UNIX)
  set(EXTERNALS_DIR "/usr/local") 
endif(UNIX)

# depenedency
find_file(LIBCONST phys_const_mks.h ${EXTERNALS_DIR}/include)
# find_library(LIBCONST libconst PATHS $ENV{LocalAppData})
if(NOT LIBCONST)
  message(FATAL_ERROR "libconst library not found")
endif()
message(STATUS "[VERB]libconst: ${LIBCONST}")

#include 
include_directories("." ${EXTERNALS_DIR}/include)

# source
file(GLOB SOURCES "src/*.c")
file(GLOB INCLUDES "*.h")

# library
if(MSVC)
  set(LIBNAME lib${CMAKE_PROJECT_NAME})
else()
  set(LIBNAME ${CMAKE_PROJECT_NAME})
endif(MSVC)

# build
if(BUILD_SHARED_LIBS)
  add_library(${LIBNAME} SHARED ${SOURCES}) 
  if(MSVC)
    if(BUILD_SHARED_LIBS)
      add_definitions(-DMSVC_DLL)
      add_definitions(-DMSVC_DLL_EXPORT)
      include (GenerateExportHeader)
      GENERATE_EXPORT_HEADER(${LIBNAME} BASE_NAME ${LIBNAME} STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
    endif(BUILD_SHARED_LIBS)
  endif(MSVC)
else()
  add_library(${LIBNAME} STATIC ${SOURCES}) 
endif(BUILD_SHARED_LIBS)

# install
install(TARGETS ${LIBNAME} CONFIGURATIONS Release)
install(FILES ${INCLUDES} DESTINATION "include")

# CTest
# if(ENABLE_TESTS)
#   # testing binary
#   add_executable(test1 test/test1.c)
#   target_link_libraries(test1 PRIVATE "${LIBNAME}")

#   # enable testing functionality
#   enable_testing()

#   # define tests
#   add_test(NAME test1  COMMAND $<TARGET_FILE:test1>)
# endif(ENABLE_TESTS)