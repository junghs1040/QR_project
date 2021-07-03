cmake_minimum_required(VERSION 3.0.2)
project(mintchoco1_gazebo)


find_package(catkin 
  REQUIRED 
)

catkin_package()


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}

)

install(DIRECTORY launch config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY worlds
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
