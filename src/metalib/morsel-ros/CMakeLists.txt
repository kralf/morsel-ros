panda3d_interrogate_module(
  morsel_rosc
  COMMAND ${PANDA3D_INTERROGATE_MODULE_EXECUTABLE}
  MODULE morsel_ros
)

remake_add_library(
  morsel_rosc PREFIX panda3d-
  LINK node input output ${PANDA3D_MORSELC_LIBRARY}
)
