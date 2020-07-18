#include "base.h"

void m(motor motorName, int speed, int torq)
{
  motorName.setMaxTorque(torq, pct);
  motorName.spin(fwd, speed, pct);
}

void m_group(motor_group motorGroup, int speed, int torq)
{
  motorGroup.setMaxTorque(torq, pct);
  motorGroup.spin(fwd, speed, pct);
}

void chassis(int left, int right)
{
  m_group(chassisLeft, left);
  m_group(chassisRight, right);
}

void m_brake_mood(motor motorName, bool isBrake)
{
  if(isBrake) motorName.setBrake(brake);
  else motorName.setBrake(coast);
}

void chassis_brake_mood(bool x)
{
  if(x) //BRAKE
  {
    chassisLeft.setStopping(brake);
    chassisRight.setStopping(brake);
  }
  else 
  {
    chassisLeft.setStopping(coast);
    chassisRight.setStopping(coast);
  }
}

void grab_locked()
{
  #ifdef PRIMITIVE_HOLD_MOOD
  m_group(grab, 1, 0);
  #else
  grab.stop(hold);
  #endif
}

void arm_locked()
{
  #ifdef PRIMITIVE_HOLD_MOOD
  m(motorLL, 1, 0);
  #else
  motorLL.stop(hold);
  #endif
}

void support_locked()
{
  #ifdef PRIMITIVE_HOLD_MOOD
  m(motorHL, 1, 0);
  #else
  motorHL.stop(hold);
  #endif
}

void grab_reset()
{
  grab.resetRotation();
}

void chassis_reset()
{
  chassisLeft.resetRotation();
  chassisRight.resetRotation();
}

void arm_reset()
{
  motorLL.resetRotation();
}

void support_reset()
{
  motorHL.resetRotation();
}

void inert_reset()
{
  inert.calibrate();
  while (inert.isCalibrating()) {
    wait(10, msec);
  }
}

void encoder_reset()
{
  encoderLeft.setPosition(0, degrees);
  encoderRight.setPosition(0, degrees);
}
void all_reset()
{
  arm_reset();
  support_reset();
  chassis_reset();
  grab_reset();
  encoder_reset();
}