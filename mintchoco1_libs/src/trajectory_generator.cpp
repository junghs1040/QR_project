#include "mintchoco1_libs/trajectory_generator.hpp"


TrajectoryGenerator::TrajectoryGenerator()
{}
TrajectoryGenerator::~TrajectoryGenerator()
{}

std::vector<double> TrajectoryGenerator::sinWaveSwingTrajectory(double time)
{
    double duration;
    double time_ = time;
    double x,y,z;
    std::vector <double> start_point = {1.0,2.0,3.0};
    std::vector <double> end_point = {1.0,2.0,3.0};
    std::vector <double> position_info;

    double xs = start_point[0];
    double ys = start_point[1];
    double zs = start_point[2];

    double xe = end_point[0];
    double ye = end_point[1];
    double ze = end_point[2];

    x = xs + (time_/duration)*(xe-xs);
    y = ys + (time_/duration)*(ye-ys);
    z = zs + (time_/duration)*(ze-zs);

    return position_info = {x,y,z};


}

std::vector<double> TrajectoryGenerator::straightLineStanceTrajectory(double time, double duration)
{
    double duration_ = duration;
    double time_ = time;
    double x,y,z;
    std::vector <double> start_point = {1.0,2.0,3.0};
    std::vector <double> end_point = {1.0,2.0,3.0};
    std::vector <double> position_info;

    double xs = start_point[0];
    double ys = start_point[1];
    double zs = start_point[2];

    double xe = end_point[0];
    double ye = end_point[1];
    double ze = end_point[2];

    x = xs + (time_/duration_)*(xe-xs);
    y = ys + (time_/duration_)*(ye-ys);
    z = zs + (time_/duration_)*(ze-zs);

    return position_info = {x,y,z};
}

std::vector<double> TrajectoryGenerator::BezierWaveSwingTrajectory(double time)
{
    double time_ = time;
    double start_point;
    double end_point;
}

std::vector<double> TrajectoryGenerator::sinWaveStanceTrajectory(double time)
{
    double time_ = time;
    double start_point;
    double end_point;
}