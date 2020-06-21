using namespace vex;
using namespace std;

////////////////////////////// MOTOR PORT //////////////////////////////
#define MOTOR_LF_PORT PORT11
#define MOTOR_LB_PORT PORT12
#define MOTOR_RF_PORT PORT9
#define MOTOR_RB_PORT PORT19
#define MOTOR_LG_PORT PORT5
#define MOTOR_RG_PORT PORT6
#define MOTOR_AR_PORT PORT14
#define MOTOR_SU_PORT PORT2

////////////////////////////// SENSOR PORT //////////////////////////////
#define INERTIAL_PORT PORT7

////////////////////////////// RATIO //////////////////////////////
#define MOTOR_LF_TYPE ratio18_1
#define MOTOR_LB_TYPE ratio18_1
#define MOTOR_RF_TYPE ratio18_1
#define MOTOR_RB_TYPE ratio18_1
#define MOTOR_LG_TYPE ratio18_1
#define MOTOR_RG_TYPE ratio18_1
#define MOTOR_AR_TYPE ratio36_1
#define MOTOR_SU_TYPE ratio36_1

////////////////////////////// CONTROL PREFERENCE //////////////////////////////
// #define LEFT_CONTROL

// #ifdef LEFT_CONTROL
// #define AXIS_CONTROL1 controller1.Axis3.value() + controller1.Axis4.value()
// #define AXIS_CONTROL2 controller1.Axis3.value() - controller1.Axis4.value()
// #else
// #define AXIS_CONTROL1 controller1.Axis2.value() + controller1.Axis1.value()
// #define AXIS_CONTROL2 controller1.Axis2.value() - controller1.Axis1.value()
// #endif

////////////////////////////// CONTROLLER SENSIBILITY&THRESHOLD ////////////////////////////// 
#define SENS            1.0
#define AXIS_THRESHOLD  20 

////////////////////////////// MOTOR STANDARD SPEED //////////////////////////////
#define GRAB_V          100
#define ARM_V           100
#define SUPPORT_V       100

////////////////////////////// MOTOR HOLD TYPE //////////////////////////////
#define PRIMITIVE_HOLD_MOOD

////////////////////////////// EXTERN //////////////////////////////
extern brain Brain;
extern controller controller1;
extern motor motorLF;
extern motor motorLB;
extern motor motorRF;
extern motor motorRB;
extern motor motorLG;
extern motor motorRG;
extern motor motorAR;
extern motor motorSU;
extern motor_group chassisLeft;
extern motor_group chassisRight;
extern motor_group grab;
extern inertial inert;
extern encoder encoderLeft;
extern encoder encoderRight;