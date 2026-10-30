#include <stdio.h>
#include "validation.h"

// Checks whether temperature is between -50 and 60 Celsius.
int validateTemperature(float temperature)
{
    if (temperature >= -50.0f && temperature <= 60.0f)
    {
        return 1;
    }

    return 0;
}

// Checks whether humidity is between 0 and 100 percent.
int validateHumidity(float humidity)
{
    if (humidity >= 0.0f && humidity <= 100.0f)
    {
        return 1;
    }

    return 0;
}

// Checks whether AQI is between 0 and 500.
int validateAQI(int aqi)
{
    if (aqi >= 0 && aqi <= 500)
    {
        return 1;
    }

    return 0;
}

// Checks whether light intensity is non-negative.
int validateLightIntensity(float lightIntensity)
{
    if (lightIntensity >= 0.0f)
    {
        return 1;
    }

    return 0;
}
