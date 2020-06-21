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

void arm_manual_basic()
{
  if(BUTTON_R1)
  {
    m(motorAR, ARM_V);
  }
  else if(BUTTON_R2)
  {
    m(motorAR, -ARM_V);
  }
  else
  {
    arm_locked();
  }
}

void support_manual_basic()
{
  if(abs(AXIS_2) > SUPPORT_V)
  {
    m(motorSU, AXIS_2);
  }
  else 
  {
    support_locked();
  }
}
