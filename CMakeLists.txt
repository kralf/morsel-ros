cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  morsel-ros-${ROS_DISTRIBUTION}
  VERSION 1.0
  RELEASE beta
  SUMMARY "ROS bindings for the MObile Robot Simulator."
  AUTHOR "Ralf Kaestner"
  CONTACT "ralf.kaestner@gmail.com"
  HOME "http://github.com/kralf/morsel-ros"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
)

remake_doc(
  html
)

remake_ros_pack_deb()

remake_pack_deb(
  ARCH all
  COMPONENT doc
  DESCRIPTION "documentation"
)

remake_var_name(GIT_REVISION_VAR ${REMAKE_PROJECT_FILENAME} GIT_REVISION)

if(ROS_DISTRIBUTION STRLESS "groovy")
  remake_ros_distribute_deb(
    DISTRIBUTION lucid
    SECTION misc
    ARCH "i386 amd64"
    UPLOAD ppa:kralf/naro
    DEPENDS remake pkg-config doxygen
    PASS CMAKE_BUILD_TYPE ${GIT_REVISION_VAR}
    FORCE_CONSISTENCY
  )
endif(ROS_DISTRIBUTION STRLESS "groovy")

remake_ros_distribute_deb(
  DISTRIBUTION precise
  SECTION misc
  ARCH "i386 amd64"
  UPLOAD ppa:kralf/naro
  DEPENDS remake pkg-config doxygen
  PASS CMAKE_BUILD_TYPE ${GIT_REVISION_VAR}
  FORCE_CONSISTENCY
)
