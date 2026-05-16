#include "imu.h"
#include "config.h"
#include "filter.h"

#include <SPI.h>

// =====================================
// Internal Variables
// =====================================
static float angleX = 0.0f;
static float angleY = 0.0f;

static float filteredGyroX = 0.0f;
static float filteredGyroY = 0.0f;

// =====================================
// Dummy SPI Read Function
// Replace later with real ICM20948 code
// =====================================
int16_t spi_read_gyro_axis(uint8_t reg)
{
    digitalWrite(IMU_CS_PIN, LOW);

    SPI.transfer(reg | 0x80);

    uint8_t highByte = SPI.transfer(0x00);
    uint8_t lowByte  = SPI.transfer(0x00);

    digitalWrite(IMU_CS_PIN, HIGH);

    return (highByte << 8) | lowByte;
}

// =====================================
// IMU Initialization
// =====================================
void imu_init()
{
    pinMode(IMU_CS_PIN, OUTPUT);
    digitalWrite(IMU_CS_PIN, HIGH);

    SPI.begin();

    Serial.println("IMU Initialized");
}

// =====================================
// Update Sensor Data
// =====================================
void imu_update()
{
    // ---------------------------------
    // Dummy registers for testing
    // Replace later with actual regs
    // ---------------------------------
    int16_t rawGyroX = spi_read_gyro_axis(0x33);
    int16_t rawGyroY = spi_read_gyro_axis(0x35);

    // Convert raw values
    float gyroX = rawGyroX / GYRO_SENSITIVITY;
    float gyroY = rawGyroY / GYRO_SENSITIVITY;

    // Low pass filtering
    filteredGyroX = lowPassFilter(filteredGyroX, gyroX, 0.2f);
    filteredGyroY = lowPassFilter(filteredGyroY, gyroY, 0.2f);

    // Integrate angle
    angleX += filteredGyroX * LOOP_DT;
    angleY += filteredGyroY * LOOP_DT;
}

// =====================================
// Getter Functions
// =====================================
float imu_getAngleX()
{
    return angleX;
}

float imu_getAngleY()
{
    return angleY;
}