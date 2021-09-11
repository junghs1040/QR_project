cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_teleop)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  mintchoco1_msgs
  message_generation
)

#add_message_files(
#  FILES
#  Mintchoco1Control.msg
#)

#generate_messages(
#  DEPENDENCIES
#)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp message_runtime
)


include_directories(${catkin_INCLUDE_DIRS})

add_executable(mintchoco1_keyboard src/mintchoco1_keyboard.cpp)
target_link_libraries(mintchoco1_keyboard ${catkin_LIBRARIES})
