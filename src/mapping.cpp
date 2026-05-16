#include "mapping.h"
#include "imu.h"
#include "config.h"
#include "usb_output.h"

static int16_t joystickX = 0;
static int16_t joystickY = 0;

// =====================================
// Map angle to joystick range
// =====================================
int16_t map_angle_to_joystick(float angle)
{
    // Clamp angle
    if (angle > MAX_ANGLE)
        angle = MAX_ANGLE;

    if (angle < -MAX_ANGLE)
        angle = -MAX_ANGLE;

    return (int16_t)((angle / MAX_ANGLE) * JOYSTICK_MAX);
}

// =====================================
// Main joystick logic
// =====================================
void joystick_update()
{
    float angleX = imu_getAngleX();
    float angleY = imu_getAngleY();

    joystickX = map_angle_to_joystick(angleX);
    joystickY = map_angle_to_joystick(angleY);

    usb_output_send(joystickX, joystickY);
}