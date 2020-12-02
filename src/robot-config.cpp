#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor motorLF = motor(MOTOR_LF_PORT, MOTOR_LF_TYPE, false);
motor motorLB = motor(MOTOR_LB_PORT, MOTOR_LB_TYPE, false);
motor motorRF = motor(MOTOR_RF_PORT, MOTOR_RF_TYPE, true);
motor motorRB = motor(MOTOR_RB_PORT, MOTOR_RB_TYPE, true);
motor motorLG = motor(MOTOR_LG_PORT, MOTOR_LG_TYPE, false);
motor motorRG = motor(MOTOR_RG_PORT, MOTOR_RG_TYPE, true);
motor motorLL = motor(MOTOR_LL_PORT, MOTOR_LL_TYPE, false);
motor motorHL = motor(MOTOR_HL_PORT, MOTOR_HL_TYPE, true);

motor_group chassisLeft   = motor_group(motorLF, motorLB);
motor_group chassisRight  = motor_group(motorRF, motorRB);
motor_group grab          = motor_group(motorLG, motorRG);

inertial inert    = inertial(INERTIAL_PORT);
digital_in swc    = digital_in(Brain.ThreeWirePort.SWITCH_PORT);
line lit = line(Brain.ThreeWirePort.LIGHT_PORT);