#ifndef TRAJECTORY_GENERATOR_H_
#define TRAJECTORY_GENERATOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Eigen/Dense>

namespace trajectory_generator
{

class TrajectoryGenerator
{
    public:
        TrajectoryGenerator();
        ~TrajectoryGenerator();

        std::vector<double> stanceState(std::vector<double> position_info);
        std::vector<double> sinWaveSwingTrajectory(double time);
        std::vector<double> straightLineStanceTrajectory(double time, double duration);

        std::vector<double> BezierWaveSwingTrajectory(double time);
        std::vector<double> sinWaveStanceTrajectory(double time);

    private:

};

}


#endif