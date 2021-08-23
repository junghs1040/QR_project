#ifndef LOCOMOTION_H_
#define LOCOMOTION_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Eigen/Dense>


class Locomotion
{
    public:
        Locomotion();       // constructor
        ~Locomotion();      // destructor

        std::vector<double> stanceState(int order);

    private:



};

#endif