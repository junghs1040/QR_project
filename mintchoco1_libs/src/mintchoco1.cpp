#include "mintchoco1_libs/mintchoco1.hpp"

using namespace mintchoco1;

Mintchoco1::Mintchoco1(ros::NodeHandle *nh, ros::NodeHandle *nh_priv)
{
    double loop_rate = 100.0;
    std::string joint_control_topic = "joint_group_position_controller/command";
    //*number received by controller check and choice the walking pattern
    //*store the trajectory information and publish that information
    
    teleop_input_subscriber = nh->subscribe("cmd_vel", 1000, &Mintchoco1::msgCallback, this);
    //Joint trajectory publisher to  Gazebo
    joint_command_publisher = nh->advertise<trajectory_msgs::JointTrajectory>("joint_trajectory", 100);

    joint_state_publisher = nh->advertise<sensor_msgs::JointState>("joint_states", 1);
    //TODO : contact info publisher
    //contact_info_publisher = nh->advertise<champ_msgs::ContactsStamped>("foot_contacts", 1);

    loop_timer =nh_priv->createTimer(ros::Duration(1/loop_rate), &Mintchoco1::controlLoop,this);

}

Mintchoco1::~Mintchoco1()
{}

void Mintchoco1::controlLoop(const ros::TimerEvent& event)
{
    std::vector<double> target_joint_position;
    std::vector<double> target_foot_position;
    if (order == 0)
    {
      trajectory_generator_.stanceState(target_foot_position);
    }
    kinematics_.solveGeometricInverseKinematics(target_joint_position);

    //publishJoints(target_joint_position)
}

void Mintchoco1::msgCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  float x = msg->linear.x;
  float y = msg->linear.y;
  float z = msg->linear.z;
 
  if ( x > 0 && y == 0 && z == 0 )
    {
      ROS_INFO("go straight");
      order = 1;
    }
  if ( x < 0 && y == 0 && z == 0 )
    {
      ROS_INFO("go back");
      order = 2;
    }
  if ( x == 0 && y == 0 && z == 0 )
    {
      ROS_INFO("stop");
      order = 0;
    }
  if ( x == 0 && y > 0 && z == 0 )
    {
      ROS_INFO("go right");
      order = 3;
    }
  if ( x == 0 && y < 0 && z == 0 )
    {
      ROS_INFO("go left");
      order = 4;
    }
  if ( x == 0 && y == 0 && z > 0 )
    {
      ROS_INFO("go up");
      order = 5;
    }
  if ( x == 0 && y == 0 && z < 0 )
    {
      ROS_INFO("go down");
      order = 6;
    }
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



