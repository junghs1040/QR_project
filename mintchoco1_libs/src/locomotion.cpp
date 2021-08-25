#include "mintchoco1_libs/locomotion.hpp"

Locomotion::Locomotion()
{}
Locomotion::~Locomotion()
{}
std::vector<float> Locomotion::stanceState(int order)
{
    std::vector <float> target_joint_position;
    std::vector <float> LF;
    std::vector <float> LB;
    std::vector <float> RF;
    std::vector <float> RB;

    if(order == 0)
    {
        LF = kinematics.solveGeometricInverseKinematics({0, 78.00, -215.7});
        LB = kinematics.solveGeometricInverseKinematics({0, 78.00, -215.7});
        RF = kinematics.solveGeometricInverseKinematics({0, 78.00, -215.7});
        RB = kinematics.solveGeometricInverseKinematics({0, 78.00, -215.7});
       //TODO solve inversekinematics and find the standard state at each legs
    }
    if(order == 5)
    {
        LF = kinematics.solveGeometricInverseKinematics({0, 78.00, -320.0});
        LB = kinematics.solveGeometricInverseKinematics({0, 78.00, -320.0});
        RF = kinematics.solveGeometricInverseKinematics({0, 78.00, -320.0});
        RB = kinematics.solveGeometricInverseKinematics({0, 78.00, -320.0});
        //TODO solve inversekinematics and find the go up state
    }
    if(order == 6)
    {
        LF = kinematics.solveGeometricInverseKinematics({0, 78.00, -120.0});
        LB = kinematics.solveGeometricInverseKinematics({0, 78.00, -120.0});
        RF = kinematics.solveGeometricInverseKinematics({0, 78.00, -120.0});
        RB = kinematics.solveGeometricInverseKinematics({0, 78.00, -120.0});
        //TODO solve inversekinematics and find the go down state
    }
    //TODO - Call the trajectory function for each leg

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
    ROS_INFO("LF : %f,%f,%f ", LF[0],LF[1],LF[2]);
    ROS_INFO("LB : %f,%f,%f ", LB[0],LB[1],LB[2]);
    ROS_INFO("RF : %f,%f,%f ", RF[0],RF[1],RF[2]);
    ROS_INFO("RB : %f,%f,%f ", RB[0],RB[1],RB[2]);
    return target_joint_position;
}