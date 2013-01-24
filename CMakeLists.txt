cmake_minimum_required(VERSION 2.6)

include(ReMake)
include(Panda3D)

remake_project(
  morsel-ros
  VERSION 1.0
  RELEASE beta
  SUMMARY "Morsel ROS bindings"
  AUTHOR "Ralf Kaestner"
  CONTACT "ralf.kaestner@mavt.ethz.ch"
  HOME "http://aslforge.ethz.ch/projects/morsel-ros"
  LICENSE "GNU Lesser General Public License (LGPL)"
  INSTALL /usr
)

remake_python()
remake_doc(
  html
  latex
)

remake_pack_deb(
  morsel
)
remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  morsel-ros morsel-dev
)
remake_pack_deb(
  COMPONENT python
  morsel-ros morsel-python
)
remake_pack_deb(
  COMPONENT doc
  DESCRIPTION "Documentation"
  morsel-ros
)
