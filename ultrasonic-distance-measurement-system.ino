#include "UltrasonicSensor.h" // include header file

// create an instance of the UltrasonicSensor class
UltrasonicSensor sensor(12, 11); // trigPin = 12, echoPin = 11

void setup() {
  Serial.begin(9600); // initialie serial communication at 9600 bits per second
  sensor.initialize(); // initialize ultrasonic sensor
}

void loop() {
  // get filtered distance measurement
  float distance = sensor.getFilteredDistance();

  // print the distance to the serial monitor
  Serial.print("Filtered Distance: ");
  Serial.print(distance);
  Serial.print(" cm\n");

  delay(500); // wait for half a second before taking next measurement
}
