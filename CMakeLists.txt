cmake_minimum_required(VERSION 3.16.3)
project(bashlab VERSION 0.1.0)

# if (WIN32)
#   add_definitions(-D_CRT_SECURE_NO_WARNINGS)
#   endif (WIN32)
  
#Bring the headers, such as Student.h into the project
include_directories(.)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

#Generate the shared library from the sources
if(BUILD_SHARED_LIBS)
  if (WIN32)
    add_library(libantenna SHARED ${SOURCES})
    add_definitions(-DLIBANTENNA_MSBUILD_SHARED)
    include (GenerateExportHeader)
    GENERATE_EXPORT_HEADER(libantenna BASE_NAME libantenna STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
  else()
    add_library(antenna SHARED ${SOURCES})
  endif (WIN32)
else()
  add_definitions(-DLIBANTENNA_MSBUILD_STATIC)
  if (WIN32)
    add_library(libantenna STATIC ${SOURCES})
  else()
    add_library(antenna STATIC ${SOURCES})
  endif (WIN32)
endif(BUILD_SHARED_LIBS)

if (WIN32)
  target_link_libraries(libantenna)
else()
  target_link_libraries(antenna)
endif (WIN32)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
if (WIN32)
  install(TARGETS libantenna
  LIBRARY DESTINATION "lib"
  ARCHIVE DESTINATION "lib"
  RUNTIME DESTINATION "bin"
  INCLUDES DESTINATION "include"
  )
else()
  install(TARGETS antenna
  LIBRARY DESTINATION "lib"
  ARCHIVE DESTINATION "lib"
  RUNTIME DESTINATION "bin"
  INCLUDES DESTINATION "include"
  )
endif (WIN32)

install(FILES "libantenna.h" DESTINATION "include")

