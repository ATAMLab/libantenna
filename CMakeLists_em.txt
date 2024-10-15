cmake_minimum_required(VERSION 3.22.0)
project(libem "C")

# option
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(ENABLE_TESTS "Build test binaries" ON)

# library
file(GLOB SOURCES "em.c")
set(LIBNAME ${CMAKE_PROJECT_NAME})
if(BUILD_SHARED_LIBS)
  add_library(${LIBNAME} SHARED ${SOURCES}) 
 else()
  add_library(${LIBNAME} STATIC ${SOURCES}) 
endif(BUILD_SHARED_LIBS)

# test
if(ENABLE_TESTS)
  # testing binary
  add_executable(test test.c)
  target_link_libraries(test PRIVATE ${LIBNAME})

  # enable testing functionality
  enable_testing()

  # define tests
  add_test(NAME test  COMMAND $<TARGET_FILE:test>)
endif(ENABLE_TESTS)

# install
install(TARGETS ${LIBNAME})
