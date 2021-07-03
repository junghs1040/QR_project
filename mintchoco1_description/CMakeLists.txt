cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_description)

find_package(catkin REQUIRED COMPONENTS
  joint_state_publisher
  robot_state_publisher
  rviz
  tf
  urdf
  xacro
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

 install(DIRECTORY launch meshes rviz urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
