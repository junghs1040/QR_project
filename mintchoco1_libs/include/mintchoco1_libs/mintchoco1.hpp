#ifndef MINTCHOCO1_H_
#define MINTCHOCO1_H_

#include "gait_scheduler.hpp"
#include "kinematics.hpp"
#include "trajectory_generator.hpp"
#include "ros/ros.h"
#include "urdf/model.h"

#include <sensor_msgs/JointState.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

namespace mintchoco1 
{
class Mintchoco1
{
    public:
        Mintchoco1();       // constructor
        ~Mintchoco1();      // destructor
        void publishJoints(float target_joint_position[12]);
        void controlLoop();
        std::vector<std::string> joint_names_;

    
    private:
        ros::NodeHandle node_handle_;
        ros::NodeHandle priv_node_handle_;
        ros::Publisher joint_command_publisher;
        kinematics::Kinematics kinematics_;
        trajectory_generator::TrajectoryGenerator trajectory_generator_;

};
}

#endif