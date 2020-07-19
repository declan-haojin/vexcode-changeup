#include "manual.h"
#include "base.h"

void chassis_manual_basic()
{
  m_group(chassisLeft, (CHASSIS_AXIS_X + CHASSIS_AXIS_Y) * SENS);
  m_group(chassisRight, (CHASSIS_AXIS_X - CHASSIS_AXIS_Y) * SENS);
}

void grab_manual_basic()
{
  if(GRAB_KEY_IN)
  {
    m_group(grab, GRAB_V);
  }
  else if(GRAB_KEY_OUT)
  {
    m_group(grab, -GRAB_V);
  }
  else 
  {
    grab_locked();
  }
}

void lift_manual_basic()
{
  if(LOW_LIFT_KEY_IN)
  {
    m(motorLL, LOW_LIFT_V);
  }
  else if(LOW_LIFT_KEY_OUT)
  {
    m(motorLL, -LOW_LIFT_V);
  }
  else 
  {
    motorLL.stop(hold);
  }

  if(HIGH_LIFT_KEY_IN)
  {
    m(motorHL, HIGH_LIFT_V);
  }
  else if(HIGH_LIFT_KEY_OUT)
  {
    m(motorHL, -HIGH_LIFT_V);
  }
  else 
  {
    motorHL.stop(hold);
  }
}

// void arm_manual_basic()
// {
//   if(BUTTON_R1)
//   {
//     m(motorLL, LIFT_V);
//   }
//   else if(BUTTON_R2)
//   {
//     m(motorLL, -LIFT_V);
//   }
//   else
//   {
//     arm_locked();
//   }
// }

// void support_manual_basic()
// {
//   if(abs(AXIS_2) > SUPPORT_V)
//   {
//     m(motorHL, AXIS_2);
//   }
//   else 
//   {
//     support_locked();
//   }
// }
