/* Author : Hwan-Seok Jung , <Mintchoco Jelly Robotics Lab> */

#ifndef MINTCHOCO1_CONTROLLER_H_
#define MINTCHOCO1_CONTROLLER_H_

#include <ros/ros.h>
#include <std_srvs/Trigger.h>

namespace mintchoco1_controller
{
class Mintchoco1Controller
{
    public:
        Mintchoco1Controller();
        ~Mintchoco1Controller();

    bool moveCommandMsgCallback(std_srvs::Trigger::Request &req,
                               std_srvs::Trigger::Response &res);

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
        ros::ServiceServer move_command_server_;


};
      
    
}

#endif //MINTCHOCO1_CONTROLLER_H_