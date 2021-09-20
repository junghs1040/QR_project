#include "mintchoco1_libs/locomotion.hpp"

Locomotion::Locomotion()
{}
Locomotion::~Locomotion()
{}
std::vector<float> Locomotion::stanceState(int order, int height_order)
{
    std::vector <float> target_joint_position;
    std::vector <float> LF;
    std::vector <float> LB;
    std::vector <float> RF;
    std::vector <float> RB;

    if(order == 0)
    {
        z_position =-215.0;
    }
    if(order == 5)
    {
        z_position -= 1.0;
        if (z_position <= -320)
        {
            z_position = -320;
        }
    }
    if(order == 6)
    {
        z_position += 1.0;
        if (z_position >= -120)
        {
            z_position = -120;
        }
    }
    //TODO - Call the trajectory function for each leg


    LF = kinematics.solveGeometricInverseKinematics({10, 78.00, z_position});
    LB = kinematics.solveGeometricInverseKinematics({0, 78.00, z_position});
    RF = kinematics.solveGeometricInverseKinematics({10, 78.00, z_position});
    RB = kinematics.solveGeometricInverseKinematics({0, 78.00, z_position});

    for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(LF[i]);
    }
        for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(LB[i]);
    }
        for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(RF[i]);
    }
        for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(RB[i]);
    }
    //ROS_INFO("LF : %f,%f,%f ", LF[0],LF[1],LF[2]);
    //ROS_INFO("LB : %f,%f,%f ", LB[0],LB[1],LB[2]);
    //ROS_INFO("RF : %f,%f,%f ", RF[0],RF[1],RF[2]);
    //ROS_INFO("RB : %f,%f,%f ", RB[0],RB[1],RB[2]);
    return target_joint_position;
}

std::vector<float> Locomotion::walkingTrot(int order)
{
    std::vector <float> target_joint_position;
    std::vector <float> LF;
    std::vector <float> LB;
    std::vector <float> RF;
    std::vector <float> RB;


    for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(LF[i]);
    }
        for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(LB[i]);
    }
        for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(RF[i]);
    }
        for (int i =0; i<3; i++)
    {
        target_joint_position.push_back(RB[i]);
    }
    return target_joint_position;
}