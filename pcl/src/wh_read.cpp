
#include <rosbag/bag.h>

#include <rosbag/view.h>

#include <std_msgs/Int32.h>

#include <std_msgs/String.h>

 

#include <ros/ros.h>

// PCL specific includes
#include <sensor_msgs/LaserScan.h>

#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>

#include <pcl/point_cloud.h>

#include <pcl/point_types.h>

 

#include <pcl/visualization/pcl_visualizer.h>

#include <boost/thread/thread.hpp>

#include <pcl/visualization/cloud_viewer.h>

#include <sensor_msgs/CompressedImage.h>

#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

#include <thread>

#include <cmath>
#define pi 3.1415926

//ros::Publisher pub;

//pcl::visualization::CloudViewer viewer("Cloud Viewer");
// bool  judge_range(sensor_msgs::LaserScan::ConstPtr msg);


int main(int argc, char** argv)

{

      // Initialize ROS

    ros::init (argc, argv, "wh_read");

    ros::NodeHandle nh;
    std::string file_name;
	nh.param<std::string>("file_name", file_name);
   //char* bag_path = argv[1];
	if(argc!=2){
      std::cout<<"输入参数有误!"<<std::endl;
      return -1;
			}
    rosbag::Bag bag;

    bag.open(argv[1], rosbag::bagmode::Read); //打开一个bag文件

    

    std::vector<std::string> topics; //设置需要遍历的topic

    //topics.push_back(std::string("/scan1"));         

    topics.push_back(std::string("/scan2"));        

   // topics.push_back(std::string("/usb_cam/image_raw0/compressed"));

    //topics.push_back(std::string("/usb_cam/image_raw1/compressed"));

   // topics.push_back(std::string("/usb_cam/image_raw2/compressed"));

    //topics.push_back(std::string("/usb_cam/image_raw3/compressed"));

    //topics.push_back(std::string("/miliwave_base"));                

    //topics.push_back(std::string("/back_miliwave_base"));           

    //topics.push_back(std::string("/radar_cloud "));

    rosbag::View view(bag, rosbag::TopicQuery(topics));; // 读指定的topic，如果全读，第二个参数不写，如下

    //rosbag::View view_all(view); //读取全部topic


    // foreach(rosbag::MessageInstance const m, view) //用foreach遍历所有帧数据，每个messageInstance就是一帧数据

    // {

    int num; 
    int count=0;
    float hight=0.0;
    float width=0.0;
    float r1=0.0,r2=0.0,r3=0.0,r4=0.0,h_r1=0.0,h_r2=0.0,h_r3=0.0,h_r4=0.0;
    float l1=0.0,l2=0.0,l3=0.0,l4=0.0,h_l1=0.0,h_l2=0.0,h_l3=0.0,h_l4=0.0;
    //while(true){

    rosbag::View::iterator it = view.begin(); //使用迭代器的方式遍历

    //std::cout<<"please input num:";

    //std::cin>>num;

    //std::cout<<"num:"<<num<<std::endl;

    // for(int i = 0; i < num; ++i)

    //     ++it;

    //std::advance(it,num);

    for(; it !=  view.end(); ++it)

    {  

        auto m = *it;

        std::string topic   = m.getTopic();

        //std::cout<<"topic:"<<topic<<std::endl;

        //std::string callerid       = m.getCallerId();

        //std::cout<<"callerid:"<<callerid<<std::endl;

        //ros::Time  time = m.getTime();

        //std::cout<<"time:"<<time.sec<<":"<<time.nsec<<std::endl;
       
        //count=count+1;

	//std::cout<<"count:"<<count<<std::endl;


        //ros::Time translated = time_translator_.translate(time);


        //sensor_msgs::LaserScan::ConstPtr input = m.instantiate<sensor_msgs::LaserScan>();

        //sensor_msgs::PointCloud2ConstPtr input = *s ;

        //if (input != NULL)

        //{

            // 创建一个输出的数据格式

            //sensor_msgs::LaserScan input;  //ROS中点云的数据格式

            //对数据进行处理

            //pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);

 

            //pcl::fromROSMsg(input,*cloud);

     

            //blocks until the cloud is actually rendered

            //viewer.showCloud(cloud);

    

            //pub.publish (input);

        //}

        if(topic == "/scan2"){

            sensor_msgs::LaserScan::ConstPtr msg = m.instantiate<sensor_msgs::LaserScan>();

		//bool ok = judge_range(msg);

            //char* img = new char[frontCamMsg->data.size()];

            //double laser[msg->ranges.size()];
             
             //if(){
	     count=count+1;
             std::cout<<"count:"<<count<<std::endl;
            //memcpy(laser, &msg->ranges[0], msg->ranges.size());
	    float temp_hight=0.0;
	    float temp_width=0.0;
   	    float temp_r1=0.0,temp_r2=0.0,temp_r3=0.0,temp_r4=0.0,temp_h_r1=0.0,temp_h_r2=0.0,temp_h_r3=0.0,temp_h_r4=0.0;
   	    float temp_l1=0.0,temp_l2=0.0,temp_l3=0.0,temp_l4=0.0,temp_h_l1=0.0,temp_h_l2=0.0,temp_h_l3=0.0,temp_h_l4=0.0;

           // for(int i = 0; i<msg->ranges.size(); ++i)

            std::cout<< msg->ranges[0] <<" "<< msg->ranges[0.5*msg->ranges.size()] ;
            //std::cout<<std::endl;
       if(msg->ranges[0]<12 && msg->ranges[0.5*msg->ranges.size()]<12)
            temp_hight=msg->ranges[0] + msg->ranges[0.5*msg->ranges.size()];
	else
	    temp_hight=hight;

       if(msg->ranges[0.25*msg->ranges.size()]<12 && msg->ranges[0.75*msg->ranges.size()]<12)
	    temp_width= msg->ranges[0.25*msg->ranges.size()] +msg->ranges[0.75*msg->ranges.size()];
	else
	    temp_width=width;

	if(msg->ranges[0.05*msg->ranges.size()]<12 && msg->ranges[0.55*msg->ranges.size()]<12){
	     temp_r1= msg->ranges[0.05*msg->ranges.size()]*sin(0.1*pi);
	     temp_h_r1= msg->ranges[0.05*msg->ranges.size()]*cos(0.1*pi) + msg->ranges[0.55*msg->ranges.size()] *cos(0.1*pi) ;
	}
	else{
	    temp_r1=r1;
	    temp_h_r1=h_r1;
	}

	if(msg->ranges[0.1*msg->ranges.size()]<12 && msg->ranges[0.6*msg->ranges.size()]<12){
		temp_r2= msg->ranges[0.1*msg->ranges.size()]*sin(0.2*pi);
		temp_h_r2= msg->ranges[0.1*msg->ranges.size()]*cos(0.2*pi) + msg->ranges[0.6*msg->ranges.size()] *cos(0.2*pi) ;
	}
	else{
	    temp_r2=r2;
	    temp_h_r2=h_r2;
	}

	if(msg->ranges[0.15*msg->ranges.size()]<12 && msg->ranges[0.65*msg->ranges.size()]<12){
		temp_r3= msg->ranges[0.15*msg->ranges.size()]*sin(0.3*pi);
		temp_h_r3= msg->ranges[0.15*msg->ranges.size()]*cos(0.3*pi) + msg->ranges[0.65*msg->ranges.size()] *cos(0.3*pi) ;
	}
	else{
	    temp_r3=r3;
	    temp_h_r3=h_r3;
	}

	if(msg->ranges[0.2*msg->ranges.size()]<12 && msg->ranges[0.7*msg->ranges.size()]<12){
		temp_r4= msg->ranges[0.2*msg->ranges.size()]*sin(0.4*pi);
		temp_h_r4= msg->ranges[0.2*msg->ranges.size()]*cos(0.4*pi) + msg->ranges[0.7*msg->ranges.size()] *cos(0.4*pi) ;
	}
	else{
	    temp_r4=r4;
	    temp_h_r4=h_r4;
	}

	if(msg->ranges[0.45*msg->ranges.size()]<12 && msg->ranges[0.95*msg->ranges.size()]<12){
		temp_l1= msg->ranges[0.95*msg->ranges.size()]*sin(0.1*pi);
		temp_h_l1= msg->ranges[0.95*msg->ranges.size()]*cos(0.1*pi) + msg->ranges[0.45*msg->ranges.size()] *cos(0.1*pi) ;
	}
	else{
	    temp_l1=l1;
	    temp_h_l1=h_l1;
	}

	if(msg->ranges[0.4*msg->ranges.size()]<12 && msg->ranges[0.9*msg->ranges.size()]<12){
		temp_l2= msg->ranges[0.9*msg->ranges.size()]*sin(0.2*pi);
		temp_h_l2= msg->ranges[0.9*msg->ranges.size()]*cos(0.2*pi) + msg->ranges[0.4*msg->ranges.size()] *cos(0.2*pi) ;
	}
	else{
	    temp_l2=l2;
	    temp_h_l2=h_l2;
	}

	if(msg->ranges[0.35*msg->ranges.size()]<12 && msg->ranges[0.85*msg->ranges.size()]<12){
		temp_l3= msg->ranges[0.85*msg->ranges.size()]*sin(0.3*pi);
		temp_h_l3= msg->ranges[0.85*msg->ranges.size()]*cos(0.3*pi) + msg->ranges[0.35*msg->ranges.size()] *cos(0.3*pi) ;
	}
	else{
	    temp_l3=l3;
	    temp_h_l3=h_l3;
	}

	if(msg->ranges[0.4*msg->ranges.size()]<12 && msg->ranges[0.8*msg->ranges.size()]<12){
		temp_l4= msg->ranges[0.8*msg->ranges.size()]*sin(0.4*pi);
		temp_h_l4= msg->ranges[0.8*msg->ranges.size()]*cos(0.4*pi) + msg->ranges[0.3*msg->ranges.size()] *cos(0.4*pi) ;
	}
	else{
	    temp_l4=l4;
	    temp_h_l4=h_l4;
	}
            //std::cout<<"hight1:"<<hight1<<std::endl;
	   // std::cout<<"width1:"<<width1<<std::endl;
		if(count==1){
            hight=temp_hight;
            width=temp_width;

	    r1=temp_r1;
	    h_r1=temp_h_r1;
	    r2=temp_r2;
	    h_r2=temp_h_r2;
	    r3=temp_r3;
	    h_r3=temp_h_r3;
	    r4=temp_r4;
	    h_r4=temp_h_r4;

	    l1=temp_l1;
	    h_l1=temp_h_l1;
	    l2=temp_l2;
	    h_l2=temp_h_l2;
	    l3=temp_l3;
	    h_l3=temp_h_l3;
	    l4=temp_l4;
	    h_l4=temp_h_l4;
		}
		else{
            hight=(hight+temp_hight)/2;
            width=(width+temp_width)/2;

	    r1=(r1+temp_r1)/2;
	    h_r1=(h_r1+temp_h_r1)/2;
	    r2=(r2+temp_r2)/2;
	    h_r2=(h_r2+temp_h_r2)/2;
	    r3=(r3+temp_r3)/2;
	    h_r3=(h_r3+temp_h_r3)/2;
	    r4=(r4+temp_r4)/2;
	    h_r4=(h_r4+temp_h_r4)/2;

	    l1=(l1+temp_l1)/2;
	    h_l1=(h_l1+temp_h_l1)/2;
	    l2=(l2+temp_l2)/2;
	    h_l2=(h_l2+temp_h_l2)/2;
	    l3=(l3+temp_l3)/2;
	    h_l3=(h_l3+temp_h_l3)/2;
	    l4=(l4+temp_l4)/2;
	    h_l4=(h_l4+temp_h_l4)/2;
		}
            //std::cout<<"hight:"<<hight<<std::endl;
        //}
         //hight=(hight+hight1)/count;
         //hight1=0.0;
std::cout<<"temp_hight:"<<temp_hight<<std::endl;
std::cout<<"temp_width:"<<temp_width<<std::endl;
         //std::cout<<"hight:"<<hight<<std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }       
  std::cout<<"hight:"<<hight<<std::endl;
		//std::cout<<"temp_hight:"<<hight<<std::endl;
  std::cout<<"width:"<<width<<std::endl;
		//std::cout<<"temp_width:"<<width<<std::endl;

  std::cout<<"r1:"<<r1<<std::endl;
  std::cout<<"h_r1:"<<h_r1<<std::endl;
  std::cout<<"r2:"<<r2<<std::endl;
  std::cout<<"h_r2:"<<h_r2<<std::endl;
  std::cout<<"r3:"<<r3<<std::endl;
  std::cout<<"h_r3:"<<h_r3<<std::endl;
  std::cout<<"r4:"<<r4<<std::endl;
  std::cout<<"h_r4:"<<h_r4<<std::endl;

  std::cout<<"l1:"<<l1<<std::endl;
  std::cout<<"h_l1:"<<h_l1<<std::endl;
  std::cout<<"l2:"<<l2<<std::endl;
  std::cout<<"h_l2:"<<h_l2<<std::endl;
  std::cout<<"l3:"<<l3<<std::endl;
  std::cout<<"h_l3:"<<h_l3<<std::endl;
  std::cout<<"l4:"<<l4<<std::endl;
  std::cout<<"h_l4:"<<h_l4<<std::endl;
  std::cout<<std::endl;
    }
  //std::cout<<"hight:"<<hight<<std::endl;
  //std::cout<<"width:"<<width<<std::endl;
   // }

    //getchar();
			
    bag.close();
    return 0 ;

}
