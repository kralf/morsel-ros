panda3d_interrogate(
  output
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_ros
)

remake_ros_package_add_library(output PREFIX morsel-ros-
  LINK node transform ${MORSEL_LIBRARIES})
remake_add_headers(INSTALL output)
