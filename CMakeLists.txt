cmake_minimum_required(VERSION 3.24.0)
project(libantenna VERSION 0.1.0)

if(WIN32)
  set(LIBNAME ${CMAKE_PROJECT_NAME})
  add_definitions(-DMSVC_DLL)
else()
  set(LIBNAME antenna)
endif(WIN32)

  
#Bring the headers, such as Student.h into the project
include_directories(.)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "libantenna.c")


if(BUILD_SHARED_LIBS)
  if (WIN32)
    add_library( SHARED ${SOURCES})
    include (GenerateExportHeader)
    GENERATE_EXPORT_HEADER(${LIBNAME} BASE_NAME ${LIBNAME} STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
  endif (WIN32)
  add_library(${LIBNAME} SHARED ${SOURCES})
else()
  add_library(${LIBNAME} STATIC ${SOURCES})
endif(BUILD_SHARED_LIBS)

# target_link_libraries(${LIBNAME})


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

install(FILES "libantenna.h" DESTINATION "include")

