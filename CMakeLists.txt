cmake_minimum_required(VERSION 3.22)
project(antenna "C")

# dependency
if(UNIX OR MSYS OR MINGW)
  set(CMAKE_PREFIX_PATH "/usr/local")
elseif(WIN32)
  set(CMAKE_PREFIX_PATH $ENV{LocalAppData})
endif()
message(VERBOSE "[${CMAKE_PROJECT_NAME}] CMake prefix path: ${CMAKE_PREFIX_PATH}")

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
message(VERBOSE "[${CMAKE_PROJECT_NAME}] Project version: ${PROJECT_VERSION}")

# option
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(ENABLE_TESTS "Build test binaries" ON)

#include 
if(UNIX OR MSYS OR MINGW)
  include_directories(".")
elseif(WIN32)
  include_directories("." $ENV{LocalAppData}/include)
endif()

# source
file(GLOB SOURCES "./*.c")
file(GLOB INCLUDES "./*.h")
message(VERBOSE "[${CMAKE_PROJECT_NAME}] List of source files: ${SOURCES}")
message(VERBOSE "[${CMAKE_PROJECT_NAME}] List of include files: ${INCLUDES}")

# library dependencies
if(UNIX OR MSYS OR MINGW)
  set(DEPLIBS m)
elseif(WIN32)
  set(DEPLIBS)
endif()

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
target_compile_definitions(${LIBNAME} PUBLIC PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(${LIBNAME} PUBLIC PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(${LIBNAME} PUBLIC PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH})

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

# test
if(ENABLE_TESTS)
  # testing binary
  add_executable(test1 test/test1.c)
  target_link_libraries(test1 PRIVATE "${LIBNAME}" ${DEPLIBS})

  # enable testing functionality
  enable_testing()

  # define tests
  add_test(NAME test1  COMMAND $<TARGET_FILE:test1>)
endif(ENABLE_TESTS)

# command line
add_executable(anten main.c)
target_link_libraries(anten PUBLIC "${LIBNAME}" ${DEPLIBS} argtable2)
