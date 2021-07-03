cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_controller)

find_package(catkin REQUIRED 
  COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION} )

