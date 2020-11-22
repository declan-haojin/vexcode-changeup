using namespace vex;
using namespace std;
 
#define MOTOR_LF_PORT                   PORT13
#define MOTOR_LB_PORT                   PORT11
#define MOTOR_RF_PORT                   PORT14
#define MOTOR_RB_PORT                   PORT12
#define MOTOR_LG_PORT                   PORT1
#define MOTOR_RG_PORT                   PORT2
#define MOTOR_LL_PORT                   PORT3
#define MOTOR_HL_PORT                   PORT4

#define INERTIAL_PORT                   PORT21
#define SWITCH_PORT                     A
#define ENCODER_LEFT_PORT               B
#define ENCODER_RIGHT_PORT              C

#define MOTOR_LF_TYPE                   ratio6_1
#define MOTOR_LB_TYPE                   ratio6_1
#define MOTOR_RF_TYPE                   ratio6_1
#define MOTOR_RB_TYPE                   ratio6_1
#define MOTOR_LG_TYPE                   ratio18_1
#define MOTOR_RG_TYPE                   ratio18_1
#define MOTOR_LL_TYPE                   ratio36_1
#define MOTOR_HL_TYPE                   ratio36_1

#define SENS                            0.5
#define AXIS_THRESHOLD                  20

#define GRAB_V                          100
#define LOW_LIFT_V                      100
#define HIGH_LIFT_V                     100

#define DEVELOPING_MOOD
#define PRIMITIVE_HOLD_MOOD
#define COAST_BRAKETYPE
#define EXTERNAL_ENCODER_MOOD

extern brain Brain;
extern controller controller1;
extern motor motorLF;
extern motor motorLB;
extern motor motorRF;
extern motor motorRB;
extern motor motorLG;
extern motor motorRG;
extern motor motorLL;
extern motor motorHL;
extern motor_group chassisLeft;
extern motor_group chassisRight;
extern motor_group grab;
extern inertial inert;
extern digital_in swc;
extern encoder encoderLeft;
extern encoder encoderRight;