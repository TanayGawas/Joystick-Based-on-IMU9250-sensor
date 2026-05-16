#include "usb_output.h"

#include <Arduino.h>

// =====================================
// USB Output Send
// =====================================
void usb_output_send(int16_t xAxis, int16_t yAxis)
{
    Serial.print("Joystick X: ");
    Serial.print(xAxis);

    Serial.print(" | Y: ");
    Serial.println(yAxis);
}