#include <iostream>
#include <vector>
#include <string>
#include "mintchoco1_libs/kinematics.hpp"

std::vector<double> Kinematics::solveInverseKinematics(std::vector<double> position_info)
{
	std::vector<double> joint_state;
	double theta1, theta2, theta3;
	double link1 = 78.96;
	double link2 = 187.96;
	double link3 = 200.00;

	double x = position_info[0];
	double y = position_info[1];
	double z = position_info[2];

	double F = sqrt(z*z + y * y - 78.0 * 78.0);
	double G = 12.3 + sqrt(z*z + y * y - 78.0 * 78.0);
	double H = sqrt(G*G + x * x);
    double alpa = asin(x/(sqrt(x*x+G*G)));

	theta1 = atan2(F, 78.0) - atan2(abs(z), abs(y));

	double D = -(H*H-link2*link2-link3*link3)/(2*link2*link3);

	theta3 = acos(D) - 3.14/2 - 0.1603;
	double alpha, beta;
	//alpha = atan2(x, G);
    alpha = atan2(G, x);
	beta = atan(link3*sin(3.14 / 2 - 0.1603 - theta3) / (link2 + link3 * cos(3.14 / 2 - 0.1603 - theta3)));
    
	//theta2 = 3.14 /2  - alpha - beta - 0.1603;
    theta2 = 3.14 - alpha - beta - 0.1603;

	joint_state_ = { theta1, theta2, theta3 };

    return joint_state_;
}