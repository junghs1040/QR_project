#ifndef MINTCHOCO1_H_
#define MINTCHOCO1_H_

#include "gait_scheduler.hpp"
#include "kinematics.hpp"
#include "trajectory_generator.hpp"
#include "ros/ros.h"
#include "urdf/model.h"
#include "std_msgs/String.h"

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/JointState.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

namespace mintchoco1 
{
class Mintchoco1
{
    public:
        Mintchoco1(ros::NodeHandle *nh, ros::NodeHandle *nh_priv);       // constructor
        ~Mintchoco1();      // destructor
        void publishJoints(float target_joint_position[12]);
        void controlLoop(const ros::TimerEvent& event);
        void msgCallback(const geometry_msgs::Twist::ConstPtr& msg);
        std::vector<std::string> joint_names_;

    
    private:
        ros::Timer loop_timer;
        ros::Subscriber teleop_input_subscriber;
        ros::Publisher joint_command_publisher;
        ros::Publisher joint_state_publisher;
        ros::Publisher contact_info_publisher;
        kinematics::Kinematics kinematics_;
        trajectory_generator::TrajectoryGenerator trajectory_generator_;

        int order = 0;
        // stop - 0 , go saright - 1, go back - 2, go right -3, go left - 4, go up - 5, go down - 6

};
}

#endif