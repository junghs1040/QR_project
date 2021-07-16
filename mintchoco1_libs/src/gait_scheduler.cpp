#include "mintchoco1_libs/gait_scheduler.hpp"

using namespace gait_scheduler;

GaitScheduler::GaitScheduler()
{}

GaitScheduler::~GaitScheduler()
{}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mintchoco1");
    GaitScheduler gait;
    trajectory_generator::TrajectoryGenerator tra;

    ROS_INFO("For now we can publish quadruped robot leg's joint trajectory! ");

    double t = ros::Time::now().toSec();
    double ho;

    std::vector<double> position_info = tra.straightLineStanceTrajectory(t,ho);
    std::vector<double> d;
    // publiher setting - if we service call at the controller
    // and callback function called this node to publish joint trajectory

}