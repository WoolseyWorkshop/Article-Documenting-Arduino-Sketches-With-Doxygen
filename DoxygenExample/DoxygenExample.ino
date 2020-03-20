/**
 * @file DoxygenExample.ino
 *
 * @mainpage Doxygen Example Project
 *
 * @section description Description
 * An example sketch demonstrating how to use Doxygen style comments for
 * generating source code documentation with Doxygen.
 *
 * @section circuit Circuit
 * - Red LED connected to pin D2.
 * - Momentary push button connected to pin D3.
 *
 * @section libraries Libraries
 * - Arduino_LSM6DS3 (https://github.com/arduino-libraries/Arduino_LSM6DS3)
 *   - Interacts with on-board IMU.
 *
 * @section notes Notes
 * - Comments are Doxygen compatible.
 *
 * @section todo TODO
 * - Don't use Doxygen style formatting inside the body of a function.
 *
 * @section author Author
 * - Created by John Woolsey on 03/12/2020.
 * - Modified by John Woolsey on 03/16/2020.
 *
 * Copyright (c) 2020 Woolsey Workshop.  All rights reserved.
 */


// Libraries
#include <Arduino_LSM6DS3.h>


// Defines
#define DEBUG 1        ///< The mode of operation; 0 = normal, 1 = debug.
#define SAMPLE_RATE 1  ///< The sensor sampling rate in Hz.


// Types
/** The log level enumeration type. */
enum LogLevel {
   Error,    ///< Log errors only.
   Warning,  ///< Log errors and warnings.
   Verbose   ///< Log everything.
};

/** The sensor structure type. */
struct Sensor {
   String name;  ///< The name of the sensor.
   float value;  ///< The value of the sensor.
};


// Pin Mapping
const byte RedLED = 2;  ///< The pin connected to the red LED.
const byte Button = 3;  ///< The pin connected to the momentary push button.


// Global Constants
const float EulersNumber = 2.71828;  ///< Euler's number (e).


// Global Variables
int buttonCount = 0;             ///< The number of times the button was pressed.
unsigned long previousTime = 0;  ///< The last time something happened.


/**
 * The standard Arduino setup function used for setup and configuration tasks.
 */
void setup() {
   // Initialize serial bus (Serial Monitor)
   Serial.begin(9600);
   while (!Serial);  // wait for serial connection

   // Pin configuration
   pinMode(RedLED, OUTPUT);
   pinMode(Button, INPUT_PULLUP);  // utilize microprocessor's internal pull-up resistor

   // Configure the generic device
   configureDevice();
}


/**
 * The standard Arduino loop function used for repeating tasks.
 */
void loop() {
   int value = getDeviceValue(7, 42);
   Serial.print("Device value: "); Serial.println(value);
   delay(1000);  // wait one second
}


/**
 * Configures and initializes some device.
 *
 * Some additional detail about this function.
 */
void configureDevice() {
   // Configure the device
}


/**
 * Retrieves some value from some device.
 *
 * @param someThing   The value of some thing.
 * @param otherThing  The value of other thing.
 *
 * @return  The result of something.
 */
int getDeviceValue(int someThing, int otherThing) {
   // Retrieve the value from the device
   return someThing + otherThing;
}
