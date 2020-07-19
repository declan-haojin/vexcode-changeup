#include "manual.h"
#include "base.h"

void chassis_manual_basic()
{
  m_group(chassisLeft, (AXIS_3+AXIS_4) * SENS);
  m_group(chassisRight, (AXIS_3-AXIS_4) * SENS);
}

void grab_manual_basic()
{
  if(BUTTON_L1)
  {
    m_group(grab, GRAB_V);
  }
  else if(BUTTON_L2)
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
  if(BUTTON_R1)
  {
    m(motorLL, LOW_LIFT_V);
  }
  else if(BUTTON_R2)
  {
    m(motorLL, -LOW_LIFT_V);
  }
  else 
  {
    motorLL.stop(hold);
  }

  if(BUTTON_UP)
  {
    m(motorHL, HIGH_LIFT_V);
  }
  else if(BUTTON_DOWN)
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
