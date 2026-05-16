#ifndef IMU_H
#define IMU_H

#include <Arduino.h>

void imu_init();
void imu_update();

float imu_getAngleX();
float imu_getAngleY();

#endif