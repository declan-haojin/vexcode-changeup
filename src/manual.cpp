#include "manual.h"
#include "base.h"

double turnLimit = 1;
void chassis_manual()
{
  m_group(chassisLeft, (CHASSIS_AXIS_X + CHASSIS_AXIS_Y) * SENS * turnLimit);
  m_group(chassisRight, (CHASSIS_AXIS_X - CHASSIS_AXIS_Y) * SENS * turnLimit);
}

double tim = Brain.Timer.time(sec);
int lastV =  LEFT_V;

void chassis_brake()
{
  // double period = Brain.Timer.time(sec) - tim;
  // if(period > 0.5)
  // {
  //   tim = Brain.Timer.time(sec);
  //   double tempAc = (LEFT_V - lastV) / period;
  //   lastV = LEFT_V;
  //   if(tempAc > )   
  // }
  
}
void chassis_turn()
{
  // if((LEFT_V * RIGHT_V) < -400)
  // {
  //   turnLimit = 0.1;
  //   // controller_print("Turn mood trigged", 1);
  // }
  // else turnLimit = 1;
}

void lift_manual()
{
  if(LOWER_KEY_IN)
  {
    grab_in(GRAB_V);
  }
  else if(LOWER_KEY_OUT) 
  {
    grab_out(GRAB_V);
  }
  else
  {
    grab_locked();
  } 

  if(LOWER_KEY_IN)
  {
    low_lift_in(LOW_LIFT_V);
  }
  else if(LOWER_KEY_OUT)
  {
    low_lift_out(LOW_LIFT_V);
  }
  else if(UPPER_KEY_IN)
  {
    low_lift_in(LOW_LIFT_V);
  }
  else if(UPPER_KEY_OUT) 
  {
    low_lift_out(LOW_LIFT_V);
  }
  else
  {
    low_lift_locked();
  } 

  if(UPPER_KEY_IN)
  {
    high_lift_in(HIGH_LIFT_V);
  }
  else if(UPPER_KEY_OUT) 
  {
    high_lift_out(HIGH_LIFT_V);
  }
  else
  {
    high_lift_locked();
  } 


  controller_print("value:", LL_V);
}