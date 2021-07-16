/* Author : Hwan-Seok Jung , <Mintchoco Jelly Robotics Lab> */

#include "mintchoco1_controller/mintchoco1_controller.hpp"

using namespace mintchoco1_controller;

Mintchoco1Controller::Mintchoco1Controller()
: node_handle_(""),
  priv_node_handle_("")
{
    
    initPublisher();
    initSubscriber();
    initServer();
}


int main(int argc, char **argv)
{
    ros::init(argc,argv,"mintcoco1_controller");

    while (ros::ok())
    {
        ros::spinOnce();
        //loop_rate.sleep();
    }
    return 0;
}