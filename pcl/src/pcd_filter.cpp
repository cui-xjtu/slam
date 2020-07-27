#include <iostream>              //标准C++库中的输入输出的头文件
#include <pcl/io/pcd_io.h>       //PCD读写类相关的头文件
#include <pcl/point_types.h>     //PCL中支持的点类型的头文件
#include <vector>  
#include <algorithm>  
#include <numeric>  
#include "stdlib.h"  
#include<cmath>
#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/passthrough.h>
using namespace std;

#define pi 3.141592653589793
/*************************************************************************

 最小二乘法拟合直线，y = a*x + b; n组数据; r-相关系数[-1,1],fabs(r)->1,说明x,y之间线性关系好，fabs(r)->0，x,y之间无线性关系，拟合无意义

 a = (n*C - B*D) / (n*A - B*B)

 b = (A*D - B*C) / (n*A - B*B)

 r = E / F

 其中：

 A = sum(Xi * Xi)

 B = sum(Xi)

 C = sum(Xi * Yi)

 D = sum(Yi)

 E = sum((Xi - Xmean)*(Yi - Ymean))

 F = sqrt(sum((Xi - Xmean)*(Xi - Xmean))) * sqrt(sum((Yi - Ymean)*(Yi - Ymean)))



**************************************************************************/

void LineFitLeastSquares(float *data_x, float *data_y, int data_n, vector<float> &vResult)

{

	float A = 0.0;

	float B = 0.0;

	float C = 0.0;

	float D = 0.0;

	float E = 0.0;

	float F = 0.0;

 

	for (int i=0; i<data_n; i++)

	{

		A += data_x[i] * data_x[i];

		B += data_x[i];

		C += data_x[i] * data_y[i];

		D += data_y[i];

	}

 

	// 计算斜率a和截距b

	float a, b, temp = 0;

	if( temp = (data_n*A - B*B) )// 判断分母不为0

	{

		a = (data_n*C - B*D) / temp;

		b = (A*D - B*C) / temp;

	}

	else

	{

		a = 1;

		b = 0;

	}

 

	// 计算相关系数r

	float Xmean, Ymean;

	Xmean = B / data_n;

	Ymean = D / data_n;

 

	float tempSumXX = 0.0, tempSumYY = 0.0;

	for (int i=0; i<data_n; i++)

	{

		tempSumXX += (data_x[i] - Xmean) * (data_x[i] - Xmean);

		tempSumYY += (data_y[i] - Ymean) * (data_y[i] - Ymean);

		E += (data_x[i] - Xmean) * (data_y[i] - Ymean);

	}

	F = sqrt(tempSumXX) * sqrt(tempSumYY);

 

	float r;

	r = E / F;

 

	vResult.push_back(a);

	vResult.push_back(b);

	vResult.push_back(r*r);

}


int main (int argc, char** argv)
{ 
int count1=0;
int count2=0;
int count3=0;
int count4=0;
float degree;
vector<float> vl_y;
vector<float> vl_x;
vector<float> vr_y;
vector<float> vr_x;
vector<float> vResult_l;
vector<float> vResult_r;
   //创建一个PointCloud<pcl::PointXYZ>    boost共享指针并进行实例化
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
 
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);

pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);

pcl::PointCloud<pcl::PointXYZ>::Ptr cloud3(new pcl::PointCloud<pcl::PointXYZ>);
 
  //打开点云文件
  if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[1], *cloud) == -1) 
  {
    PCL_ERROR ("Couldn't read file \n");
    return (-1);
  }
