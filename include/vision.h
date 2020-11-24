/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature REDBALL = vex::vision::signature (1, 6459, 10119, 8288, -793, 1, -396, 2.5, 0);
vex::vision::signature BLUEBALL = vex::vision::signature (2, -3387, -2757, -3072, 7671, 12583, 10126, 2.5, 0);
vex::vision::signature SIG_3 = vex::vision::signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision = vex::vision (vex::PORT21, 50, REDBALL, BLUEBALL, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/