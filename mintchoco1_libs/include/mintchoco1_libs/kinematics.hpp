#ifndef KINEMATICS_H_
#define KINEMATICS_H_

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
        std::vector<double> solveGeometricInverseKinematics(std::vector<double> position_info);


    private:



};


#endif