cmake_minimum_required(VERSION 3.23.22)
project(antenna "C")

# version
get_filename_component(VERSION_TAG_PATH "version.tag" ABSOLUTE)
if(EXISTS ${VERSION_TAG_PATH})
  file(READ version.tag VERSION_TAG OFFSET 1)
  string(REPLACE "." ";" VERSION_LIST ${VERSION_TAG})
  list(GET VERSION_LIST 0 PROJECT_VERSION_MAJOR)
  list(GET VERSION_LIST 1 PROJECT_VERSION_MINOR)
  list(GET VERSION_LIST 2 PROJECT_VERSION_PATCH)
else()
  set(PROJECT_VERSION_MAJOR 0)
  set(PROJECT_VERSION_MINOR 0)
  set(PROJECT_VERSION_PATCH 0)
endif()
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
message(STATUS "[VERB] Project version: ${PROJECT_VERSION}")

# option
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# dependency
set(CMAKE_PREFIX_PATH $ENV{LocalAppData})
message(STATUS "[VERB] CMake prefix path: ${CMAKE_PREFIX_PATH}")
find_package(consts CONFIG REQUIRED CONFIGS constsConfigVersion.cmake)

#include 
if(UNIX OR MSYS OR MINGW)
  include_directories(".")
elseif(WIN32)
  include_directories("." $ENV{LocalAppData}/include)
endif()

# source
file(GLOB SOURCES "src/*.c")
file(GLOB INCLUDES "*.h")

# library
if(UNIX OR MSYS OR MINGW)
  set(LIBNAME ${CMAKE_PROJECT_NAME})
elseif(WIN32)
  set(LIBNAME lib${CMAKE_PROJECT_NAME})
endif()

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
include(GNUInstallDirs)
if(UNIX OR MSYS OR MINGW)
  set(PACKAGE_INSTALL_CMAKEDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})
elseif(WIN32)
  set(PACKAGE_INSTALL_CMAKEDIR "cmake")
endif()

install(TARGETS ${LIBNAME} EXPORT ${CMAKE_PROJECT_NAME}Config)
install(FILES ${INCLUDES} DESTINATION "include")

install(EXPORT ${CMAKE_PROJECT_NAME}Config NAMESPACE ${CMAKE_PROJECT_NAME}:: DESTINATION ${PACKAGE_INSTALL_CMAKEDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake" VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(FILES "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake" DESTINATION ${PACKAGE_INSTALL_CMAKEDIR})
