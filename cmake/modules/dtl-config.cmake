# - Try to find DTL include dirs
#
# Usage of this module as follows:
#
#     find_package(DTL)
#
# Variables used by this module, they can change the default behaviour and need
# to be set before calling find_package:
#
#  DTL_ROOT_DIR          Set this variable to the root installation of
#                            DTL if the module has problems finding the
#                            proper installation path.
#
# Variables defined by this module:
#
#  DTL_FOUND             System has DTL, include dirs found
#  DTL_INCLUDE_DIR       The DTL include directories.

find_path(DTL_ROOT_DIR
  NAMES include/DTL.hpp
  HINTS
    ENV DTL_ROOT
    ENV DTL_DIR
)

find_path(DTL_INCLUDE_DIR
  NAMES DTL.hpp
  HINTS
    ${DTL_ROOT_DIR}/include
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(DTL DEFAULT_MSG
  DTL_INCLUDE_DIR
)
