#include "vex.h"

////////////////////////////// MOTION //////////////////////////////
void m(motor motorName, int speed, int torq = 100);
void m_group(motor_group motorGroup, int speed, int torq = 100);
void m_stop_mood(bool isBrake);
void chassis(int left, int right);

////////////////////////////// LOCK //////////////////////////////
void grab_locked();
void arm_locked();
void support_locked();

////////////////////////////// RESET //////////////////////////////
void grab_reset();
void chassis_reset();
void arm_reset();
void support_reset();
void inert_reset();
void encoder_reset();
void all_reset();

////////////////////////////// OTHERS //////////////////////////////
void controller_print(string s, int x);
void controller_print(string s, double x);

////////////////////////////// MOTOR ROTATION //////////////////////////////
#define LF_DEG fabs(motorLF.rotation(deg))
#define LB_DEG fabs(motorLB.rotation(deg))
#define RF_DEG fabs(motorRF.rotation(deg))
#define RB_DEG fabs(motorRB.rotation(deg))

#define LEFT_DEG fabs(encoderLeft.position(degrees))
#define RIGHT_DEG fabs(encoderRight.position(degrees))

////////////////////////////// SENSOR ROTATION //////////////////////////////
#define INERT_DEG fabs(inert.rotation(degrees))

////////////////////////////// MOTOR SPEED //////////////////////////////
#define LF_V abs(motorLF.velocity(pct))
#define LB_V abs(motorLB.velocity(pct))
#define RF_V abs(motorRF.velocity(pct))
#define RB_V abs(motorRB.velocity(pct))