//默认就是而二进制块读取转换为模块化的PointCLoud格式里pcl::PointXYZ作为点类型  然后打印出来
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from file with the following fields: "
            << std::endl;
  for (size_t i = 0; i < cloud->points.size (); i++){
		if(cloud->points[i].y > 0 && cloud->points[i].x <3 && cloud->points[i].x >1 && cloud->points[i].z *100 <2 && cloud->points[i].z*100 >-2)
	{
	count1=count1+1;
	vl_x.push_back(cloud->points[i].x);
	vl_y.push_back(cloud->points[i].y);
 //  	   std::cout << "    " << cloud->points[i].x
  //       << " "    << cloud->points[i].y
  //          << " "    << cloud->points[i].z << std::endl;
	}
		else if(cloud->points[i].y < 0 && cloud->points[i].x <3 && cloud->points[i].x >1 && cloud->points[i].z *100 <2 && cloud->points[i].z*100 >-2)
	{
	count2=count2+1;
	vr_x.push_back(cloud->points[i].x);
	vr_y.push_back(cloud->points[i].y);	
	}
}
	int m_l=vl_x.size();
	float px_l[m_l],py_l[m_l];
	int m_r=vr_x.size();
	float px_r[m_r],py_r[m_r];

  for (size_t i = 0; i < m_l; i++){
	px_l[i]=vl_x[i];
	py_l[i]=vl_y[i];
	}

 for (size_t i = 0; i < m_r; i++){
	px_r[i]=vr_x[i];
	py_r[i]=vr_y[i];
	}

	LineFitLeastSquares(px_l, py_l, m_l, vResult_l);
	LineFitLeastSquares(px_r, py_r, m_r, vResult_r);


	cout<<"a1: "<<vResult_l[0]<<endl;
	cout<<"b1: "<<vResult_l[1]<<endl;
	cout<<"r1: "<<vResult_l[2]<<endl;
	cout<<"count1: "<<count1<<endl;

	cout<<"a2: "<<vResult_r[0]<<endl;
	cout<<"b2: "<<vResult_r[1]<<endl;
	cout<<"r2: "<<vResult_r[2]<<endl;
	cout<<"count2: "<<count2<<endl;

	degree=atan(0.5*(vResult_l[0]+vResult_r[0]));
	cout<<"degree: "<<degree<<endl;
//直通滤波
pcl::PassThrough<pcl::PointXYZ> pass1;       //创建滤波器 pass
pass1.setInputCloud(cloud);
pass1.setFilterFieldName("x");
pass1.setFilterLimits(0, 5);
pass1.filter(*cloud1);

pcl::PassThrough<pcl::PointXYZ> pass2;       //创建滤波器 pass
pass2.setInputCloud(cloud1);
pass2.setFilterFieldName("z");
pass2.setFilterLimitsNegative(true);
pass2.setFilterLimits(0.05, 0.18);
pass2.filter(*cloud2);

//离群滤波
 pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;  
 sor.setInputCloud (cloud2); 
 sor.setMeanK (50);  
 sor.setStddevMulThresh (5);  
 sor.filter (*cloud3);

 for (size_t i = 0; i < cloud2->points.size (); i++){
		if(  degree >0.02618)
	{
	count3=count3+1;
	cloud3->points[i].x= cloud3->points[i].x*cos(2*pi - degree) - cloud3->points[i].y *sin(2*pi - degree) ;
	cloud3->points[i].y= cloud3->points[i].x*sin(2*pi - degree) + cloud3->points[i].y *cos(2*pi - degree) ;
	cloud3->points[i].z=cloud3->points[i].z;
	// 	   std::cout << "    " << cloud->points[i].x
      //   << " "    << cloud->points[i].y
    //     << " "    << cloud->points[i].z << std::endl;
	}	

	else if(  degree < -0.02618)
	{
	count3=count3+1;
	cloud3->points[i].x= cloud3->points[i].x*cos( fabs(degree) )- cloud3->points[i].y *sin(fabs(degree) ) ;
	cloud3->points[i].y= cloud3->points[i].x*sin(fabs(degree) ) + cloud3->points[i].y *cos(fabs(degree) ) ;
	cloud3->points[i].z=cloud3->points[i].z;
	// 	   std::cout << "    " << cloud->points[i].x
      //   << " "    << cloud->points[i].y
    //     << " "    << cloud->points[i].z << std::endl;
	}	
}
	cout<<"numbler of points: "<<count3<<endl;

 //for (size_t i = 0; i < cloud->points.size (); i++){
//		if(cloud->points[i].y > 0 && cloud->points[i].x <5 && cloud->points[i].x >1 && cloud->points[i].z *100 <2 && cloud->points[i].z*100 >-2)
//	{
//		count4=count4+1;
//	 	   std::cout << "    " << cloud->points[i].x
 //       << " "    << cloud->points[i].y
//         << " "    << cloud->points[i].z << std::endl;
//	}
//}
//	cout<<"count4: "<<count4<<endl;


 //   ros::init (argc, argv, "pcl_read");
//    ros::NodeHandle nh;
//    ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("pcl_output", 1);
//	    sensor_msgs::PointCloud2 output;
//     pcl::toROSMsg(*cloud, output);
//    output.header.frame_id = "base_link";
//    ros::Rate loop_rate(1);

 //   while (ros::ok())

 //   {

  //      pcl_pub.publish(output);

 //       ros::spinOnce();

 //       loop_rate.sleep();
//
//    }
pcl::PCDWriter writer;
writer.write<pcl::PointXYZ> (argv[2], *cloud3, false);
  return 0;

}
