#include <iostream>              //标准C++库中的输入输出的头文件
#include <pcl/io/pcd_io.h>       //PCD读写类相关的头文件
#include <pcl/point_types.h>     //PCL中支持的点类型的头文件
#include <vector>  
#include <algorithm>  
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

 

int main()

{

	vector <int> arr = {12, 2, 5, 6, 21};//{ 1, 2, 2, 2, 4, 6, 6, 8, 11 };

	vector<int> res;

	res = majorityElement(arr);

 

	for (int i = 0; i < res.size(); i++)

	{

		cout << res[i] << ' ';

	}

	

	system("pause");

	return 0;


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
int y_r=0;
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
	Solution solve_vr;
	Solution solve_vl;
	y_r=solve_vr.majorityElement(vr);
	y_l=solve_vl.majorityElement(vl);
	cout<<y_r<<endl;
	cout<<y_l<<endl;
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
	Solution solve_v_rp0;
	Solution solve_v_rm0;
	Solution solve_v_rp1;
	Solution solve_v_rm1;
	Solution solve_v_rp2;
	Solution solve_v_rm2;
	Solution solve_v_rp3;
	Solution solve_v_rm3;
	Solution solve_v_rp4;
	Solution solve_v_rm4;
	Solution solve_v_lp1;
	Solution solve_v_lm1;
	Solution solve_v_lp2;
	Solution solve_v_lm2;
	Solution solve_v_lp3;
	Solution solve_v_lm3;
	Solution solve_v_lp4;
	Solution solve_v_lm4;

	z_r0=solve_v_rp0.majorityElement(v_rp0) + fabs(solve_v_rm0.majorityElement(v_rm0));
	z_r1=solve_v_rp1.majorityElement(v_rp1) + fabs(solve_v_rm1.majorityElement(v_rm1));
	z_r2=solve_v_rp2.majorityElement(v_rp2) + fabs(solve_v_rm2.majorityElement(v_rm2));
	z_r3=solve_v_rp3.majorityElement(v_rp3) + fabs(solve_v_rm3.majorityElement(v_rm3));
	z_r4=solve_v_rp4.majorityElement(v_rp4) + fabs(solve_v_rm4.majorityElement(v_rm4));

	//z_l1=solve_v_lp1.majorityElement(v_lp1) + fabs(solve_v_lm1.majorityElement(v_lm1));
	z_l2=solve_v_lp2.majorityElement(v_lp2) + fabs(solve_v_lm2.majorityElement(v_lm2));
	z_l3=solve_v_lp3.majorityElement(v_lp3) + fabs(solve_v_lm3.majorityElement(v_lm3));
	z_l4=solve_v_lp4.majorityElement(v_lp4) + fabs(solve_v_lm4.majorityElement(v_lm4));
std::cout <<" x:   " << x/count1<< std::endl;
std::cout <<" y:   " << y/count2<< std::endl;
std::cout << 0 <<" 1:   " << solve_v_rp0.majorityElement(v_lp1)<<" 2:   " << solve_v_rm0.majorityElement(v_lm1)<< std::endl;
std::cout << 0 <<" z_r0:   " << z_r0<< std::endl;
std::cout << round(0.2*y_r) <<" z_r1:   " << z_r1<< std::endl;
std::cout << round(0.4*y_r) <<" z_r2:   " << z_r2 << std::endl;
std::cout << round(0.6*y_r) <<" z_r3:   " << z_r3<< std::endl;
std::cout << round(0.8*y_r) <<" z_r4:   " << z_r4<< std::endl;

std::cout << round(0.2*y_l) <<" z_l1:   " << z_l1<< std::endl;
std::cout << round(0.4*y_l) <<" z_l2:   " << z_l2<< std::endl;
std::cout << round(0.6*y_l) <<" z_l3:   " << z_l3<< std::endl;
std::cout << round(0.8*y_l) <<" z_l4:   " << z_l4<< std::endl;
  return 0;

}
