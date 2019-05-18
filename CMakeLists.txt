# for cmake issue #16482 to support MSVC `/std:` flag
cmake_minimum_required(VERSION 3.10.0)
project(DTL)

set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE NEVER)
find_path(DTL_ROOT_DIR
  NAMES include/DTL.hpp
  HINTS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../
  NO_DEFAULT_PATH
)

add_subdirectory(Sample)
add_custom_target(ci
  DEPENDS run_sample
)

#
# install
#
install(DIRECTORY ${DTL_ROOT_DIR}/include/
  DESTINATION include
)
install(
  FILES  ${DTL_ROOT_DIR}/cmake/modules/dtl-config.cmake
  DESTINATION share/cmake/DTL/
)
