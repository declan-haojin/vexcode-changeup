#include "vex.h"

#define currentTurn   inert.rotation(deg)
#define wt(x)         wait(x, sec)
#define stopshooting  grab_locked();low_lift_locked();high_lift_locked()

int sign(double x);

void shift(double speed);

void chassis_run(double dist, double pw, double turnDeg);
void chassis_shift(double dist, double pw, double turnDeg);
void chassis_turn(double target);

void blue_close_basic();
void blue_close_side();
void blue_close_shift();

void blue_far_basic();

void red_close_basic();
void red_close_side();
void red_close_shift();

void test();