#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Eigen/Dense>


class Kinematics
{
    public:
        Kinematics();       // constructor
        ~Kinematics();      // destructor

        std::vector<double> joint_state_;
        std::vector<double> solveInverseKinematics(std::vector<double> position_info);


    private:



};


#endif