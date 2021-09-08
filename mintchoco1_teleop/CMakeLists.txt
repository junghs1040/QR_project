cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_teleop)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS geometry_msgs roscpp
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(mintchoco1_keyboard src/mintchoco1_keyboard.cpp)
target_link_libraries(mintchoco1_keyboard ${catkin_LIBRARIES})
