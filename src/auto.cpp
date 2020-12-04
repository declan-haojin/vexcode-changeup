#include "base.h"
#include "auto.h"
#include <algorithm>

int ballCount = 0;
double t0 = 0;

int sign(double x)
{
  if(x > 0) return 1;
  if(x < 0) return -1;
  return 0;
}

void shift(double front, double back)
{
  m(motorLF, front);
  m(motorLB, -back);
  m(motorRF, -front);
  m(motorRB, back);
}

void chassis_run(double dist, double pw, double turnDeg)
{
  // double gyro_kp = 1.5;
  // double gyro_kd = 1;

  // double move_kp = 0.49;
  // double move_kd = 3.5;

  double gyro_kp = 1.5;
  double gyro_kd = 1.01;

  double move_kp = 0.49;
  double move_kd = 3.47;

  double currentDist = 0;
  double diffTurn;
  double diffDist;
  double turnPower;
  double movePower;
  double gyroLastError;
  double moveLastError;
  
  double moveError = fabs(dist) - fabs(currentDist);
  double gyroError = turnDeg - currentTurn;

  chassis_reset();
  
  gyroLastError = gyroError;
  moveLastError = moveError;

  while(true)
  {
    currentDist = (LF_DEG + LB_DEG + RF_DEG + RB_DEG) * 0.25;
    
    moveError = fabs(dist) - fabs(currentDist);
    gyroError = turnDeg - currentTurn;

    diffDist = moveError - moveLastError;
    diffTurn = gyroError - gyroLastError;

    moveLastError = moveError;
    gyroLastError = gyroError;

    movePower = move_kp*moveError + move_kd*diffDist;
    turnPower = gyro_kp*gyroError + gyro_kd*diffTurn;

    if(moveError < 3 && fabs(diffDist) < 0.1) break;

    if(dist > 0)
    {
      if(currentDist > 0.1*fabs(dist)) //查的距离还比较远
      {
        chassis(pw + turnPower, pw-turnPower);
      }
      else
      {
        chassis(pw*0.7 + turnPower, pw*0.7-turnPower);
      }
    }
    else
    {
      if(currentDist > 0.1*fabs(dist)) //查的距离还比较远
      {
        chassis(-pw + turnPower, -pw-turnPower);
      }
      else
      {
        chassis(-pw*0.7 + turnPower, -pw*0.7-turnPower);
      }
    }
    wait(1, msec);
  }
  chassis(0, 0);
}

void chassis_shift(double dist, double pw, double turnDeg)
{
  // double gyro_kp = 1.5;
  // double gyro_kd = 1;

  // double move_kp = 0.49;
  // double move_kd = 3.5;

  double gyro_kp = 1.7;
  double gyro_kd = 1.02;

  double move_kp = 0.49;
  double move_kd = 3.5;

  double currentDist = 0;
  double diffTurn;
  double diffDist;
  double turnPower;
  double movePower;
  double gyroLastError;
  double moveLastError;
  
  double moveError = fabs(dist) - fabs(currentDist);
  double gyroError = turnDeg - currentTurn;

  chassis_reset();
  
  gyroLastError = gyroError;
  moveLastError = moveError;

  while(true)
  {
    currentDist = (fabs(LF_DEG) + fabs(LB_DEG) + fabs(RF_DEG) + fabs(RB_DEG)) * 0.25;
    
    moveError = fabs(dist) - fabs(currentDist);
    gyroError = turnDeg - currentTurn;

    diffDist = moveError - moveLastError;
    diffTurn = gyroError - gyroLastError;

    moveLastError = moveError;
    gyroLastError = gyroError;

    movePower = move_kp*moveError + move_kd*diffDist;
    turnPower = gyro_kp*gyroError + gyro_kd*diffTurn;

    if(moveError < 3 && fabs(diffDist) < 0.1) break;

    if(dist > 0)
    {
      if(currentDist > 0.1*fabs(dist)) //查的距离还比较远
      {
        shift(pw + turnPower, pw-turnPower);
      }
      else
      {
        shift(pw*0.7 + turnPower, pw*0.7-turnPower);
      }
    }
    else
    {
      if(currentDist > 0.1*fabs(dist)) //查的距离还比较远
      {
        shift(-pw + turnPower, -pw-turnPower);
      }
      else
      {
        shift(-pw*0.7 + turnPower, -pw*0.7-turnPower);
      }
    }
    wait(1, msec);
  }
  shift(0, 0);
}

void chassis_turn(double target)
{
  double kp = 1.7;
  double ki = 0.01;//30;
  double kd = 2;//20;

  int timeUsed = 0;

  double iRange = 1.0;
  double iStart = 60;
  double distTorl = 0.1;
  double errorTorl = 1;
  double lim = 100;
  double error = target - currentTurn; // 337-1.78
  double lastError;
  double diffError = 0;
  double i = 0;

  bool isFinished;
  double timeTorl = fabs(error) < 20 ? 700 : fabs(error) * 27;
  double pw;

  lastError = error;
  isFinished = (error == 0);

  while(!isFinished)
  {
    timeUsed += 10;
    error = target - currentTurn;

    diffError = error - lastError;
    lastError = error;

    if((fabs(error) < errorTorl && fabs(diffError) <= distTorl) || timeUsed > timeTorl) isFinished = true;
    if(fabs(i) < iRange && fabs(error) < iStart)
    {
      i += sign(error) * 0.01;
    }
    if(error * lastError <= 0)
    {
      i = 0;
    }

    pw = kp * error + kd * diffError + ki * i;
    pw = fabs(pw) > lim ? sign(pw) * lim : pw;

    chassis(pw, -pw);

    wait(10, msec);
  }

  chassis(0, 0);
}

