# 🎮 IMU-Based Joystick using Gyroscope (6-axis fusion)

## 📌 Overview
This project implements a **gesture-based joystick system** using an **IMU (Inertial Measurement Unit)** sensor.  
Instead of a traditional mechanical joystick, this system uses **gyroscope and accelerometer data** to detect motion and convert it into control signals.

The project demonstrates real-time motion tracking and provides a smooth and responsive control interface for various applications.

---

## 🚀 Features
- Real-time motion sensing using IMU  
- Gyroscope + Accelerometer integration  
- Smooth and responsive joystick output  
- Noise filtering and calibration  
- Multi-axis control (X, Y, optional Z)  
- Modular and scalable code structure  

---

## 🛠️ Hardware Requirements
- Micro controller (Teensy / Arduino)
- IMU Sensor (e.g., MPU6050 / MPU9250)
- USB Cable
- Breadboard & Connecting Wires

---

## 💻 Software Requirements
- PlatformIO / Arduino IDE  
- C++ (Embedded Programming)  
- Serial Monitor for debugging  

---

## 📂 Project Structure

include/<br>
├── config.h # Centralized configuration and system parameters management<br>
├── filter.h # Signal processing interfaces for noise reduction and data smoothing<br>
├── imu.h # Abstraction layer for IMU sensor data acquisition and handling<br>
├── joystick.h # Motion-to-input mapping logic for joystick axis generation<br>
└── usb_output.h # Interface for USB communication and HID data transmission<br>


src/<br>
├── filter.cpp # Implementation of filtering algorithms (e.g., smoothing, stabilization)<br>
├── imu.cpp # Real-time IMU data acquisition and preprocessing<br>
├── joystick.cpp # Conversion of processed sensor data into joystick control signals<br>
├── main.cpp # Application entry point and system integration logic<br>
└── usb_output.cpp # USB data handling and host communication implementation<br>



---

## ⚙️ Working Principle
1. IMU sensor reads orientation and motion data  
2. Raw data is processed and filtered  
3. Motion is mapped to joystick axis values  
4. Output signals are generated in real-time  

---

## 📊 Applications
- Gaming controllers  
- Robotics control  
- VR/AR input systems  
- Assistive technology 
- Drone Controllers 

---

