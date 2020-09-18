#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor motorLF = motor(MOTOR_LF_PORT, ratio18_1, true);
motor motorLB = motor(MOTOR_LB_PORT, ratio18_1, false);
motor motorRF = motor(MOTOR_RF_PORT, ratio18_1, false);
motor motorRB = motor(MOTOR_RB_PORT, ratio18_1, true);
motor motorLG = motor(MOTOR_LG_PORT, ratio18_1, false);
motor motorRG = motor(MOTOR_RG_PORT, ratio18_1, true);
motor motorLL = motor(MOTOR_LL_PORT, ratio36_1, true);
motor motorHL = motor(MOTOR_HL_PORT, ratio36_1, false);

motor_group chassisLeft = motor_group(motorLF, motorLB);
motor_group chassisRight = motor_group(motorRF, motorRB);
motor_group grab = motor_group(motorLG, motorRG);

inertial inert = inertial(INERTIAL_PORT);

encoder encoderLeft = encoder(Brain.ThreeWirePort.ENCODER_LEFT_PORT);
encoder encoderRight = encoder(Brain.ThreeWirePort.ENCODER_RIGHT_PORT);