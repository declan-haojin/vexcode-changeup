using namespace vex;
using namespace std;

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                      DEVELOPING / COMPETITION MOOD                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define DEVELOPING_MOOD

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                               MOTOR PORT                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define MOTOR_LF_PORT PORT11
#define MOTOR_LB_PORT PORT12
#define MOTOR_RF_PORT PORT9
#define MOTOR_RB_PORT PORT19
#define MOTOR_LG_PORT PORT5
#define MOTOR_RG_PORT PORT6
#define MOTOR_AR_PORT PORT14
#define MOTOR_SU_PORT PORT2

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                               SENSOR PORT                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define INERTIAL_PORT       PORT7
#define ENCODER_LEFT_PORT   A
#define ENCODER_RIGHT_PORT  C

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                               MOTOR RATIO                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define MOTOR_LF_TYPE ratio18_1
#define MOTOR_LB_TYPE ratio18_1
#define MOTOR_RF_TYPE ratio18_1
#define MOTOR_RB_TYPE ratio18_1
#define MOTOR_LG_TYPE ratio18_1
#define MOTOR_RG_TYPE ratio18_1
#define MOTOR_AR_TYPE ratio36_1
#define MOTOR_SU_TYPE ratio36_1

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                    CONTROLLER SENSIBILITY & THRESHOLD                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define SENS            1.0
#define AXIS_THRESHOLD  20 

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                            MOTOR STANDARD SPEED                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define GRAB_V          100
#define ARM_V           100
#define SUPPORT_V       100

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              MOTOR HOLD MOOD                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define PRIMITIVE_HOLD_MOOD

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                               ENCODER MOOD                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#define EXTERNAL_ENCODER_MOOD



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