#ifndef MAPPING_H
#define MAPPING_H

#include <Arduino.h>

void joystick_update();
int16_t map_angle_to_joystick(float angle);

#endif