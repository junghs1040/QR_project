#include <ros/ros.h>
#include "mintchoco1_msgs/Mintchoco1Control.h"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#include <map>

// Map for movement keys
std::map<char, std::vector<float>> moveBindings
{
  {'w', { 1,  0,  0, 0, 0, 0}},  // GO
  {'a', { 0, -1,  0, 0, 0, 0}}, // LEFT
  {'s', {-1,  0,  0, 0, 0, 0}},  // BACK
  {'d', { 0,  1,  0, 0, 0, 0}}, // RIGHT

  {'t', { 0,  0,  1,  0,  0,  0}},  // UP
  {'b', { 0,  0, -1,  0,  0,  0}},  // DOWN

  {',', { 0,  0, 0,  -1,  0,  0}},  // TURN COUNTER CLOCKWISE  - X-axis
  {'.', { 0,  0, 0,   1,  0,  0}},  // TURN CLOCKWISE - X-axis

  {'<', { 0,  0,  0,  0, -1,  0}},  // TURN COUNTER CLOCKWISE  - Y-axis
  {'>', { 0,  0,  0,  0,  1,  0}},  // TURN CLOCKWISE - Y-axis

  {'q', { 0,  0,  0,  0,  0, -1}},   // TURN COUNTER CLOCKWISE - Z-axis
  {'e', { 0,  0,  0,  0,  0,  1}}   // TURN CLOCKWISE  - Z-axis

 
};

// Map for speed keys
std::map<char, std::vector<float>> gaitControlBindings
{
  {'u', {1}},  // walking gait
  {'z', {0.9, 0.9}},
  {'w', {1.1, 1}},
  {'x', {0.9, 1}},

};

// Reminder message
const char* msg = R"(
Reading from the keyboard and Publishing to Twist!
---------------------------
Moving around :
        w     
   a    s    d
           
Turn around :
---------------------------
   X-axis ["." = CW "," = CCW]
   Y-axis [">" = CW "<" = CCW]
   Z-axis ["q" = CW "e" = CCW]
t : up (+z)
b : down (-z)
anything else : stop

CTRL-C to quit
)";

// Init variables
float num(0.0); // Gait Mode 
//float turn(1.0); // Angular velocity (rad/s)
float x(0), y(0), z(0), x_t(0), y_t(0), z_t(0); // Forward/backward/neutral direction vars
char key(' ');

// For non-blocking keyboard inputs
int getch(void)
{
  int ch;
  struct termios oldt;
  struct termios newt;

  // Store old settings, and copy to new settings
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  // Make required changes and apply the settings
  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_iflag |= IGNBRK;
  newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
  newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newt);

  // Get the current character
  ch = getchar();

  // Reapply old settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}

int main(int argc, char** argv)
{
  // Init ROS node
  ros::init(argc, argv, "mintchoco1_keyboard");
  ros::NodeHandle nh;

  // Init cmd_vel publisher
  ros::Publisher pub = nh.advertise<mintchoco1_msgs::Mintchoco1Control>("mintchoco1_msg", 1);


  mintchoco1_msgs::Mintchoco1Control mincho;

  printf("%s", msg);
  //printf("\rCurrent: speed %f\tturn %f | Awaiting command...\r", speed, turn);

  while(true){

    // Get the pressed key
    key = getch();

    // If the key corresponds to a key in moveBindings
    if (moveBindings.count(key) == 1)
    {

      // Grab the direction data
      x = moveBindings[key][0];
      y = moveBindings[key][1];
      z = moveBindings[key][2];
      x_t = moveBindings[key][3];
      y_t = moveBindings[key][4];
      z_t = moveBindings[key][5];


      printf("\rLast command: %c   ", key);
    }

    // Otherwise if it corresponds to a key in speedBindings
     else if (gaitControlBindings.count(key) == 1) //gait
    {
      // Grab the speed data
      num = gaitControlBindings[key][0];

      printf("\rGait num %f | Last command: %c   ", num, key);
    }
    
    // Otherwise, set the robot to stop
    else
    {
      x = 0;
      y = 0;
      z = 0;
      x_t = 0;
      y_t = 0;
      z_t = 0;

      // If ctrl-C (^C) was pressed, terminate the program
      if (key == '\x03')
      {
        printf("\n\n I LOVE ROBOT \n\n ");
        break;
      }

      printf("\rInvalid command! %c", key);
    }
    ROS_INFO("%f, %f, %f", x,y,z);
    // Update the Twist message
    mincho.linear={x,y,z};
    mincho.angular={x_t,y_t,z_t};
    mincho.control_num = {num};
    // Publish it and resolve any remaining callbacks
    pub.publish(mincho);
    ros::spinOnce();
  }

  return 0;
}