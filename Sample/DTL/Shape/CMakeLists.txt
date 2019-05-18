# for cmake issue #16482 to support MSVC `/std:` flag
cmake_minimum_required(VERSION 3.10.0)

enable_language(CXX)

#
# Setup pproject path
#
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE NEVER)
find_path(DTL_ROOT_DIR
  NAMES include/DTL.hpp
  HINTS
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
  Border.cpp
  BorderOdd.cpp
  CellularAutomatonIsland.cpp
  CellularAutomatonMixIsland.cpp
  DiamondSquareAverageCornerIsland.cpp
  DiamondSquareAverageIsland.cpp
  FractalIsland.cpp
  FractalLoopIsland.cpp
  MazeDig.cpp
  PointGrid.cpp
  PointGridAndSomeBlocksWithBorder.cpp
  PointGridWithBorder.cpp
  RandomRect.cpp
  RandomVoronoi.cpp
  Rect.cpp
  Reversi.cpp
  SimpleRogueLike.cpp
  SimpleVoronoiIsland.cpp
  WhiteNoise.cpp
)
add_custom_target(sample_DTL_Shape)
add_custom_target(run_sample_DTL_Shape)
foreach(src IN LISTS standalone_src)
  get_filename_component(target ${src} NAME_WE)
  #
  # Compile
  #
  add_executable(${target} ${src})
  #
  # add Run task
  #
  add_custom_target(run_${target}
    COMMAND ${target}
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS ${target}
    COMMENT "Execute produced executable."
  )
  add_dependencies(sample_DTL_Shape
    ${target}
  )
  add_dependencies(run_sample_DTL_Shape
    run_${target}
  )
endforeach()

