#include "base.h"
#include "manual.h"
#include "auto.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  is_chassis_brake_mood(true);
  chassis_reset();
  inert_reset();
}

void autonomous(void) {
  is_chassis_brake_mood(true);
  chassis_reset();
  inert_reset();

  // chassis_run(5000, 70, 0);
  // wait(0.5, sec);
  // chassis_turn(90);
  blue1();
}

void usercontrol(void) {
  is_chassis_brake_mood(true);
  m_brake_mood(motorHL, false);

  while (1) {
    chassis_manual();
    lift_manual();
    wait(20, msec); 
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}