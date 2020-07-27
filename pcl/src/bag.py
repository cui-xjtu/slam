import rosbag
import numpy as np
import sensor_msgs.point_cloud2 as pc2

bag_file = 'test.bag'
bag = rosbag.Bag(bag_file, "r")
bag_data = bag.read_messages('/pandora/sensor/pandora/hesai40/PointCloud2')

for topic, msg, t in bag_data:
    lidar = pc2.read_points(msg)
    points = np.array(list(lidar))
    # 看你想如何处理这些点云

