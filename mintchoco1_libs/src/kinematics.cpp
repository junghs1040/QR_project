#include "mintchoco1_libs/kinematics.hpp"



Kinematics::Kinematics()
{}
Kinematics::~Kinematics()
{}

std::vector<float> Kinematics::solveGeometricInverseKinematics(std::vector<double> position_info)
{
	float theta1, theta2, theta3;
	float link1 = 78.96;
	float link2 = 187.96;
	float link3 = 200.00;

	float x = position_info[0];
	float y = position_info[1];
	float z = position_info[2];

	float F = sqrt(z*z + y * y - 78.0 * 78.0);
	float G = 12.3 + sqrt(z*z + y * y - 78.0 * 78.0);
	float H = sqrt(G*G + x * x);
    float alpa = asin(x/(sqrt(x*x+G*G)));

	theta1 = atan2(F, 78.0) - atan2(abs(z), abs(y));

	float D = -(H*H-link2*link2-link3*link3)/(2*link2*link3);

	theta3 = acos(D) - 3.14/2 - 0.1603;
	float alpha, beta;
	//alpha = atan2(x, G);
    alpha = atan2(G, x);
	beta = atan(link3*sin(3.14 / 2 - 0.1603 - theta3) / (link2 + link3 * cos(3.14 / 2 - 0.1603 - theta3)));
    
	//theta2 = 3.14 /2  - alpha - beta - 0.1603;
    theta2 = 3.14 - alpha - beta - 0.1603;

	joint_state_ = { theta1, theta2, theta3 };

    return joint_state_;
}
