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
  add_library(libantenna SHARED ${SOURCES})
  if (WIN32)
    add_definitions(-DLIBANTENNA_MSBUILD)
    include (GenerateExportHeader)
    GENERATE_EXPORT_HEADER(libantenna BASE_NAME libantenna STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
  endif (WIN32)
else()
  add_library(libantenna STATIC ${SOURCES})
endif(BUILD_SHARED_LIBS)

target_link_libraries(libantenna)
#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS libantenna)

