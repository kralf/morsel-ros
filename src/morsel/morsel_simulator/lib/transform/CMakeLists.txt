panda3d_interrogate(
  transform
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_ros
)

remake_ros_package_add_library(transform PREFIX morsel-ros-
  LINK node ${MORSEL_LIBRARIES})
remake_add_headers(INSTALL transform)
