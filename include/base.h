#include "vex.h"

////////////////////////////// MOTION //////////////////////////////
void m(motor motorName, int speed, int torq = 100);
void m_group(motor_group motorGroup, int speed, int torq = 100);
void m_brake_mood(motor motorName, bool isBrake);

void chassis(int left, int right);
void chassis_brake_mood(bool x);
void chassis_reset();
void chassis_stop();

void grab_in(int speed);
void grab_out(int speed);
void grab_locked();

void low_lift_up(int speed);
void low_lift_down(int speed);
void low_lift_locked();

void high_lift_up(int speed);
void high_lift_down(int speed);
void high_lift_locked();

void inert_reset();

////////////////////////////// MOTOR ROTATION //////////////////////////////
#define LF_DEG motorLF.rotation(deg)
#define LB_DEG motorLB.rotation(deg)
#define RF_DEG motorRF.rotation(deg)
#define RB_DEG motorRB.rotation(deg)

#define LF_V abs(motorLF.velocity(pct))
#define LB_V abs(motorLB.velocity(pct))
#define RF_V abs(motorRF.velocity(pct))
#define RB_V abs(motorRB.velocity(pct))
#define LL_V abs(motorLL.velocity(pct))
#define LEFT_V ((motorLF.velocity(pct)+motorLB.velocity(pct)*0.5))
#define RIGHT_V ((motorRF.velocity(pct)+motorRB.velocity(pct)*0.5))

////////////////////////////// SENSOR ROTATION //////////////////////////////
#define INERT_DEG fabs(inert.rotation(degrees))
#define SWITCH swc.value() == false 
////////////////////////////// MOTOR SPEED //////////////////////////////


////////////////////////////// PRINT //////////////////////////////
#define controller_print(str, x) controller1.Screen.clearScreen();controller1.Screen.setCursor(1, 1);controller1.Screen.print(str);controller1.Screen.print("%d", x);