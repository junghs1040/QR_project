#ifndef MINTCHOCO1_H_
#define MINTCHOCO1_H_

#include "kinematics.hpp"
#include "trajectory_generator.hpp"
#include "locomotion.hpp"
#include "ros/ros.h"
#include "urdf/model.h"
#include "std_msgs/String.h"
#include <iostream>
#include "mintchoco1_msgs/Mintchoco1Control.h"
#include <sensor_msgs/JointState.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>


class Mintchoco1
{
    public:
        Mintchoco1(ros::NodeHandle *nh, ros::NodeHandle *nh_priv);       // constructor
        ~Mintchoco1();      // destructor
        void publishJoints(std::vector<float> target_joint_position);
        void controlLoop(const ros::TimerEvent& event);
        void msgCallback(const mintchoco1_msgs::Mintchoco1Control::ConstPtr& msg);
        std::vector<double> target_joint_position;
        std::vector<std::string> joint_names_ = {"LF_joint1","LF_joint2","LF_joint3", 
                                                 "LB_joint1","LB_joint2","LB_joint3",
                                                 "RF_joint1","RF_joint2","RF_joint3",
                                                 "RB_joint1","RB_joint2","RB_joint3", };

    
    private:
        ros::Timer loop_timer;
        ros::Subscriber teleop_input_subscriber;
        ros::Publisher joint_command_publisher;
        ros::Publisher joint_state_publisher;
        ros::Publisher contact_info_publisher;
        
        Kinematics kinematics_;
        TrajectoryGenerator trajectory_generator_;
        Locomotion locomotion_controller;
        int order;
        bool base_control = false;
        // stop - 0 , go saright - 1, go back - 2, go right -3, go left - 4, go up - 5, go down - 6

};


#endif