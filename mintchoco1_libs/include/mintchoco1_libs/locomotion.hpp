#ifndef LOCOMOTION_H_
#define LOCOMOTION_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Eigen/Dense>
#include "kinematics.hpp"
#include "ros/ros.h"



class Locomotion
{
    public:
        Locomotion();       // constructor
        ~Locomotion();      // destructor
        std::vector<float> stanceState(int order);
        std::vector<float> walkingTrot(int order);

    private:
        Kinematics kinematics;



};

#endif