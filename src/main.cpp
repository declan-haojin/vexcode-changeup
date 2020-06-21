#include "base.h"
#include "manual.h"
#include "auto.h"

using namespace vex;

competition Competition;

void test()
{
  chassis_turn_inerial_control(-37);
  controller_print("The deg is ", INERT_DEG);
}

void pre_auton(void) {
  all_reset();
}

void autonomous(void) {
  
}

void usercontrol(void) {
  while (1) {
    chassis_manual_basic();
    grab_manual_basic();
    arm_manual_basic();
    support_manual_basic();

    controller1.Screen.clearScreen();
    controller1.Screen.setCursor(1, 1);
    controller1.Screen.print("The degree is %f", encoderLeft.position(degrees));
    //test
    if(BUTTON_X) blue1();
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
