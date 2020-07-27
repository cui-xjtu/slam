#include <iostream>              //标准C++库中的输入输出的头文件
#include <pcl/io/pcd_io.h>       //PCD读写类相关的头文件
#include <pcl/point_types.h>     //PCL中支持的点类型的头文件

int
main (int argc, char** argv)
{ 
   //创建一个PointCloud<pcl::PointXYZ>    boost共享指针并进行实例化
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  
  //打开点云文件
  if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[1], *cloud) == -1) 
  {
    PCL_ERROR ("Couldn't read file.pcd.pcd \n");
    return (-1);
  }
//默认就是而二进制块读取转换为模块化的PointCLoud格式里pcl::PointXYZ作为点类型  然后打印出来
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  for (size_t i = 0; i < cloud->points.size (); ++i)
    std::cout << "    " << cloud->points[i].x
              << " "    << cloud->points[i].y
              << " "    << cloud->points[i].z << std::endl;

  return (0);
}
