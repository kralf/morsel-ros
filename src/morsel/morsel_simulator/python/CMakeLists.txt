remake_add_directories(config morsel_ros)
remake_python_distribute(
  NAME morsel_ros
  PACKAGES morsel_ros morsel_ros.config
)
remake_add_directories(rosc)
