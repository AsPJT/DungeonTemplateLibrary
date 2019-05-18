# for cmake issue #16482 to support MSVC `/std:` flag
cmake_minimum_required(VERSION 3.10.0)
set(children
  Shape
  Storage
)
add_custom_target(sample_DTL)
add_custom_target(run_sample_DTL)
foreach(child IN LISTS children)
  add_subdirectory(${child})
  add_dependencies(sample_DTL sample_DTL_${child})
  add_dependencies(run_sample_DTL run_sample_DTL_${child})
endforeach()
