#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/time_synchronizer.h>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <cmath>

   // ros::NodeHandle n;
   // ros::Publisher scan_filter_pub = n.advertise<sensor_msgs::LaserScan>("scan_filter", 1000);
    sensor_msgs::LaserScan scan_filter;
    ros::Publisher scan_filter_pub;
void multi_callback(const sensor_msgs::LaserScanConstPtr& scan, const geometry_msgs::Vector3StampedConstPtr& rpy)
{
		//ros::Rate r(1.0);
	int num_readings = 274;
	double pitch = 0;
	if((rpy->vector.y) < 0.1){
		pitch=1;}
	else{
		pitch=cos(rpy->vector.y);	
	}
	ROS_INFO("processing...%");
    //sensor_msgs::LaserScan scan_filter;
    ros::NodeHandle m;
   scan_filter_pub = m.advertise<sensor_msgs::LaserScan>("scan_filter", 1000);
	ros::Time scan_time = ros::Time::now();
  //  sensor_msgs::LaserScan scan;
    scan_filter.header.stamp = scan_time;
    scan_filter.header.frame_id = scan->header.frame_id;
    scan_filter.angle_min = scan->angle_min;
    scan_filter.angle_max = scan->angle_max;
    scan_filter.angle_increment = scan->angle_increment;
    scan_filter.time_increment = scan->time_increment;
    scan_filter.range_min = scan->range_min;
    scan_filter.range_max = scan->range_max;

   scan_filter.ranges.resize(num_readings);
    scan_filter.intensities.resize(num_readings);
    for(unsigned int i = 0; i < num_readings; ++i){
      scan_filter.ranges[i] = scan->ranges[i]*pitch;
      scan_filter.intensities[i] = scan->intensities[i];
	}

	scan_filter_pub.publish(scan_filter);
	//r.sleep();
		   /**
		  	处理函数 ......
		   */
	}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "scan_filter");
    ros::NodeHandle n;
    //ros::Publisher scan_filter_pub = n.advertise<sensor_msgs::LaserScan>("scan_filter", 1000);
    message_filters::Subscriber<sensor_msgs::LaserScan> subscriber_laser(n,"scan1",1000,ros::TransportHints().tcpNoDelay());
    message_filters::Subscriber<geometry_msgs::Vector3Stamped> subscriber_rpy(n,"imu/rpy/filtered",1000,ros::TransportHints().tcpNoDelay());
    
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::LaserScan, geometry_msgs::Vector3Stamped> syncPolicy;
    //message_filters::TimeSynchronizer<sensor_msgs::LaserScan,geometry_msgs::PoseWithCovarianceStamped> sync(subscriber_laser, subscriber_pose, 10);
    message_filters::Synchronizer<syncPolicy> sync(syncPolicy(10), subscriber_laser, subscriber_rpy);  
    sync.registerCallback(boost::bind(&multi_callback, _1, _2));
    
    std::cout << "processing..." << std::endl;

    ros::spin();
    return 0;
}

