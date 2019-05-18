# for cmake issue #16482 to support MSVC `/std:` flag
cmake_minimum_required(VERSION 3.10.0)
add_subdirectory(DTL)
add_custom_target(sample
  DEPENDS sample_DTL
)
add_custom_target(run_sample
  DEPENDS run_sample_DTL
)
