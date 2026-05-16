#include <Arduino.h>

#include "imu.h"
#include "mapping.h"

// =====================================
// Setup
// =====================================
void setup()
{
    Serial.begin(115200);

    imu_init();

    Serial.println("Joystick System Started");
}

// =====================================
// Main Loop
// =====================================
void loop()
{
    imu_update();

    joystick_update();

    delay(10);
}