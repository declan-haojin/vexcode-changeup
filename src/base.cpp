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
  m(motorAR, 1, 0);
  #else
  motorAR.stop(hold);
  #endif
}

void support_locked()
{
  #ifdef PRIMITIVE_HOLD_MOOD
  m(motorSU, 1, 0);
  #else
  motorSU.stop(hold);
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
  motorAR.resetRotation();
}

void support_reset()
{
  motorSU.resetRotation();
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

// void controller_print(string s, int x)
// {
//   controller1.Screen.clearScreen();
//   controller1.Screen.setCursor(1, 1);
//   controller1.Screen.print(s);
//   controller1.Screen.print("%d",x);
// }

// void controller_print(string s, double x)
// {
//   controller1.Screen.clearScreen();
//   controller1.Screen.setCursor(1, 1);
//   controller1.Screen.print(s);
//   controller1.Screen.print("%f", x);
// }