# for cmake issue #16482 to support MSVC `/std:` flag
cmake_minimum_required(VERSION 3.10.0)
add_subdirectory(Sample)
add_custom_target(ci
  DEPENDS run_sample
)
