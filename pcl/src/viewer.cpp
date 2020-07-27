
#include <iostream>

#include <ros/ros.h>

#include <pcl/visualization/cloud_viewer.h>

#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>

 

class cloudHandler

{

public:

    cloudHandler()

    : viewer("Cloud Viewer")

    {

     pcl::PointCloud<pcl::PointXYZ> cloud;

     pcl::io::loadPCDFile ("/home/cui/catkin_ws/src/chapter10_tutorials/file/map.pcd", cloud);

     viewer.showCloud(cloud.makeShared());

     viewer_timer = nh.createTimer(ros::Duration(0.1), &cloudHandler::timerCB, this);

    }

 

    void timerCB(const ros::TimerEvent&)

    {

        if (viewer.wasStopped())

        {

            ros::shutdown();

        }

    }

 

protected:

    ros::NodeHandle nh;

    pcl::visualization::CloudViewer viewer;

    ros::Timer viewer_timer;

};

 

main (int argc, char **argv)

{

    ros::init (argc, argv, "pcl_filter");

    cloudHandler handler;

    ros::spin();

    return 0;

}

