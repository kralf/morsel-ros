remake_find_package(PythonLibs)
remake_find_library(panda3d-panda panda.h PACKAGE Panda3d)
remake_find_library(panda3d-morselc morsel.h PACKAGE Morsel)
remake_find_library(roscpp ros/ros.h PACKAGE ROS)

remake_find_executable(panda3d-interrogate)
remake_find_executable(panda3d-interrogate_module)
remake_find_executable(panda3d-gen_pycode)

remake_include(
  ${PYTHON_INCLUDE_PATH}
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_MORSELC_HEADERS}
  ${ROSCPP_HEADERS}
  lib
)

remake_add_directories(lib)
remake_add_directories(metalib)
