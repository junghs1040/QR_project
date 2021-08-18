#include "mintchoco1.hpp"
using namespace mintchoco1;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mintchoco1");
    
    ros::NodeHandle nh("");
    ros::NodeHandle nh_priv("~");
    
    
    Mintchoco1 minco(&nh, &nh_priv);

    ros::spin();
    return 0;
}