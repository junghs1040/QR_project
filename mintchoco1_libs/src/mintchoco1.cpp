#include "mintchoco1_libs/mintchoco1.hpp"


Mintchoco1::Mintchoco1(ros::NodeHandle *nh, ros::NodeHandle *nh_priv)
{
    double loop_rate = 100.0;
    order = 0;
    std::string joint_control_topic = "joint_group_position_controller/command";
    //*number received by controller check and choice the walking pattern
    //*store the trajectory information and publish that information
    
    teleop_input_subscriber = nh->subscribe("mintchoco1_msg", 1000, &Mintchoco1::msgCallback, this);
    //Joint trajectory publisher to  Gazebo
    joint_command_publisher = nh_priv->advertise<trajectory_msgs::JointTrajectory>("joint_group_position_controller/command", 1);

    joint_state_publisher = nh->advertise<sensor_msgs::JointState>("joint_states", 1);
    //TODO : contact info publisher
    //contact_info_publisher = nh->advertise<champ_msgs::ContactsStamped>("foot_contacts", 1);

    loop_timer =nh_priv->createTimer(ros::Duration(1/loop_rate), &Mintchoco1::controlLoop, this);
    //if (order ==1)
    //{
    //  loop_timer =nh_priv->createTimer(ros::Duration(3.0), &Mintchoco1::controlLoop, this);
    //}

}

Mintchoco1::~Mintchoco1()
{}

void Mintchoco1::controlLoop(const ros::TimerEvent& event)
{
  std::vector<float> target_joint_position;
    if (order == 0 || 5 || 6)
    {
      
      target_joint_position = locomotion_controller.stanceState(order, height_order);
    }
    if (order == 1)
    {
      target_joint_position = locomotion_controller.walkingTrot(order);
    }

    publishJoints(target_joint_position);
    //ROS_INFO("ok");
}

void Mintchoco1::msgCallback(const mintchoco1_msgs::Mintchoco1Control::ConstPtr& msg)
{
  float x = msg->linear[0];
  float y = msg->linear[1];
  float z = msg->linear[2];
  ROS_INFO("hh");
  ROS_INFO("%f,%f,%f", x,y,z);
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
  if ( order == 0 || 5 || 6)
  {
    base_control = true;
    ROS_INFO("base_control = true");
  }
  if ( order == 1 || 2 || 3 || 4)
  {
    base_control = false;
    ROS_INFO("base_control = false");
  }

}

void Mintchoco1::publishJoints(std::vector<float> target_joint_position)
{
    trajectory_msgs::JointTrajectory joints_cmd_msg;
    joints_cmd_msg.header.stamp = ros::Time::now();
    joints_cmd_msg.joint_names = joint_names_;
    
    trajectory_msgs::JointTrajectoryPoint point;
    point.positions.resize(12);
    if (base_control)
    {
      point.time_from_start = ros::Duration(2.0);
    }
    else 
      point.time_from_start = ros::Duration(1.0/100.0);

    for (int i=0; i<12; i++)
    {
        point.positions[i] = target_joint_position[i];
    }
    
    joints_cmd_msg.points.push_back(point);
    joint_command_publisher.publish(joints_cmd_msg);
}



