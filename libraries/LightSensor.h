
#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"

class LightSensor
{
	public:
		LightSensor(uint8_t pinIn);
		bool isTriggered();
		
    private:
        const uint8_t _pinIn;
};

#endif