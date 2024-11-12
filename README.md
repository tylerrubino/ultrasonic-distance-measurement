# Ultrasonic Distance Measurement System with Arduino

## Project Overview

This project involves the design and implementation of an advanced ultrasonic distance measurement system using an Arduino microcontroller and an HC-SR04 ultrasonic sensor. The system measures distances in real-time, processes the data using filtering algorithms, and outputs the results to the Serial Monitor. The project demonstrates proficiency in embedded C++ programming, Object-Oriented Programming (OOP), algorithm development, and hardware-software integration skills highly relevant for embedded systems engineering roles.

[Demonstration](/demonstration.gif)

---

## Features

- **Advanced Embedded C++ Programming**: Utilizes Object-Oriented Programming to encapsulate sensor functionality.
- **Real-Time Distance Measurement**: Accurately measures distanes ranging from 2 cm to 400 cm using ultrasonic sound waves.
- **Median Filtering Algorithm**: Implemented a median filter to improve measurement accuracy by reducing noise and outliers.
- **Error Handling**: Includes robust error handling for sensor timeouts and invalid measurements.
- **Modular and Extensible Code**: Designed with scalability in mind, allowing easy integration of additional sensors or features.
- **Hardware-Software Integration**: Demonstrates seamless integration between hardware components and software logic.

## Hardware Requirements

- **Arduino Uno** (or compatible microcontroller)
- **HC-SR04 Ultrasonic Sensor**
- **Breadboard** and **Jumper Wires**
- **USB Cable** for programming and serial communication

## Software Requirements

- **Arduino IDE** (version 1.8.x or higher)
- **Arduino USB Driver** (if required by your operating system)

## Circuit Diagram

- Coming soon...
- Note: The image above will illustrate the connections between the HC-SR04 ultrasonic sensor and the Arduino Uno

## Implementation Details

### Object-Oriented Design

The project employs Object-Oriented Programming (OOP) principles to create a modular and maintainable codebase. An `UltrasonicSensor` class encapsulates all functionalities related to the sensor, including initialization, distance measurement, filtering, and error handling.

**Benefits of OOP Implementation**:

- **Encapsulation**: Keeps sensor-related code within the class, promoting code reusability.
- **Modularity**: Allows for easy integration of multiple sensors or future enhancements.
- **Abstratction**: Hides low-level hardware interactions from the main program logic.

### Ultrasonic Sensor (HC-SR04)

The HC-SR04 ultrasonic sensor measures distance by emitting an ultrasonic pulse and measuring the time it takes for the echo to return.

**Key Specifications**:

- **Operating Voltage**: 5V DC
- **Measuring Range**: 2 cm to 400 cm
- **Accuracy**: ±3 mm
- **Signal Input Trigger**: 10 μs TTL pulse

### Median Filtering Algorithm

To improve measurement accuracy, a median filter processes multiple distance readings and calculates the median calue. This reduces the impact of transient noise and outliers.

**Algorithm Steps**:

1. **Data Collection**: Collect a predefined number of distance samples.
2. **sorting**: Sort the collected samples in ascending order.
3. **Median Calculation**: Determine the median value based on the number of samples.
   - If the number of samples is odd, select the middle value.
   - If even, calculate the average of the two middle values.

**Benefits**:

- **Noise Reduction**: Filters out anomalous readings.
- **Improved Accuracy**: Provides a more reliable distance measurement.

### Error Handling and Robustness

The system includs error handling mechanisms to manage unexpected scenarios, such as:

- **Sensor Timeout**: Detects when no echo is received within a reasonable time frame.
- **Invalid Measurements**: Handles readings that fall outside the sensor's operational range.

**Implementation**:

- Returns a specific error code or negative value to indicate an error.
- Outputs error messages to the Serial Monitor for debugging purposes.

## Getting Startef

### Hardware Setup

1. **Connect the HC-SR04 Ultrasonic Sensor to the Arduino**:
   - **VCC** (sensor) -> **5V** (Arduino)
   - **GND** (sensor) -> **GND** (Arduino)
   - **Trig** (sensor) -> **Digital Pin 12** (Arduino)
   - **Echo** (sensor) -> **Digital Pn 11** (Arduino)
2. **Ensure Secure Connections**:
   - Use a breadboard and jumper wires for stable connections.
   - Double-check all connections to prevent damages to the components.

### Software Setup

1. **Install the Arduino IDE:**
   - Download and install from the [official website](https://docs.arduino.cc/software/ide/)
2. **Setup Arduino IDE**:
   - Open Arduino IDE
   - Connect your Arduino to your computer via USB
   - Select byour board under **Tools** -> **Board** -> **Arduino IDE**
   - Select the correct port under **Tools** -> **Port**
3. Fork this project, OR:
   - Create the project files
     - `main.ino`
     - `UltrasonicSensor.h`
     - `UltrasonicSensor.cpp`
   - Copy code from respective files in this repository

### Usage

1. **Compile and Upload Code**:
   - Click the **Verify** button to compile the code.
   - Click the **Upload** button to upload the code to your Arduino board.
   - Ensure the correct board and port are selected.
2. **Open Serial Monitor**:
   - Navigate to **Tools** -> **Serial Monitor**
   - Set the baud rate to 9600 baud
3. **Observe Distance Measurement**:
   - The serial monitor will display the filtered distance readings in centimeters.
   - Move an object closer to or further from the sensor to see changes in the measurements.

## Potential Enhancements

- **Temperature Compensation**:
  - Incorporate a temperature sensor to adjust the speed of sound dynamically.
  - Improve measurement accuracy in varying environmental conditions.
- **Integration with Displays**:
  - Add an LCD or OLED display to show distance measurements without a computer.
  - Implement a graphical representation or visual alerts.
- **Data Logging**:
  - Use an SD card module to log distance measurements over time.
  - Enable data analysis and visualization.
- **Wireless Communication**:
  - Implement Bluetooth or Wi-Fi modules to transmit data wirelessly.
  - Create a web interface for remote monitoring.
- **Multi-Sensor Array**:
  - Integrate multiple ultrasonic sensors for broader area scanning.
  - Develop algorithms for object tracking and mapping.
- **Advanced Filtering Techniques**:
  - Explore other filtering algorithms (like Kalman filters or moving averages).
  - Enhance noise reduction and system responsiveness.

## Conclusion

This project showcases a comprehensive application of embedded systems engineering principles, including advanced programming techniques, hardware interfacing, and algorithm development. By implementing Object-Oriented Programming, medial filtering, and robust error handling, the project not only achieves accurate distance measurements but also demonstrates professional coding practices and system design.

## References

- Arduino Official Website: https://www.arduino.cc
- HC-SR04 Ultrasonic Sensor Datasheet: [Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
- Speed of Sound: [Wikipedia](https://en.wikipedia.org/wiki/Speed_of_sound)
- Median Filtering: [Wikipedia](https://en.wikipedia.org/wiki/Median_filter)
- Arduino OOP Guide: [Guide](https://roboticsbackend.com/arduino-object-oriented-programming-oop/)

## Disclaimer

This project is intended for educational purposes and should be used responsibly. Always ensure safety when working with electronic components.
