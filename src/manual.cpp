#include "manual.h"
#include "base.h"

/*

//           \\




\\           //

正方向： 顺时针为各轮正方向

*/

double turnLimit = 1;
void chassis_manual()
{
  double rotationValue = AXIS_4;
  // basic movement / shift
  m(motorLF, (AXIS_2 + AXIS_1) * SENS + rotationValue);
  m(motorLB, (AXIS_2 - AXIS_1) * SENS + rotationValue);
  m(motorRF, (-AXIS_2 + AXIS_1) * SENS + rotationValue);
  m(motorRB, (-AXIS_2 - AXIS_1) * SENS + rotationValue);
}

// int status = 0; // 0stop  1in   2out  3 shoot
// #define STOP    0
// #define IN      1
// #define OUT     2
// #define SHOOT   3

void lift_manual()
{
  if(LOWER_KEY_UP)
  {
    grab_in(100);
  }
  else if(LOWER_KEY_DOWN)
  {
    grab_out(100);
  }
  else
  {
    grab_locked();
  }
  
  if((BUTTON_L1 && BUTTON_L2) || BUTTON_Y)
  {
    low_lift_up(70);
  }
  else if(LOWER_KEY_UP)
  {
    low_lift_up(100);
  }
  else if(LOWER_KEY_DOWN) 
  {
    low_lift_down(100);
  }
  else if (UPPER_KEY_UP) 
  {
    low_lift_up(100);
  }
  else if (UPPER_KEY_DOWN) 
  {
    low_lift_down(100);
  }
  else
  {
    low_lift_locked();
  }

  if((BUTTON_L1 && BUTTON_L2) || BUTTON_Y)
  {
    high_lift_down(100);
  }
  else if(UPPER_KEY_UP)
  {
    high_lift_up(100);
  }
  else if(UPPER_KEY_DOWN)
  {
    high_lift_down(100);
  }
  else
  {
    high_lift_locked();
  }
}