#include <iostream>              //标准C++库中的输入输出的头文件
#include <pcl/io/pcd_io.h>       //PCD读写类相关的头文件
#include <pcl/point_types.h>     //PCL中支持的点类型的头文件
#include <vector>  
#include <algorithm>  
#include <numeric>  
#include "stdlib.h"  
using namespace std;


/************ 求数组中的众数 *************/

vector<int> majorityElement(vector<int> arr) {
	vector<int> numSet;
	vector<int> count;
	vector<int> res;
	numSet.push_back(arr[0]);
	count.push_back(1);

	if (arr.size() == 1)
	{
		res.push_back(arr[0]);
		return res;
	}//当数组大小为1时
	else if (arr.size() == 2)
	{
		res.push_back(arr[0]);
		if (arr[0] != arr[1])
		{
			res.push_back(arr[1]);
		}
	return res;
	} //当数组大小为2时
 
	//当数组大小大于等于三时
	sort(arr.begin(), arr.end()); //先排序
	int m = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != arr[i - 1]) {
			numSet.push_back(arr[i]);//记录下不重复的值
			count.push_back(1); //并将次数赋值为1
		m++;
		}
		else
			count[m]++; //当和前值相等时，次数加1
	}
	int max = count[0];
	for (int i = 0; i < count.size(); i++) //求出最大的次数
	{
		if (max < count[i])
		max = count[i];
	}
	for (int i = 0; i < count.size(); i++) //输出次数最大的值
	{
		if (count[i] == max)
			res.push_back(numSet[i]);
	}
	return res;
		//cout << arr[i] << ' ';
}

int main (int argc, char** argv)
{ 
vector<int> vr;
vector<int> vl;
vector<int> v_rp0;
vector<int> v_rm0;
vector<int> v_rp1;
vector<int> v_rm1;
vector<int> v_rp2;
vector<int> v_rm2;
vector<int> v_rp3;
vector<int> v_rm3;
vector<int> v_rp4;
vector<int> v_rm4;

vector<int> v_lp1;
vector<int> v_lm1;
vector<int> v_lp2;
vector<int> v_lm2;
vector<int> v_lp3;
vector<int> v_lm3;
vector<int> v_lp4;
vector<int> v_lm4;

double x=0.0;
double y=0.0;
vector<int> y_r;
vector<int> y_l;
int y_l=0;
int count=0;
int count1=0;
int count2=0;
double z_ra,z_rb;
double z_r1=0,z_r2=0,z_r3=0,z_r4=0,z_r0=0, z_l1=0,z_l2=0,z_l3=0,z_l4=0;
   //创建一个PointCloud<pcl::PointXYZ>    boost共享指针并进行实例化
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  
  //打开点云文件
  if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[1], *cloud) == -1) 
  {
    PCL_ERROR ("Couldn't read file map.pcd \n");
    return (-1);
  }
//默认就是而二进制块读取转换为模块化的PointCLoud格式里pcl::PointXYZ作为点类型  然后打印出来
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  for (size_t i = 0; i < cloud->points.size (); i++){
		if(cloud->points[i].y > 0)
	vr.push_back(round(cloud->points[i].y*100));
		else if(cloud->points[i].y < 0)
	vl.push_back(round(cloud->points[i].y*100));	
}

	y_r=majorityElement(vr);
	y_l=majorityElement(vl);
	cout<<(accumulate(y_r.begin(),y_r.end()))/y_r.size()<<endl;
	cout<<(accumulate(y_l.begin(),y_l.end()))/y_l.size()<<endl;
	vector<int>().swap(vr);
	vector<int>().swap(vl);
	//cout<<"3.vr的容量:"<< vr.capacity() <<endl;

  for (size_t i = 0; i < cloud->points.size (); ++i){
	//x_cm=floor(cloud->points[i].x*100);
	y=round(cloud->points[i].y*100);
	//z_cm=floor(cloud->points[i].z*100);
	//v_y.push_back(a[i]); 

	if(y==0.0 && fabs(cloud->points[i].z) >0.15){
//	if(cloud->points[i].z> 0)
//	count1=count1+1;
//	else if(cloud->points[i].z<0)
//	count2=count2+1;
//	std::cout  <<" cloud->points[i].z:   " << cloud->points[i].z<< std::endl;
		if(cloud->points[i].z> 0)
	v_rp0.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm0.push_back(round(cloud->points[i].z*100));	
		}

if(y==round(0.2*y_r) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_rp1.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm1.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.4*y_r) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_rp2.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm2.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.6*y_r) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_rp3.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm3.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.8*y_r) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_rp4.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm4.push_back(round(cloud->points[i].z*100));
		}



if(y==round(0.2*y_l) && fabs(cloud->points[i].z) >0.25){
		if(round(cloud->points[i].z ) >0){
	x=round(cloud->points[i].z*100)+x;
	count1=count1+1;
	v_lp1.push_back(round(cloud->points[i].z*100));
	std::cout  <<"count1  "<<count2<<" cloud->points[i].z:   " << cloud->points[i].z<< std::endl;}
		else if(round(cloud->points[i].z)<0){
	y=round(cloud->points[i].z*100)+y;
	v_lm1.push_back(round(cloud->points[i].z*100));
	count2=count2+1;}
	//std::cout  <<"count2  "<<count2<<" cloud->points[i].z:   " << cloud->points[i].z<< std::endl;}
		}

if(y==round(0.4*y_l) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_lp2.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm2.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.6*y_l) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_lp3.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm3.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.8*y_l) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0)
	v_lp4.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm4.push_back(round(cloud->points[i].z*100));
		}


    //std::cout << "    " << cloud->points[i].x
    //          << " "    << cloud->points[i].y
     //         << " "    << cloud->points[i].z << std::endl;

}
  return 0;

}
