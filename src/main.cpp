#include "base.h"
#include "manual.h"
#include "auto.h"

using namespace vex;

competition Competition;

void test()
{
  if(BUTTON_X) blue1();
  controller_print("The degree is ", (int)INERT_DEG);
}

void pre_auton(void) {
  all_reset();
}

void autonomous(void) {
  
}

void usercontrol(void) {
  #ifdef COAST_BRAKETYPE
  chassis_brake_mood(false);
  #else
  chassis_brake_mood(true);
  #endif

  while (1) {
    chassis_manual_basic();
    grab_manual_basic();
    // arm_manual_basic();
    // support_manual_basic();

    // controller1.Screen.clearScreen();
    // controller1.Screen.setCursor(1, 1);
    // controller1.Screen.print("The degree is %f", encoderLeft.position(degrees));
  
    #ifdef DEVELOPING_MOOD
    test();
    #endif

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