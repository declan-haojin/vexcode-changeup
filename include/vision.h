/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature REDBALL = vex::vision::signature (1, 2213, 5431, 3822, -1433, -657, -1046, 2.5, 0);
vex::vision::signature BLUEBALL = vex::vision::signature (2, -3387, -2757, -3072, 7671, 12583, 10126, 2.5, 0);
vex::vision::signature SIG_3 = vex::vision::signature (3, -297, 565, 134, -3389, -1821, -2605, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, -5765, -4135, -4950, -6103, -3945, -5024, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision = vex::vision (vex::PORT21, 90, REDBALL, BLUEBALL, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/