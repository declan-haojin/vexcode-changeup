#include "vex.h"

#define currentTurn   inert.rotation(deg)
#define wt(x)         wait(x, sec)
#define stopshooting  grab_locked();low_lift_locked();high_lift_locked()

int sign(double x);

void shift(double speed);

void chassis_run(double dist, double pw, double turnDeg);
void chassis_shift(double dist, double pw, double turnDeg);
void chassis_turn(double target);

void auto_left();
void auto_right();

void right_one();

void switch_accessibility_test();