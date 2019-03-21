#include <iostream>
#include <string>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/common/impl/common.hpp>

int main()
{
    pcl::PointCloud<pcl::PointXYZ> cloud;
    // Generate pointcloud data
    cloud.width = 1000;
    cloud.height = 1;
    cloud.points.resize (cloud.width * cloud.height);

    for (size_t i = 0; i < cloud.points.size (); ++i)
    {
        cloud.points[i].x = 1024.0f * rand () / (RAND_MAX + 1.0f);
        cloud.points[i].y = 1024.0f * rand () / (RAND_MAX + 1.0f);
        cloud.points[i].z = 1024.0f * rand () / (RAND_MAX + 1.0f);
    }
    pcl::PointXYZ MinPoint, MaxPoint;
    pcl::getMinMax3D(cloud, MinPoint, MaxPoint);
    
    std::cout << "Min x: " << std::to_string(MinPoint.x) << std::endl;
    std::cout << "Min y: " << std::to_string(MinPoint.y) << std::endl;
    std::cout << "Min z: " << std::to_string(MinPoint.z) << std::endl;
    std::cout << "Max x: " << std::to_string(MaxPoint.x) << std::endl;
    std::cout << "Max y: " << std::to_string(MaxPoint.y) << std::endl;
    std::cout << "Max z: " << std::to_string(MaxPoint.z) << std::endl;
}
