panda3d_interrogate(
  node
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_ros
)

remake_ros_package_add_library(node PREFIX morsel-ros-
  LINK ${MORSEL_LIBRARIES})
remake_add_headers(INSTALL node)
