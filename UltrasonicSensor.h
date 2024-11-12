#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

// include core arduino library
#include <Arduino.h>

// class definition for the UltrasonicSensor
class UltrasonicSensor {
  private:
    int trigPin; // pin # connected to the TRIG pin of the sensor
    int echoPin; // pin # connected to the ECHO pin of the sensor
    float speedOfSound; // speed of sound in cm/μs

  public:
    // constructor to initialize the sensor with specified trig and echo pins
    UltrasonicSensor(int trig, int echo);

    // initializes sensor by setting up the pins
    void initialize();

    // sets a custom speed of sound (useful for temperature compensation)
    void setSpeedOfSound(float sos);

    // measures and returns the distance in centimeters
    float getDistance();

    // measures multiple distances and returns the median value for filtering
    float getFilteredDistance(int samples = 5);
};

#endif 