#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor motorLF = motor(MOTOR_LF_PORT, ratio18_1, false);
motor motorLB = motor(MOTOR_LB_PORT, ratio18_1, false);
motor motorRF = motor(MOTOR_RF_PORT, ratio18_1, true);
motor motorRB = motor(MOTOR_RB_PORT, ratio18_1, true);
motor motorLG = motor(MOTOR_LG_PORT, ratio18_1, false);
motor motorRG = motor(MOTOR_RG_PORT, ratio18_1, true);
motor motorAR = motor(MOTOR_AR_PORT, ratio36_1, false);
motor motorSU = motor(MOTOR_SU_PORT, ratio36_1, true);

motor_group chassisLeft = motor_group(motorLF, motorLB);
motor_group chassisRight = motor_group(motorRF, motorRB);
motor_group grab = motor_group(motorLG, motorRG);

inertial inert = inertial(INERTIAL_PORT);

encoder encoderLeft = encoder(Brain.ThreeWirePort.A);
encoder encoderRight = encoder(Brain.ThreeWirePort.C);