panda3d_interrogate_include(
  ${PANDA3D_PANDA_HEADERS}
  ${PANDA3D_PANDA_HEADERS}/parser-inc
)
panda3d_interrogate(
  transform
  COMMAND ${PANDA3D_INTERROGATE_EXECUTABLE}
  MODULE morsel_ros
)

remake_add_library(transform LINK ${ROS_TF_LIBRARIES})
remake_add_headers(INSTALL transform)
