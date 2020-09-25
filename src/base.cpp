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

void grab_in(int speed)
{
  m_group(grab, speed);
}
void grab_out(int speed)
{
  m_group(grab, -speed);
}
void grab_locked()
{
  grab.stop(hold);
}

void low_lift_up(int speed)
{
  m(motorLL, speed);
}
void low_lift_down(int speed)
{
  m(motorLL, -speed);
}
void low_lift_locked()
{
  motorLL.stop(hold);
}

void high_lift_up(int speed)
{
  m(motorHL, speed);
}
void high_lift_down(int speed)
{
  m(motorHL, -speed);
}
void high_lift_locked()
{
  motorHL.stop(hold);
}

void chassis_reset()
{
  chassisLeft.resetRotation();
  chassisRight.resetRotation();
}
void chassis_stop()
{
  chassisLeft.stop(brake);
  chassisRight.stop(brake);
}

void inert_reset()
{
  inert.calibrate();
  while (inert.isCalibrating()){}
}