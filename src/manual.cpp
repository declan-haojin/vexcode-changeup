#include "manual.h"
#include "base.h"

double turnLimit = 1;
void chassis_manual()
{
  m_group(chassisLeft, (CHASSIS_AXIS_X + CHASSIS_AXIS_Y) * SENS * turnLimit);
  m_group(chassisRight, (CHASSIS_AXIS_X - CHASSIS_AXIS_Y) * SENS * turnLimit);
}

//机器姿态判断

void chassis_status()
{
  int status = -1;
  if((LEFT_V * RIGHT_V) < -400)
  {
    // turnLimit = 0.1;
    status = 0;
    // chassis_brake_mood(true);
    controller_print("Turning", 1);
  }
  else if(LEFT_V > 20 && RIGHT_V > 20)
  {
    status = 1;
    // m_brake_mood(motorLF, false);
    // m_brake_mood(motorRF, false);
    // m_brake_mood(motorLB, true);
    // m_brake_mood(motorRB, true);
    controller_print("Go ahead", 1)
  }
  else if(LEFT_V < -20 && RIGHT_V < -20)
  {
    status = 2;
    // m_brake_mood(motorLB, false);
    // m_brake_mood(motorRB, false);
    // m_brake_mood(motorLF, true);
    // m_brake_mood(motorRF, true);
    controller_print("Go backward", 1)
  }
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