#include <iostream>
#include <vector>
#include <string>

#include "ros/ros.h"
#include "mintchoco1_libs/mintchoco1.hpp"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "mintchoco1");
    
    ros::NodeHandle nh("");
    ros::NodeHandle nh_priv("~");
    
    
    Mintchoco1 mincho(&nh, &nh_priv);
    ros::spin();
    return 0;
}