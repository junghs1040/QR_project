cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_libs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

find_package(Eigen3 REQUIRED)

generate_messages(DEPENDENCIES std_msgs)

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

add_library(mintchoco1_libs
  src/kinematics.cpp
  src/trajectory_generator.cpp
  src/gait_scheduler.cpp
)
add_dependencies(mintchoco1_libs ${catkin_EXPORTED_TARGETS})
target_link_libraries(mintchoco1_libs ${catkin_LIBRARIES} ${Eigen3_LIBRARIES})
