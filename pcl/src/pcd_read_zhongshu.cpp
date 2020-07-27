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

vector<int> rp0;
vector<int> rm0;
vector<int> rp1;
vector<int> rm1;
vector<int> rp2;
vector<int> rm2;
vector<int> rp3;
vector<int> rm3;
vector<int> rp4;
vector<int> rm4;

vector<int> v_lp1;
vector<int> v_lm1;
vector<int> v_lp2;
vector<int> v_lm2;
vector<int> v_lp3;
vector<int> v_lm3;
vector<int> v_lp4;
vector<int> v_lm4;

vector<int> lp1;
vector<int> lm1;
vector<int> lp2;
vector<int> lm2;
vector<int> lp3;
vector<int> lm3;
vector<int> lp4;
vector<int> lm4;

double x=0.0;
double y=0.0;
int y_r=0;
int y_l=0;
vector<int> v_y_r;
vector<int> v_y_l;
//int y_l=0;
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
		if(cloud->points[i].y > 0 && cloud->points[i].x <5)
	vr.push_back(round(cloud->points[i].y*100));
		else if(cloud->points[i].y < 0  && cloud->points[i].x <5)
	vl.push_back(round(cloud->points[i].y*100));	
}

	v_y_r=majorityElement(vr);
	v_y_l=majorityElement(vl);
	//cout<<accumulate(y_r.begin(),y_r.end(),0)<<endl;
	//cout<<accumulate(y_l.begin(),y_l.end(),0)<<endl;
	//cout<<"vr:"<<vr.capacity()<<endl;
	//cout<<"vl:"<<vl.capacity()<<endl;
	y_r=(accumulate(v_y_r.begin(),v_y_r.end(),0))/v_y_r.size();
	y_l=fabs((accumulate(v_y_l.begin(),v_y_l.end(),0)))/v_y_l.size();
	cout<<"y_l: "<<y_r<<endl;
	cout<<"y_r: "<<-y_l<<endl;
	cout<<"width "<<y_r+y_l<<endl;
	vector<int>().swap(vr);
	vector<int>().swap(vl);
	//cout<<"3.vr的容量:"<< vr.capacity() <<endl;

	v_rm0.push_back(0);
	v_rm1.push_back(0);
	v_rm2.push_back(0);
	v_rm3.push_back(0);
	v_rm4.push_back(0);

	v_lm1.push_back(0);
	v_lm2.push_back(0);
	v_lm3.push_back(0);
	v_lm4.push_back(0);

	v_rp0.push_back(0);
	v_rp1.push_back(0);
	v_rp2.push_back(0);
	v_rp3.push_back(0);
	v_rp4.push_back(0);

	v_lp1.push_back(0);
	v_lp2.push_back(0);
	v_lp3.push_back(0);
	v_lp4.push_back(0);

  for (size_t i = 0; i < cloud->points.size (); ++i){
	//x_cm=floor(cloud->points[i].x*100);
	y=round(cloud->points[i].y*100);
	//z_cm=floor(cloud->points[i].z*100);
	//v_y.push_back(a[i]); 
	if(y==0.0 && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x <6){
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

if(y==round(0.2*y_r) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x <6){
	//std::cout  <<" cloud->points[i].z:   " << cloud->points[i].z<< std::endl;
		if(cloud->points[i].z> 0)
	v_rp1.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm1.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.4*y_r) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x <6){
		if(cloud->points[i].z> 0)
	v_rp2.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm2.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.6*y_r) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x <6){
		if(cloud->points[i].z> 0)
	v_rp3.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm3.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.8*y_r) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x < 6){
		if(cloud->points[i].z> 0)
	v_rp4.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_rm4.push_back(round(cloud->points[i].z*100));
		}


if(y==round(0.2*y_l) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x < 6){
		if(cloud->points[i].z> 0)
	v_lp1.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm1.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.4*y_l) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x < 6){
		if(cloud->points[i].z> 0)
	v_lp2.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm2.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.6*y_l) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x < 6){
		if(cloud->points[i].z> 0)
	v_lp3.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm3.push_back(round(cloud->points[i].z*100));
		}

