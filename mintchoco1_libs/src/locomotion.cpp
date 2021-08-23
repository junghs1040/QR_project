#include "mintchoco1_libs/locomotion.hpp"

Locomotion::Locomotion()
{}
Locomotion::~Locomotion()
{}
std::vector<double> Locomotion::stanceState(int order)
{
    if(order == 0)
    {
       //TODO solve inversekinematics and find the standard state
    }
    if(order == 5)
    {
        //TODO solve inversekinematics and find the go up state
    }
    if(order == 6)
    {
        //TODO solve inversekinematics and find the go down state
    }
    //TODO - Call the trajectory function for each leg
}