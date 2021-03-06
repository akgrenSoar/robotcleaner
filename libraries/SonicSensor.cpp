
#include "Arduino.h"
#include "SonicSensor.h"

SonicSensor::SonicSensor(uint8_t trigPin, uint8_t echoPin)
:	_trigPin(trigPin),
	_echoPin(echoPin)
{
	pinMode(_trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(_echoPin, INPUT); // Sets the echoPin as an Input
}

/**
 * Read sensor distance in centimeters.
 * This method uses a less accurate approximation of the distance.
 * 
 * @returns Sensor distance in centimeters.
 */
unsigned long SonicSensor::getDistance()
{
	digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    unsigned long duration = pulseIn(_echoPin, HIGH);
    // Approximating the distance
	// For more accurate distance calculation, use duration / 58.2
    unsigned long distance = duration >> 6;
  
    return distance;
}
