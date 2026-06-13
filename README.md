# CAN Bus Communication Using Arduino and MCP2515

## Overview

This project demonstrates CAN (Controller Area Network) communication between two Arduino UNO boards using MCP2515 CAN modules.

The transmitter reads data from a potentiometer and an ultrasonic sensor and sends it over the CAN bus. The receiver processes the received data, controls LED blinking speed, activates a warning LED for obstacle detection, and displays status information on a 16×2 LCD.

## Components Used

- Arduino UNO ×2
- MCP2515 CAN Module ×2
- Potentiometer
- HC-SR04 Ultrasonic Sensor
- 16×2 I2C LCD
- LEDs
- Breadboard
- Jumper Wires

## Features

- CAN Bus communication
- Potentiometer-based speed control
- Ultrasonic obstacle detection
- LCD status display
- LED indication
- Real-time data transmission

## Technologies

- Arduino IDE
- SPI Protocol
- MCP2515 Library
- CAN Bus Protocol

## Future Scope

- STM32 integration
- Automotive safety applications
- Autonomous vehicle communication
- Sensor networking

## Author

Om Sapdhare
