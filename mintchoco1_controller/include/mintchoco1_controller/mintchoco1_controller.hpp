/* Author : Hwan-Seok Jung , <Mintchoco Jelly Robotics Lab> */

#ifndef MINTCHOCO1_CONTROLLER_H_
#define MINTCHOCO1_CONTROLLER_H_

#include <ros/ros.h>

namespace mintchoco1_controller
{
class Mintchoco1Controller
{
    public:
        Mintchoco1Controller();
        ~Mintchoco1Controller();

    private:
        /********************************************
        ** ROS NodeHandle
        *********************************************/
        ros::NodeHandle node_handle_;
        ros::NodeHandle priv_node_handle_;

        /********************************************
        ** ROS Parameters
        *********************************************/

        /********************************************
        ** ROS NodeHandle
        *********************************************/

        /********************************************
        ** Init Functions
        *********************************************/
        void initPublisher();
        void initSubscriber();
        void initServer();
        
        /********************************************
        ** ROS Servers and Callback Functions
        *********************************************/
        


};
      
    
}

#endif //MINTCHOCO1_CONTROLLER_H_