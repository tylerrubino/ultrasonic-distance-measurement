#include "UltrasonicSensor.h" // include header file

// constructor implementation
UltrasonicSensor::UltrasonicSensor(int trig, int echo) {
  trigPin = trig; // assign trig pin
  echoPin = echo; // assign echo pin
  speedOfSound = 0.0343; // initialize to default speed in cm/μs (0.0343)
}

// initializes sensor by setting pin modes and initial states
void UltrasonicSensor::initialize() {
  pinMode(trigPin, OUTPUT); // set trig pin as an output
  pinMode(echoPin, INPUT); // set echo pin as an input
  digitalWrite(trigPin, LOW); // ensure trig pin is low to start
  delay(100); // allows sensor to settle
}

// allows setting a custom speed of sound (e.g., for temperature adjustments)
void UltrasonicSensor::setSpeedOfSound(float sos) {
  speedOfSound = sos; // update the speed of sound value
}

// measures the distance once and returns the value in centimeters
float UltrasonicSensor::getDistance() {
  long duration; // stores duration of echo pulse
  float distance; // stores calculated distance in centimeters

  // Trigger the sensor and send ultrasonic pulse
  digitalWrite(trigPin, LOW); // ensure trig pin is low
  delayMicroseconds(2); // wait 2 microseconds
  digitalWrite(trigPin, HIGH); // set trig pin to high to send the pulse
  delayMicroseconds(10); // keep it high for 10 microseconds
  digitalWrite(trigPin, LOW); // set trig pin back to low again

  // Read the echo pulse with a timeout
  duration = pulseIn(echoPin, HIGH, 30000); // measures the duration of the high pulse on the echo pin

  if (duration == 0) {
    // Handle timeout
    Serial.println("Error: No echo received");
    return -1.0; // indicate an error
  }

  // Calculate distance
  // distance (cm) = (Duration * Speed of Sound) / 2
  // divided by 2 becayse the pulse travels to the object AND back
  distance = (duration * speedOfSound) / 2.0;

  // Valid distance range
  if (distance < 2 || distance > 400) {
    Serial.println("Error: INvalid distance");
    return -1.0; // indicate an error
  }

  // return the measured and calculated distance in cm
  return distance;
}

// measures multiple distances and returns the median value for better accuracy
float UltrasonicSensor::getFilteredDistance(int samples) {
  // dynamically allocate an array to store distance samples
  float *distances = new float[samples];

  // collect multiple samples
  for (int i = 0; i < samples; i++) {
    distances[i] = getDistance(); // measure distance and store it in the array
    delay(10); // small delay between samples to prevent sensor overload
  }

  // sort the array (distance samples) to find median
  for (int i = 0; i < samples - 1; i++) {
    for (int j = i + 1; j < samples; j++) {
      if (distances[i] > distances[j]) {
        // swap distances[i] and distances[j]
        float temp = distances[j];
        distances[i] = distances[j];
        distances[j] = temp;
      }
    }
  }

  // calculate median
  float median;
  if (samples % 2 == 0) {
    // if even number of samples, avaerage the two middle values
    median = (distances[samples / 2 - 1] + distances[samples / 2]) / 2.0;
  } else {
    // if odd number of samples, take the middle value
    median = distances[samples / 2];
  }

  delete[] distances; // free dynamically allocated memory to prevent memory leaks

  // return median distance in cm
  return median;
}