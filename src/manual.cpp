#include "manual.h"
#include "base.h"

/*

//           \\




\\           //

正方向： 顺时针为各轮正方向

*/

double turnLimit = 1;
void chassis_manual()
{
  // basic movement / shift
  m(motorLF, (AXIS_2 + AXIS_1 + AXIS_4) * SENS);
  m(motorLB, (AXIS_2 - AXIS_1 + AXIS_4) * SENS);
  m(motorRF, (-AXIS_2 + AXIS_1 + AXIS_4) * SENS);
  m(motorRB, (-AXIS_2 - AXIS_1 + AXIS_4) * SENS);
}

void lift_manual()
{
  if(LOWER_KEY_UP)
  {
    grab_in(100);
  }
  else if(LOWER_KEY_DOWN)
  {
    grab_out(100);
  }
  else
  {
    grab_locked();
  }

  if(LOWER_KEY_UP)
  {
    low_lift_up(100);
  }
  else if(LOWER_KEY_DOWN) 
  {
    low_lift_down(100);
  }
  else if (UPPER_KEY_UP) 
  {
    low_lift_up(100);
  }
  else if (UPPER_KEY_DOWN) 
  {
    low_lift_down(100);
  }
  else
  {
    low_lift_locked();
  }

  if(UPPER_KEY_UP)
  {
    high_lift_up(100);
  }
  else if(UPPER_KEY_DOWN)
  {
    high_lift_down(100);
  }
  else if(BUTTON_Y)
  {
    high_lift_down(100);
  }
  else
  {
    high_lift_locked();
  }
}


// void lift_manual()
// {
//   if(LOWER_KEY_UP)
//   {
//     grab_in(GRAB_V);
//   }
//   else if(LOWER_KEY_DOWN) 
//   {
//     grab_out(GRAB_V);
//   }
//   else
//   {
//     grab_locked();
//   } 

//   if(LOWER_KEY_UP)
//   {
//     if(SWITCH)
//     {
//       low_lift_locked();
//     }
//     else if(!UPPER_KEY_DOWN && !UPPER_KEY_UP)
//     {
//       low_lift_locked();
//     }
//     else
//     {
    
//     }
//   }
//   else if(LOWER_KEY_DOWN)
//   {
//     low_lift_down();
//   }
//   else if(UPPER_KEY_UP)
//   {

//   }
//   else if(UPPER_KEY_DOWN)
//   {

//   }
//   else
//   {

//   }

//   if(swc.value() == 0)
//   {
//     low_lift_locked();
//     if(UPPER_KEY_UP)
//     {
//       low_lift_up(100);
//       high_lift_up(100);
//     }
//   }
//   else if(LOWER_KEY_UP)
//   {
//     low_lift_up(LOW_LIFT_V);
//   }
//   else if(LOWER_KEY_DOWN)
//   {
//     low_lift_down(LOW_LIFT_V);
//   }
//   else if(UPPER_KEY_DOWN)
//   {
//     low_lift_up(LOW_LIFT_V);
//   }
//   else if(UPPER_KEY_UP) 
//   {
//     low_lift_down(LOW_LIFT_V);
//   }
//   else
//   {
//     low_lift_locked();
//   } 

//   if(UPPER_KEY_DOWN)
//   {
//     high_lift_down(HIGH_LIFT_V);
//   }
//   else if(UPPER_KEY_UP) 
//   {
//     high_lift_up(HIGH_LIFT_V);
//   }
//   else
//   {
//     high_lift_locked();
//   } 
//   // controller_print("value:", swc.value());
// }

// void lift_detect()
// {
//   if(BUTTON_R1)
//   {
//     if(swc.value() == 0)
//     {
//       grab_in(GRAB_V);
//       low_lift_locked();
//     }
//     else
//     {
//       grab_in(GRAB_V);
//       low_lift_up(LOW_LIFT_V);
//     }
//   }
//   else if(BUTTON_R2)
//   {
//     grab_out(GRAB_V);
//     low_lift_down(LOW_LIFT_V);
//   }
//   else if((!BUTTON_A) && (!BUTTON_B))
//   {
//     low_lift_locked();
//     grab_locked();
//   }
//   else 
//   {
//     grab_locked();
//   }

//   if(BUTTON_B)
//   {
//     low_lift_down(LOW_LIFT_V);
//     high_lift_up(HIGH_LIFT_V);
//   }
//   else if(BUTTON_A)
//   {
//     low_lift_up(LOW_LIFT_V);
//     high_lift_down(HIGH_LIFT_V);
//   }
//   else if((!BUTTON_R1) && (!BUTTON_R2))
//   {
//     high_lift_locked();
//     low_lift_locked();
//   }
//   else
//   {
//     high_lift_locked();
//   }
// }