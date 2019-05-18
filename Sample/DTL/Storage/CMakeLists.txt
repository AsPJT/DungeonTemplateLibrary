# for cmake issue #16482 to support MSVC `/std:` flag
cmake_minimum_required(VERSION 3.10.0)

enable_language(CXX)

#
# Setup project path
#
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE NEVER)
find_path(DTL_ROOT_DIR
  NAMES include/DTL.hpp
  HINTS
    ../../../
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../
  NO_DEFAULT_PATH
)

set(DTL_DIR ${DTL_ROOT_DIR})
list(APPEND CMAKE_PREFIX_PATH ${DTL_ROOT_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../)
list(APPEND CMAKE_PREFIX_PATH ${DTL_ROOT_DIR}/cmake/modules)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules)
list(APPEND CMAKE_MODULE_PATH ${DTL_ROOT_DIR}/cmake/modules)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules)
find_package(DTL REQUIRED)

#
# C++ version
#
include(DecideCXXStanderd)
DECIDE_CXX_STANDERD()
message(STATUS "CMAKE_CXX_STANDARD:${CMAKE_CXX_STANDARD}")

set(CMAKE_CXX_STANDARD_REQUIRED ON)#...is required...

#...without compiler extensions like gnu++11
# TODO: Watch cmake issue #17068 carefully for MSVC `/permissive-`, `-Za` and `-Zc` flag
set(CMAKE_CXX_EXTENSIONS OFF)


#
# Update compiler waring flags
#
if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic")
endif()

#
# include dir
#
include_directories(${DTL_INCLUDE_DIR})

#
# standalone source files list
#
set(standalone_src
  FileBMP.cpp
  FileHDR.cpp
  FileJPG.cpp
  FileMD.cpp
  FilePNG.cpp
  FileTGA.cpp
)
add_custom_target(sample_DTL_Storage)
add_custom_target(run_sample_DTL_Storage)
foreach(src IN LISTS standalone_src)
  get_filename_component(target ${src} NAME_WE)
  #
  # Compile
  #
  add_executable(${target} ${src})
  string(REGEX REPLACE "File([A-Z]+)" "file_sample.\\1" output_name_base ${target})
  string(TOLOWER ${output_name_base} output_name)
  #
  # add Run task
  #
  add_custom_target(run_${target}
    SOURCES ${output_name}
    COMMENT "Execute produced executable."
  )
  add_custom_command(
    OUTPUT ${output_name}
    COMMAND ${target}
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS ${target}
  )
  add_dependencies(sample_DTL_Storage
    ${target}
  )
  add_dependencies(run_sample_DTL_Storage
    run_${target}
  )
endforeach()
