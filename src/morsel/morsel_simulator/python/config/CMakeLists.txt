remake_component_get(${REMAKE_COMPONENT} CONFIGURATION_DESTINATION DESTINATION)
remake_component_get(${REMAKE_COMPONENT} FILE_DESTINATION DESTINATION)

remake_file_configure(*.remake)
remake_python_package(
  NAME morsel_ros.config
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
