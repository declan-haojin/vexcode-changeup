#include "vision.h"

bool isBlueFound() {
  Vision.takeSnapshot(BLUEBALL);
  if(Vision.objectCount > 0 && Vision.objects[0].width > 150 && Vision.objects[0].height > 100) return true;
  return false;
}

bool isRedFound() {
  Vision.takeSnapshot(REDBALL);
  if(Vision.objectCount > 0 && Vision.objects[0].width > 150 && Vision.objects[0].height > 100) return true;
  return false;
}
