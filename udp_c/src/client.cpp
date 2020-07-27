#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/socketvar.h>
#include <arpa/inet.h>
#include <iostream>

#include <sstream>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>


#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

using namespace std;
#define SERVER_PORT     4001
#define MAX_MSG_SIZE    1024

ros::Publisher scan_pub;

void udps_respon(int sockfd)
{
        struct sockaddr_in addr;
        //int     n;
        int i;
        int j;
        int flag =60;
	ros::NodeHandle n;
        scan_pub = n.advertise<sensor_msgs::LaserScan>("scan1", 60);
        unsigned int num_readings = 274;
        double laser_frequency = 60;
        double ranges[num_readings];
        double intensities[num_readings];
//	ros::Rate r(1.0);

//       int32_t recvBuf2[36] = {0};
//        float saveBuf[3][25];
//        int32_t saveBufBase[36] = {0};
//        int32_t saveBufBaseFlg = 0;

	socklen_t addrlen;
 //       char    msg[MAX_MSG_SIZE];
        unsigned char recvBuf[579];
        struct U921Packet
        {
            unsigned short int SIZE;//0-1
            unsigned short int CMD;//2-3
            unsigned int ID;//4-7
            unsigned short int CNTR;//8-9sendSktID
        //    unsigned char CVEH[14];//10-23 此项传感器出厂时默认禁止recvfrom
            unsigned char MDI[549];//24-572
        //    unsigned char PLANE;//24
        //    unsigned short int MDI[274];//25-572
            unsigned char CHK[2];//573-574
            unsigned char SYNC[4];//575-578
        };
        union U921PacketUnion
        {
            U921Packet data;
            unsigned char recvBuf[579];
        };
        U921PacketUnion u921Packet;
        char tmp[256*4];
		ROS_INFO("BBB");
        while(1)
        {
			//ROS_INFO("BUG1");
            recvfrom(sockfd, u921Packet.recvBuf, sizeof(u921Packet.recvBuf), 0, (struct sockaddr*)&addr, &addrlen);  //recvfrom是拥塞函数，没有数据就一直拥塞

           // j = 0;
           // j +=  sprintf(tmp+j,"message length =%d,SYNC=%02x%02x%02x%02x,ID=%x,counter=%d,",
                          //u921Packet.data.SIZE,u921Packet.data.SYNC[0],u921Packet.data.SYNC[1],u921Packet.data.SYNC[2],u921Packet.data.SYNC[3],u921Packet.data.ID,u921Packet.data.CNTR);

         //  for(i=0;i<274;i+=27){//274
//    //        for(i=40;i<150;i+=27/3){//274//201
          //      j +=  sprintf(tmp+j,"D%d=%d ", i,u921Packet.data.MDI[i*2+1]+u921Packet.data.MDI[i*2+2]*256);

         //  }
//
          // if(u921Packet.data.CNTR%flag == 0){
           //           cout <<tmp<<endl;
           // }
		//ROS_INFO("BUG2");
		//ROS_INFO("CCC,%d",u921Packet.data.MDI[21]+u921Packet.data.MDI[22]*256);
            for(unsigned int i = 0; i < num_readings; ++i){
                ranges[i] = (u921Packet.data.MDI[i*2+1]+u921Packet.data.MDI[i*2+2]*256)/1000.0;
                intensities[i] = 300;
           		}
			
         ros::Time scan_time = ros::Time::now();
         sensor_msgs::LaserScan scan;
         scan.header.stamp = scan_time;
         scan.header.frame_id = "laser1_link";
         scan.angle_min = -0.837758;
         scan.angle_max = 0.837758;
         scan.angle_increment = 1.675516 / num_readings;
         scan.time_increment = (1 / laser_frequency) / (num_readings);
         scan.range_min = 0.0;
         scan.range_max = 60.0;
 
        scan.ranges.resize(num_readings);
        scan.intensities.resize(num_readings);
         for(unsigned int i = 7; i < num_readings; ++i){
                   scan.ranges[i] = ranges[i];
                  scan.intensities[i] = intensities[i];
         }
 		//ROS_INFO("DDD");
        scan_pub.publish(scan);
    	//++count;
   	// r.sleep();
            //packetOneFile.write(reinterpret_cast<char *>(u921Packet.recvBuf) ,sizeof(u921Packet.recvBuf ));
            continue;

        }
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "laser_scan_publisher");
        //ros::NodeHandle n;
	ROS_INFO("AAA");
        int sockfd;
        struct sockaddr_in      addr;
        
        sockfd=socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd<0)
        {
                fprintf(stderr,"Socket Error:%s\n",strerror(errno));
                exit(1);
        }
        bzero(&addr,sizeof(struct sockaddr_in));
        addr.sin_family=AF_INET;
        addr.sin_addr.s_addr=htonl(INADDR_ANY);
        addr.sin_port=htons(SERVER_PORT);
        if(bind(sockfd,(struct sockaddr *)&addr,sizeof(addr))<0)
        {
                fprintf(stderr,"Bind Error:%s\n",strerror(errno));
                exit(1);
        }
        //scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 50);
	//unsigned int num_readings = 274;
  	//double laser_frequency = 60;
  	//double ranges[num_readings];
  	//double intensities[num_readings];
	// int count = 0;
        //ros::Rate r(1.0);

//  
        udps_respon(sockfd);
        close(sockfd);
}
