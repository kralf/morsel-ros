remake_ros_package(
  morsel_simulator
  DEPENDS roscpp rospy tf diagnostic_updater
  EXTRA_BUILD_DEPENDS morsel-dev morsel-python
  EXTRA_RUN_DEPENDS morsel morsel-python
  DESCRIPTION "simulator"
)

remake_ros_package(
  morsel_diagnostics
  DEPENDS roscpp rospy diagnostic_aggregator
  DESCRIPTION "diagnostics"
)
