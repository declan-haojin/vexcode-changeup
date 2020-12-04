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
  // test();
  // chassis_shift(2000, 37.7, 0);
  inert_reset();
  // chassis_run(5000, 77.7, 0);
  // wait(0.5, sec);
  // chassis_turn(90);
  // blue1();
  // auto_right();
  auto_left();
  // red_far_basic();
}

void usercontrol(void) {
  // is_chassis_brake_mood(true);
  // is_m_brake_mood(motorHL, false);
  // test();
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