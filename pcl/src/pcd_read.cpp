#include <iostream>              //标准C++库中的输入输出的头文件
#include <pcl/io/pcd_io.h>       //PCD读写类相关的头文件
#include <pcl/point_types.h>     //PCL中支持的点类型的头文件
#include <vector>  
#include <algorithm>  
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
   int i,j,maxCount=0,index=0,nCount=0;
    int n;
   for(i=0;i<n;i++)           //双循环记数
    {
        for(j=0;j<n;j++)
        {
            if(nums[j]==nums[i])
                nCount++;
        }

        if(nCount>maxCount)
        {
            maxCount=nCount;
            index=i;
        }

        nCount=0;
    }
		return nums[index];
	}
};

int main (int argc, char** argv)
{ 
vector<int> vr;
vector<int> vl;
double x=0.0;
double y=0.0;
int y_r=0;
int y_l=0;
double x_rp0=0.0,x_rm0=0.0,x_rp1=0.0,x_rm1=0.0,x_rp2=0.0,x_rm2=0.0,x_rp3=0.0,x_rm3=0.0,x_rp4=0.0,x_rm4=0.0;
double x_lp1=0.0,x_lm1=0.0,x_lp2=0.0,x_lm2=0.0,x_lp3=0.0,x_lm3=0.0,x_lp4=0.0,x_lm4=0.0;
int count_rp0=0,count_rm0=0,count_rp1=0,count_rm1=0,count_rp2=0,count_rm2=0,count_rp3=0,count_rm3=0,count_rp4=0,count_rm4=0;
int count_lp1=0,count_lm1=0,count_lp2=0,count_lm2=0,count_lp3=0,count_lm3=0,count_lp4=0,count_lm4=0;
double z_rp0=0.0,z_rm0=0.0, z_rp1=0.0,z_rm1=0.0, z_rp2=0.0,z_rm2=0.0, z_rp3=0.0,z_rm3=0.0, z_rp4=0.0,z_rm4=0.0;
double z_lp1=0.0,z_lm1=0.0, z_lp2=0.0,z_lm2=0.0, z_lp3=0.0,z_lm3=0.0, z_lp4=0.0,z_lm4=0.0;
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

	if(y==0.0 && fabs(cloud->points[i].z) >0.25){
		if(cloud->points[i].z> 0){
		z_rp0=round(cloud->points[i].z*100)+x_rp0;
		x_rp0=z_rp0;
		count_rp0=count_rp0+1;
		std::cout <<" cloud->points[i].z:   " <<round(cloud->points[i].z*100)<< std::endl;
		std::cout <<" z_rp0:   " <<z_rp0<< std::endl;
		std::cout  <<" count_rp0:   " <<count_rp0<< std::endl;
		}
		else if(cloud->points[i].z< 0){
		std::cout  <<" cloud->points[i].z:   " <<round(cloud->points[i].z*100)<< std::endl;
		z_rm0=round(cloud->points[i].z*100)+x_rm0;
		x_rm0=z_rm0;
std::cout <<" z_rm0:   " <<z_rm0<< std::endl;
		count_rm0=count_rm0+1;
std::cout  <<" count_rm0:   " <<count_rm0<< std::endl;
		}
	}
	if(y==round(0.2*y_r) && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_rp1=round(cloud->points[i].z*100)+x_rp1;
		x_rp1=z_rp1;
		count_rp1=count_rp1+1;
		}
		else if(cloud->points[i].z< 0){
		z_rm1=round(cloud->points[i].z*100)+x_rm1;
		x_rm1=z_rm1;
		count_rm1=count_rm1+1;
		}
	}
	if(y==round(0.4*y_r)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_rp2=round(cloud->points[i].z*100)+x_rp2;
		x_rp2=z_rp2;
		count_rp2=count_rp2+1;
		}
		else if(cloud->points[i].z< 0){
		z_rm2=round(cloud->points[i].z*100)+x_rm2;
		x_rm2=z_rm2;
		count_rm2=count_rm2+1;
		}
	}
	if(y==round(0.6*y_r)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_rp3=round(cloud->points[i].z*100)+x_rp3;
		x_rp3=z_rp3;
		count_rp3=count_rp3+1;
		}
		else if(cloud->points[i].z< 0){
		z_rm3=round(cloud->points[i].z*100)+x_rm3;
		x_rm3=z_rm3;
		count_rm3=count_rm3+1;
		}
	}
	if(y==round(0.8*y_r)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_rp4=round(cloud->points[i].z*100)+x_rp4;
		x_rp4=z_rp4;
		count_rp4=count_rp4+1;
		}
		else if(cloud->points[i].z< 0){
		z_rm4=round(cloud->points[i].z*100)+x_rm4;
		x_rm4=z_rm4;
		count_rm4=count_rm4+1;
		}
	}
	if(y==round(0.2*y_l)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_lp1=round(cloud->points[i].z*100)+x_lp1;
		x_lp1=z_lp1;
		count_lp1=count_lp1+1;
		}
		else if(cloud->points[i].z< 0){
		z_lm1=round(cloud->points[i].z*100)+x_lm1;
		x_lm1=z_lm1;
		count_lm1=count_lm1+1;
		}
	}
	if(y==round(0.4*y_l)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_lp2=round(cloud->points[i].z*100)+x_lp2;
		x_lp2=z_lp2;
		count_lp2=count_lp2+1;
		}
		else if(cloud->points[i].z< 0){
		z_lm2=round(cloud->points[i].z*100)+x_lm2;
		x_lm2=z_lm2;
		count_lm2=count_lm2+1;
		}
	}
	if(y==round(0.6*y_l)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_lp3=round(cloud->points[i].z*100)+x_lp3;
		x_lp3=z_lp3;
		count_lp3=count_lp3+1;
		}
		else if(cloud->points[i].z< 0){
		z_lm3=round(cloud->points[i].z*100)+x_lm3;
		x_lm3=z_lm3;
		count_lm3=count_lm3+1;
		}
	}
	if(y==round(0.8*y_l)  && fabs(cloud->points[i].z) >0.15){
		if(cloud->points[i].z> 0){
		z_lp4=round(cloud->points[i].z*100)+x_lp4;
		x_lp4=z_lp4;
		count_lp4=count_lp4+1;
		}
		else if(cloud->points[i].z< 0){
		z_lm4=round(cloud->points[i].z*100)+x_lm4;
		x_lm4=z_lm4;
		count_lm4=count_lm4+1;
		}
	}
    //std::cout << "    " << cloud->points[i].x
    //          << " "    << cloud->points[i].y
     //         << " "    << cloud->points[i].z << std::endl;

}


//std::cout << 0 <<" z_r0:   " << (z_rp0/count_rp0)+(fabs(z_rm0)/count_rm0)<< std::endl;

std::cout << 0<<" z_r0:   " << (z_rp0/count_rp0)<< std::endl;
std::cout << round(0.2*y_r) <<" z_r1:   " << (z_rp1/count_rp1)<< std::endl;
std::cout << round(0.4*y_r) <<" z_r2:   " << (z_rp2/count_rp2) << std::endl;
std::cout << round(0.6*y_r) <<" z_r3:   " << (z_rp3/count_rp3)<< std::endl;
std::cout << round(0.8*y_r) <<" z_r4:   " << (z_rp4/count_rp4)<< std::endl;

std::cout << round(0.2*y_l) <<" z_l1:   " <<  (z_lp1/count_lp1)<< std::endl;
std::cout << round(0.4*y_l) <<" z_l2:   " <<  (z_lp2/count_lp2)<< std::endl;
std::cout << round(0.6*y_l) <<" z_l3:   " <<  (z_lp3/count_lp3)<< std::endl;
std::cout << round(0.8*y_l) <<" z_l4:   " <<  (z_lp4/count_lp4)<< std::endl;
  return 0;
}
