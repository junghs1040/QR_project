#ifndef GAIT_SCHEDULER_H_
#define GAIT_SCHEDULER_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Eigen/Dense>
#include <ros/ros.h>
#include "kinematics.hpp"
#include "trajectory_generator.hpp"

namespace gait_scheduler
{

class GaitScheduler
{
    public:
      GaitScheduler();
      ~GaitScheduler();

      std::vector<double> walkingTrot();




    private:

};

}


#endif