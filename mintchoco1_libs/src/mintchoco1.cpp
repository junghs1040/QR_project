#include "mintchoco1_libs/mintchoco1.hpp"

using namespace mintchoco1;

Mintchoco1::Mintchoco1()
    :node_handle_(""),
     priv_node_handle_("~")
{
    std::string joint_control_topic = "joint_group_position_controller/command";
    //number received by controller check and choice the walking pattern
    //store the trajectory information and publish that information
    
    joint_command_publisher = node_handle_.advertise<trajectory_msgs::JointTrajectory>("joint_trajectory", 100);
    
    joint_names_ = {"LF_joint1","LF_joint2","LF_joint3","LB_joint1","LB_joint2","LB_joint3",
                    "RF_joint1","RF_joint2","RF_joint3","RB_joint1","RB_joint2","RB_joint3",};
    //TODO use the urdf.h source file to get the joint name form URDF
}

Mintchoco1::~Mintchoco1()
{}

void Mintchoco1::controlLoop()
{
    std::vector<double> target_joint_position;
    float target_foot_position[4];
    trajectory_generator_.something();

    kinematics_.solveGeometricInverseKinematics(target_joint_position);

}

void Mintchoco1::publishJoints(float target_joint_position[12])
{
    trajectory_msgs::JointTrajectory joints_cmd_msg;
    joints_cmd_msg.header.stamp = ros::Time::now();
    joints_cmd_msg.joint_names = joint_names_;
    
    trajectory_msgs::JointTrajectoryPoint point;
    point.positions.resize(12);

    point.time_from_start = ros::Duration(1.0/60.0);
    for (int i=0; i<12; i++)
    {
        point.positions[i] = target_joint_position[i];
    }

    joints_cmd_msg.points.push_back(point);
    joint_command_publisher.publish(joints_cmd_msg);
}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "mintchoco1");
    Mintchoco1 mintcho;
    trajectory_generator::TrajectoryGenerator tra;
    kinematics::Kinematics invk;

    ROS_INFO("For now we can publish quadruped robot leg's joint trajectory! ");

    double t = ros::Time::now().toSec();
    double ho;
    std::string joint_control_topic = "joint_group_position_controller/command";
    
    std::vector<double> position_info = tra.straightLineStanceTrajectory(t,ho);
    std::vector<double> joint_info = invk.solveGeometricInverseKinematics(position_info);
    
    // publiher setting - if we service call at the controller
    // and callback function called this node to publish joint trajectory

}