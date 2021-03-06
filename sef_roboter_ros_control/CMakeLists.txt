cmake_minimum_required(VERSION 2.8.3)
project(sef_roboter_ros_control)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sef_roboter_msgs
  ros_control_boilerplate
)

catkin_package(
  CATKIN_DEPENDS
    roscpp
    std_msgs
    sef_roboter_msgs
    ros_control_boilerplate
  INCLUDE_DIRS
    include   
)

include_directories(include ${catkin_INCLUDE_DIRS} ${ros_control_boilerplate_INCLUDE_DIRS})

# SefRoboter Hardware Interface
add_library(sef_roboter_hw_interface
  src/sef_roboter_hw_interface.cpp
)
target_link_libraries(sef_roboter_hw_interface
  generic_hw_interface
  ${catkin_LIBRARIES}
)

# Main control executable
add_executable(sef_roboter_hw_main src/sef_roboter_hw_main.cpp)
target_link_libraries(sef_roboter_hw_main
  sef_roboter_hw_interface
  generic_hw_control_loop
  ${catkin_LIBRARIES}
)

## Install ------------------------------------------------------------

# Install libraries
install(TARGETS
    sef_roboter_hw_interface
  LIBRARY DESTINATION
    ${CATKIN_PACKAGE_LIB_DESTINATION}
)

# Install executables
install(TARGETS
    sef_roboter_hw_main
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install header files
install(DIRECTORY include/sef_roboter_ros_control/ DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