if(y==round(0.8*y_l) && fabs(cloud->points[i].z) >0.2 && cloud->points[i].x < 6){
		if(cloud->points[i].z> 0)
	v_lp4.push_back(round(cloud->points[i].z*100));
		else if(cloud->points[i].z< 0)
	v_lm4.push_back(round(cloud->points[i].z*100));
	 //   std::cout << "    " << cloud->points[i].x
          //   << " "    << cloud->points[i].y
          //   << " "    << cloud->points[i].z << std::endl;
		}


}

		rp0=majorityElement(v_rp0);
		rm0=majorityElement(v_rm0);

		rp1=majorityElement(v_rp1);
		rm1=majorityElement(v_rm1);
		lp1=majorityElement(v_lp1);
		lm1=majorityElement(v_lm1);

		rp2=majorityElement(v_rp2);
		rm2=majorityElement(v_rm2);
		lp2=majorityElement(v_lp2);
		lm2=majorityElement(v_lm2);

		rp3=majorityElement(v_rp3);
		rm3=majorityElement(v_rm3);
		lp3=majorityElement(v_lp3);
		lm3=majorityElement(v_lm3);

		rp4=majorityElement(v_rp4);
		rm4=majorityElement(v_rm4);
		lp4=majorityElement(v_lp4);
		lm4=majorityElement(v_lm4);

	z_r0=(accumulate(rp0.begin(),rp0.end(),0))/rp0.size() + fabs((accumulate(rm0.begin(),rm0.end(),0)))/rm0.size();
	z_r1=(accumulate(rp1.begin(),rp1.end(),0))/rp1.size() + fabs((accumulate(rm1.begin(),rm1.end(),0)))/rm1.size();
	z_r2=(accumulate(rp2.begin(),rp2.end(),0))/rp2.size() + fabs((accumulate(rm2.begin(),rm2.end(),0)))/rm2.size();
	z_r3=(accumulate(rp3.begin(),rp3.end(),0))/rp3.size() + fabs((accumulate(rm3.begin(),rm3.end(),0)))/rm3.size();
	z_r4=(accumulate(rp4.begin(),rp4.end(),0))/rp4.size() + fabs((accumulate(rm4.begin(),rm4.end(),0)))/rm4.size();

	z_l1=(accumulate(lp1.begin(),lp1.end(),0))/lp1.size() + fabs((accumulate(lm1.begin(),lm1.end(),0)))/lm1.size();
	z_l2=(accumulate(lp2.begin(),lp2.end(),0))/lp2.size() + fabs((accumulate(lm2.begin(),lm2.end(),0)))/lm2.size();
	z_l3=(accumulate(lp3.begin(),lp3.end(),0))/lp3.size() + fabs((accumulate(lm3.begin(),lm3.end(),0)))/lm3.size();
	z_l4=(accumulate(lp4.begin(),lp4.end(),0))/lp4.size() + fabs((accumulate(lm4.begin(),lm4.end(),0)))/lm4.size();

//std::cout << 0 <<" (accumulate(lp4.begin(),lp4.end(),0)):   " << (accumulate(lp4.begin(),rp4.end(),0))<< std::endl;
//std::cout << 0 <<" lp4.size():   " <<lp4.size()<< std::endl;
//std::cout << 0 <<" fabs((accumulate(lm4.begin(),lm4.end(),0))):   " << fabs((accumulate(lm4.begin(),lm4.end(),0)))<< std::endl;
//std::cout << 0 <<" lm4.size():   " << lm4.size()<< std::endl;
std::cout  <<"不同位置处的高度:   " << std::endl;
std::cout << 0 <<" z_r0:   " << z_r0<< std::endl;
std::cout << round(0.2*y_r) <<" z_l1:   " << z_r1<< std::endl;
std::cout << round(0.4*y_r) <<" z_l2:   " << z_r2 << std::endl;
std::cout << round(0.6*y_r) <<" z_l3:   " << z_r3<< std::endl;
std::cout << round(0.8*y_r) <<" z_l4:   " << z_r4<< std::endl;

std::cout << -round(0.2*y_l) <<" z_r1:   " << z_l1<< std::endl;
std::cout << -round(0.4*y_l) <<" z_r2:   " << z_l2<< std::endl;
std::cout << -round(0.6*y_l) <<" z_r3:   " << z_l3<< std::endl;
std::cout << -round(0.8*y_l) <<" z_r4:   " << z_l4<< std::endl;


  return 0;

}
