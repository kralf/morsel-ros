panda3d_python_package(
  COMMAND ${PANDA3D_GEN_PYCODE_EXECUTABLE}
  NAME morsel_ros.rosc
)
remake_python_distribute(NAME morsel_ros.rosc PACKAGES morsel_ros.rosc
  DESCRIPTION "Python bindings")