bool isBallDetected()
{
  return swc.value() == 0 ? true : false;
  // return lit.reflectivity() > 17 ? true : false;
}

int CountingCallback()
{
  ballCount = 0;
  bool isFirstBallDetected = false;
  bool flag = false;
  double lastTime = 0;

  while(true)
  {
    if(isBallDetected() == true && flag == false)
    {
      double currentTime = Brain.timer(sec);
      if(ballCount == 0)
      {
        isFirstBallDetected = true;
        lastTime = currentTime;
      } 
      else if(currentTime - lastTime < 0.37) continue;
      lastTime = currentTime;
      ballCount++;
      flag = true;
    }
    else if(isBallDetected() == false && flag == true)
    {
      flag = false;
    }
    wait(30, msec);
  }
  return 0;
}

int BallOutCallback()
{
  wt(1.17);
  low_lift_down(80);
  grab_out(80);
  high_lift_down(80);
  wt(1.77);
  stopshooting;
  return 0;
}

int DisplayCallback()
{
  controller1.Screen.clearScreen();

  controller1.Screen.setCursor(controller1.Screen.row(), 1);
  controller1.Screen.setCursor(1, 1);
  controller1.Screen.print("ballCount: %d", ballCount);
  
  controller1.Screen.setCursor(controller1.Screen.row(), 3);
  controller1.Screen.setCursor(3, 1);
  controller1.Screen.print("rotation:  %f", currentTurn);
  return 0;
}

void auto_left()
{
  #ifdef DEV
  task Display = task(DisplayCallback);
  #endif

  high_lift_up(70);
  grab_out(100);
  low_lift_up(70);
  wt(0.5);
  grab_in(70);
  wt(0.27);

  chassis_run(3377, 77.7, 0);
  wt(0.27);
  high_lift_locked();

  chassis_turn(271.7-360);
  wt(0.27);

  task Counting = task(CountingCallback);

  chassis_run(3777, 77.7, 271.7-360);

  chassis(77.7, 77.7);
  wt(0.17);

  t0 = Brain.timer(sec);
  while(ballCount < 3 && Brain.timer(sec)-t0 < 4)
  {
    high_lift_up(70);
    low_lift_up(80);
    grab_in(90);
  }

  stopshooting;

  task BallOut = task(BallOutCallback);
  wt(0.1);

  chassis_run(-2977, 77.7, 271.7-360);
  BallOut.stop();
  wt(0.27);
  stopshooting;

  chassis_turn(45.07);
  wt(0.27);

  grab_in(100);
  low_lift_up(50);

  chassis_run(2217, 57.7, 48.7);

  t0 = Brain.timer(sec);
  while(ballCount < 4 && Brain.timer(sec)-t0 < 1){}

  wt(0.47);
  grab_out(100);

  chassis_shift(2077, 37.7, 48.7);
  // stopshooting;
}

void auto_right()
{
  // task FirstBallDetected = task(FirstBallDetectedCallback);
  grab_out(100);
  low_lift_up(100);
  high_lift_up(100);
  wt(0.5);
  grab_in(70);
  wt(0.27);

  chassis_run(2877, 77.7, 0);
  wt(0.27);

  chassis_turn(93.7);
  wt(0.27);

  task Counting = task(CountingCallback);

  chassis_run(4327, 77.7, 93.7);
  wt(0.27);

  t0 = Brain.timer(sec);
  while(ballCount < 3 && Brain.timer(sec)-t0 < 4)
  {
    high_lift_up(100);
    low_lift_up(70);
    grab_in(60);
  }

  stopshooting;
  
  task BallOut = task(BallOutCallback);
  wt(0.1);

  chassis_run(-2977, 77.7, 93.7);
  BallOut.stop();
  wt(0.27);

  chassis_turn(317.1-360);
  wt(0.27);

  chassis_shift(-4377, 87.7, 317.7-360);
  wt(0.27);

  chassis_run(1777, 77.7, 309.7-360);
  wt(0.27);

  stopshooting;
  grab_out(100);

  chassis_shift(2000, 37.7, 317.7-360);


  stopshooting;
}

void switch_accessibility_test()
{
  task Counting = task(CountingCallback);
  
  while(true)
  {
    if(controller1.ButtonA.pressing())
    {
      low_lift_up(100);
      high_lift_up(100);
      grab_in(100);
    }
    else
    {
      stopshooting;
    }

    controller1.Screen.clearScreen();
    controller1.Screen.setCursor(controller1.Screen.row(), 1);
    controller1.Screen.setCursor(1, 1);
    controller1.Screen.print("ballCount: %d", ballCount);
    wait(20, msec);
  }
}