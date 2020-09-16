#include "vex.h"

void chassis_manual_basic();
void grab_manual_basic();
void lift_manual_basic();
// void arm_manual_basic();
// void arm_manual_auto();
// void support_manual_basic();
// void support_manual_auto();

////////////////////////////// CONTROLLER SETTING //////////////////////////////
#define AXIS_1        controller1.Axis1.value()
#define AXIS_2        controller1.Axis2.value()
#define AXIS_3        controller1.Axis3.value()
#define AXIS_4        controller1.Axis4.value()
#define BUTTON_X      controller1.ButtonX.pressing()
#define BUTTON_Y      controller1.ButtonY.pressing()
#define BUTTON_A      controller1.ButtonA.pressing()
#define BUTTON_B      controller1.ButtonB.pressing()
#define BUTTON_UP     controller1.ButtonUp.pressing()
#define BUTTON_DOWN   controller1.ButtonDown.pressing()
#define BUTTON_LEFT   controller1.ButtonLeft.pressing()
#define BUTTON_RIGHT  controller1.ButtonRight.pressing()
#define BUTTON_L1     controller1.ButtonL1.pressing()
#define BUTTON_L2     controller1.ButtonL2.pressing()
#define BUTTON_R1     controller1.ButtonR1.pressing()
#define BUTTON_R2     controller1.ButtonR2.pressing()

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                            CONTROLLER SETTING                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// #define LOW_LIFT_KEY_IN     BUTTON_R1
// #define LOW_LIFT_KEY_OUT    BUTTON_R2
// #define HIGH_LIFT_KEY_IN    BUTTON_UP
// #define HIGH_LIFT_KEY_OUT   BUTTON_DOWN
// #define GRAB_KEY_IN         BUTTON_L1
// #define GRAB_KEY_OUT        BUTTON_L2
#define CHASSIS_AXIS_X      AXIS_3
#define CHASSIS_AXIS_Y      AXIS_4

#define LOWER_KEY_IN        BUTTON_R1
#define LOWER_KEY_OUT       BUTTON_R2
#define UPPER_KEY_IN        BUTTON_B
#define UPPER_KEY_OUT       BUTTON_A