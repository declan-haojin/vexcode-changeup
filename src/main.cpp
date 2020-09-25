#include "base.h"
#include "manual.h"
#include "auto.h"

using namespace vex;

competition Competition;

void test()
{
  controller_print("The degree is ", (int)INERT_DEG);
  chassis_turn(95);
  controller_print("The degree is ", (int)INERT_DEG);
}

void pre_auton(void) {
  
}

void autonomous(void) {
  
}

void usercontrol(void) {
  
  chassis_brake_mood(false);


  m_brake_mood(motorHL, false);

  while (1) {
    chassis_manual();
    lift_detect();
    // chassis_status();
    // lift_manual();

    // controller1.Screen.clearScreen();
    // controller1.Screen.setCursor(1, 1);
    // controller1.Screen.print("The degree is %f", encoderLeft.position(degrees));
  
    // #ifdef DEVELOPING_MOOD
    if(BUTTON_X) test();
    // #endif

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