cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_libs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

find_package(Eigen3 REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES mintchoco1_libs
  CATKIN_DEPENDS roscpp
  DEPENDS EIGEN3
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
)

add_executable(mintchoco1_node
  src/mintchoco1_node.cpp
  src/mintchoco1.cpp 
  src/kinematics.cpp 
  src/trajectory_generator.cpp 
  src/locomotion.cpp
)
add_dependencies(mintchoco1_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(mintchoco1_node ${catkin_LIBRARIES} )
