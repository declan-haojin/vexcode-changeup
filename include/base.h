#include "vex.h"

////////////////////////////// MOTION //////////////////////////////
void m(motor motorName, double speed, double torq = 100);
void m_group(motor_group motorGroup, double speed, double torq = 100);
void m_brake_mood(motor motorName, bool isBrake);

void chassis(double left, double right);
void is_chassis_brake_mood(bool x);
void chassis_reset();
void chassis_stop();

void grab_in(double speed);
void grab_out(double speed);
void grab_locked();

void low_lift_up(double speed);
void low_lift_down(double speed);
void low_lift_locked();

void high_lift_up(double speed);
void high_lift_down(double speed);
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

bool isBlueFound();
bool isRedFound();