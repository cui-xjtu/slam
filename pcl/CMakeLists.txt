
cmake_minimum_required(VERSION 2.8.3)

project(pcl)

find_package(catkin REQUIRED COMPONENTS

  pcl_conversions

  pcl_ros

  roscpp

  sensor_msgs

  rospy

)

 

find_package(PCL REQUIRED)

catkin_package()

 

include_directories(

  ${catkin_INCLUDE_DIRS}

  ${PCL_INCLUDE_DIRS}

)

 

link_directories(${PCL_LIBRARY_DIRS})

 

 

add_executable(pcl_create src/pcl_create.cpp)

target_link_libraries(pcl_create ${catkin_LIBRARIES} ${PCL_LIBRARIES})


add_executable(pcl_read src/pcl_read.cpp)

add_executable(pcl_write src/pcl_write.cpp)

add_executable(viewer src/viewer.cpp)

add_executable(pcl_filter src/pcl_filter.cpp) 

add_executable(wh_read src/wh_read.cpp) 

add_executable(pcd_read src/pcd_read.cpp) 

add_executable(pcdxyz_read src/pcdxyz_read.cpp) 

add_executable(pcd_read_zhongshu src/pcd_read_zhongshu.cpp)

add_executable(scan_filter src/scan_filter.cpp)

add_executable(output src/output.cpp)

add_executable(pcd_filter src/pcd_filter.cpp)

target_link_libraries(pcl_read ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(pcl_write ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(viewer ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(pcl_filter ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(wh_read ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(pcd_read ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(pcdxyz_read ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(pcd_read_zhongshu ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(scan_filter ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(output ${catkin_LIBRARIES} ${PCL_LIBRARIES})

target_link_libraries(pcd_filter ${catkin_LIBRARIES} ${PCL_LIBRARIES})

