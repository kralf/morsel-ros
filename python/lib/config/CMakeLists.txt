remake_ros_find_package(roscpp)
remake_ros_find_package(tf)

remake_file_configure(*.remake)
remake_python_package(NAME morsel_ros.config
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
