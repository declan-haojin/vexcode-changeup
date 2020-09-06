#include "base.h"
#include "auto.h"
#include <algorithm>

double chassis_deg()
{
  #ifdef EXTERNAL_ENCODER_MOOD
  return (LEFT_DEG + RIGHT_DEG) * 0.5;
  #else
  double chassisDeg[4] = {LF_DEG, LB_DEG, RF_DEG, RB_DEG};
  std::sort(chassisDeg, chassisDeg + 1);
  return (chassisDeg[1] + chassisDeg[2]) * 0.5;
  #endif
}

void chassis_stop()
{
  chassisLeft.stop(brake);
  chassisRight.stop(brake);
}

void chassis_turn_inerial_control(int deg)
{
  double KP = 0.57;
  double speed = 0;
  bool direct = (deg > 0);
  deg = abs(deg);
  double err = deg;
  inert_reset();
  chassis_reset();
  
  while(abs(err) > 5)
  {
    err = deg - INERT_DEG;
    speed = KP * err;
    if(direct) chassis(speed, -speed);
    else chassis(-speed, speed);
  }
  chassis_stop();
}

void grab_in()
{
  m_group(grab, GRAB_V);
}

void grab_out()
{
  m_group(grab, -GRAB_V);
}

void grab_stop()
{
  grab.stop(hold);
}

bool enablePID = false;
bool resetPID = false;
double KP = 0.07;
double KD = 0.0;
double error;
double lastError;
double derivative;
double desiredDis;

int PID()
{
  if(resetPID)
  {
    resetPID = false;
    all_reset();
  }
  while(enablePID)
  {
    double averageDis = chassis_deg();
    error = desiredDis - averageDis;
    derivative = error - lastError;
    lastError = error;
    double output = KP * error + KD * derivative;
    
    chassisLeft.spin(fwd, output, volt);
    chassisRight.spin(fwd, output, volt);

    task::sleep(20);
  }
  return 0;
}

void blue1()
{
  enablePID = true;
  task tasks = task(PID);

  resetPID = true;
  desiredDis = 500;
}

void blue2()
{
  
}