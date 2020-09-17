#include "manual.h"
#include "base.h"

void chassis_manual()
{
  m_group(chassisLeft, (CHASSIS_AXIS_X + CHASSIS_AXIS_Y) * SENS);
  m_group(chassisRight, (CHASSIS_AXIS_X - CHASSIS_AXIS_Y) * SENS);
}

void chassis_brake()
{
  
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
    high_lift_in(HIGH_LIFT_V);
  }
  else
  {
    high_lift_locked();
  } 
}